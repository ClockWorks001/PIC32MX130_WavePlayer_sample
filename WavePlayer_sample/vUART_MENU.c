/*******************************************************************************
 *	UART Moniter Menu
 *	author  :hiroshi murakami
 *	created :20161225
 *	modified:-
 ******************************************************************************/
#define _vUART_MENU_C

#include "mcc_generated_files/mcc.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "integer.h"
#include "xprintf.h"

#include "diskio.h"
#include "ff.h"		

#include "vRTCC.h"
//#include "vUART_CMND.h"
#include "vUART_MENU.h"
//#include "vFFF.h"
#include "vWAVE.h"


DWORD AccSize;			/* Work register for fs command */
WORD AccFiles, AccDirs;
BYTE*  pBuff;
volatile UINT uTimer;	/* 1kHz increment timer */

char cMsgLine01;
const BYTE bMsg01[] = {
	"+Input your command!\n"		//入力表示コマンドモード
	"+(DEL)->command clear\n"      //コマンドクリア
	"+(ESC)->exit or clear\n"		//
	"+Dyymmdd->Date setting\n"		//
	"+Thhmmss->Time setting\n"		//
	"+G->Time Output\n"				//時間の表示

    "+wd <file name> - Dump text file\n"
	"+wo <file name> - Open wave file and show properties\n"
	"+wp - Wave playing start\n"
	"+wc - Close wave playing\n"

    "+fi [<mount>] - Force initialized the logical drive\n"	//
#if !_FS_READONLY 
	"+fs [<path>] - Show logical drive status\n"			//
#endif
	"+fl [<path>] - Directory listing\n"					//
	"+fo <mode> <file> - Open a file\n"						//
	"+fc - Close a file\n"									//
	"+fe <ofs> - Seek file pointer\n"						//
	"+fr <len> - read file\n"								//
	"+fd <len> - read and dump file from current fp\n"		//
#if !_FS_READONLY 
	"+fw <len> <val> - write file\n"						//
	"+fn <old_name> <new_name> - Change file/dir name\n"	//
	"+fu <path> - Unlink a file or dir\n"					//
	"+fv - Truncate file\n"									//
	"+fk <path> - Create a directory\n"						//
//	"+fa <atrr> <mask> <name> - Change file/dir attribute\n"//
//	"+ft <year> <month> <day> <hour> <min> <sec> <name> - Change timestamp\n"		//
	"+fx <src_name> <dst_name> - Copy file\n"				//
#endif
	"+fg <path> - Change current directory\n"				//
//	"+fq - Show current dir path\n"							//
//	"+fm <partition rule> <sect/clust> - Create file system\n" //
	"+dd [<pd#> <sector>] - Dump secrtor\n"					//
	"+di <pd#> - Initialize physical drive\n"				//
	"+ds <pd#> - Show disk status\n"						//

	"+bd <ofs> - Dump R/W buffer\n"							//
	"+br <pd#> <sector> <count> - Read disk into R/W buffer\n"	//
	"+bw <pd#> <sector> <count> - Write R/W buffer into disk\n"	//
	"+bf <n> - Fill working buffer\n"							//
//	"+fz [<year> <mon> <mday> <hour> <min> <sec>\n"			//
	"\0"			//
};


//******************************************************************************
//* initialization
//******************************************************************************
void vUART_menu_init(void) {
	eModeStatusC2 = eModeC2_menu_init ;
	vUART_CMND_Init();
	vXputs_return();
	xputs("\nFatFs module test monitor for PIC32MX\n");
	xputs(_USE_LFN ? "LFN Enabled" : "LFN Disabled");
	xprintf(", Code page: %u\n", _CODE_PAGE);
    
    pBuff = &fffBuff[0].bBuff[0];       //for FatFs command
}

//******************************************************************************
//* Menu mode control
//******************************************************************************
void vModeUartControl11(void) {
	char *ptr;
   	ptr = &cCmdBuf[0];
    
	switch (eModeStatusC2) {
	case  	eModeC2_menu_msg1 :
		xputs(bMsg01);							//初期メッセージ出力
		eModeStatusC2++;						//モードを次のステータスへ遷移
		break;

	case  	eModeC2_menu_init :
		vXputs_return();						//改行&入力指示プロンプト
		eModeStatusC2++;						//モードを次のステータスへ遷移
		break;

	case  	eModeC2_vGetsCMND :
		switch(eUART_CMND_Getc()) {					//コマンド文字列取得->cCmdBuf格納
		case eUART_CMND_Exec:
			eModeStatusC2 = eModeC2_vExecCmd;
			break;
		case eUART_CMND_Esc:
			eModeStatusC2 = eModeC2_menu_msg1;
			break;
		case eUART_CMND_Del:
		case eUART_CMND_Err:
			eModeStatusC2 = eModeC2_menu_init;
			break;
		case eUART_CMND_Wait:
		default:								//コマンド入力まち
			break;
		}
		break;

	case  	eModeC2_vExecCmd:					//Command selection
		switch(cCmdBuf[0]) {
		case 'T':								//時計設定コマンド
		case 't':								//時計設定コマンド
			vCommand_TimeSet();
			eModeStatusC2 = eModeC2_menu_init;
			break;
		case 'D':								//日付設定コマンド
//		case 'd':								//日付設定コマンド
			vCommand_DateSet();
			eModeStatusC2 = eModeC2_menu_init;
			break;
		case 'g':
		case 'G':
			vShowNowTimeMessage();
			eModeStatusC2 = eModeC2_menu_init;
			break;
		case 's':
		case 'S':
			eModeStatusC2 = eModeC2_menu_init;
			break;
		case '?':								//メニュー
			eModeStatusC2 = eModeC2_menu_msg1;
			break;
		case '\n':								//コマンド入力まち
		case '\0':								//コマンド入力まち
			eModeStatusC2 = eModeC2_menu_init;
			break;

			//pFatFS moniter////////////////////////////////////////////////
		case 'd':
		case 'b':
		case 'f':
			vCommand_FatFs();
			eModeStatusC2 = eModeC2_menu_init;
			break;
			//pFatFS moniter////////////////////////////////////////////////

			//FFF moniter////////////////////////////////////////////////
		case 'w':
		case 'W':
			vCommand_WAVE();
			eModeStatusC2 = eModeC2_menu_init;
			break;
			//FFF moniter////////////////////////////////////////////////

        default:								// コマンドエラー
			eModeStatusC2 = eModeC2_Command_error;
			break;
		}
		break;

	case  	eModeC2_Command_error:
		// コマンド該当なし
			xputs("\n? Unrecognized command format\n");	// 入力エラー
		eModeStatusC2 = eModeC2_menu_init;
		break;

	default:
		eModeStatusC2 = eModeC2_menu_init;
	}

}


//******************************************************************************
//* Timer Setting
//******************************************************************************
void vCommand_TimeSet(void) {
	char str[3];
	struct tm currentTime;

	//コマンドフォーマットチェック *hhmmss
	vComandFormatCheck_7Digit();
    
    RTCC_TimeGet(&currentTime);         //現在の設定時刻を取得

	switch(cCmdBuf[0]) {
	case 'T':							//時計設定コマンド
	case 't':							//時計設定コマンド
		//ascii->numeric and set to the time
		str[0] = cCmdBuf[1];
		str[1] = cCmdBuf[2];
		str[3] = 0x00;
		currentTime.tm_hour = (unsigned char)atoi(str);

		str[0] = cCmdBuf[3];
		str[1] = cCmdBuf[4];
		currentTime.tm_min  = (unsigned char)atoi(str);

		str[0] = cCmdBuf[5];
		str[1] = cCmdBuf[6];
		currentTime.tm_sec  = (unsigned char)atoi(str);

		RTCC_TimeSet(&currentTime);				//時間をRTCCモジュールに設定する

		xputs("Time Setting Finish!\n");
		vShowNowTimeMessage();					//設定時間の再表示
		break;

	default:
		xputs("? Format Error.\n");	//入力エラー
		break;
	}

}
/*****************************
 * Date Setting
 *****************************/
void vCommand_DateSet(void) {
	char str[3];
	struct tm currentTime;
	
	vComandFormatCheck_7Digit();        //コマンドフォーマットチェック *hhmmss
    
    RTCC_TimeGet(&currentTime);         //現在の設定時刻を取得

	//コマンドフォーマットチェック *hhmmss
	vComandFormatCheck_7Digit();

	switch(cCmdBuf[0]) {
	case 'D':							//日付設定コマンド
	case 'd':							//日付設定コマンド
		//ascii->numeric and set to the time
		str[0] = cCmdBuf[1];
		str[1] = cCmdBuf[2];
		str[3] = 0x00;
		currentTime.tm_year = (unsigned char)atoi(str);

		str[0] = cCmdBuf[3];
		str[1] = cCmdBuf[4];
		currentTime.tm_mon  = (unsigned char)atoi(str);

		str[0] = cCmdBuf[5];
		str[1] = cCmdBuf[6];
		currentTime.tm_mday  = (unsigned char)atoi(str);

		RTCC_TimeSet(&currentTime);				//日付時間をRTCCモジュールに設定する

		xputs("Date Setting Finish!\n");
		vShowNowTimeMessage();					//設定時間の再表示
		break;

	default:
		xputs("? Format Error.\n");	// 入力エラー
		break;
	}

}

//******************************************************************************
//* Show Now Time Message
//******************************************************************************
void vShowNowTimeMessage(void) {
	struct tm currentTime;
    RTCC_TimeGet(&currentTime);         //現在の設定時刻を取得
	xprintf( "Time is %02d:%02d:%02d\n", currentTime.tm_hour, currentTime.tm_min, currentTime.tm_sec);
	xprintf( "Date is %02d/%02d/%02d\n", currentTime.tm_year, currentTime.tm_mon, currentTime.tm_mday);
}

//******************************************************************************
//* Comand format check 7digit
//******************************************************************************
void vComandFormatCheck_7Digit(void) {
	char i;
	for( i=1 ; i<7 ; i++) {
		if(!isdigit(cCmdBuf[i])) {
			cCmdBuf[0] = '?';
		}
	}
}

//******************************************************************************
//* Timer Setting Error message
//******************************************************************************
void vModeC2_T_error(void) {

}

//******************************************************************************
//* FatFs option
//******************************************************************************
static
FRESULT scan_files (
	char* path		/* Pointer to the path name working buffer */
)
{
	DIR dirs;
	FRESULT res;
	int i;


	if ((res = f_opendir(&dirs, path)) == FR_OK) {
		while (((res = f_readdir(&dirs, &Finfo)) == FR_OK) && Finfo.fname[0]) {
			if (Finfo.fattrib & AM_DIR) {
				i = strlen(path);
				AccDirs++;
				path[i] = '/'; strcpy(&path[i+1], Finfo.fname);
				res = scan_files(path);
				path[i] = 0;
				if (res != FR_OK) break;
			} else {
#if 0
				xprintf("%s/%s\n", path, fn);
#endif
				AccFiles++;
				AccSize += Finfo.fsize;
			}
		}
	}
	return res;
}

//******************************************************************************
//* FatFs 
//******************************************************************************
void vCommand_FatFs(void) {
	char *ptr;
	long p1, p2, p3;
	BYTE b, drv = 0;
	const BYTE ft[] = {0,12,16,32};
	UINT s1, s2, cnt;
	DWORD ofs = 0, sect = 0;
	FRESULT res;
	FATFS *fs;				/* Pointer to file system object */
	DIR dir;				/* Directory object */

    	ptr = &cCmdBuf[0];
		switch (*ptr++) {
		case 'd' :
			switch (*ptr++) {
			case 'd' :	/* dd [<pd#> <sector>] - Dump secrtor */
				if (xatoi(&ptr, &p1)) {
					if (!xatoi(&ptr, &p2)) break;
				} else {
					p1 = drv; p2 = sect;
				}
				b = disk_read((BYTE)p1, pBuff, p2, 1);
				if (b) { xprintf("rc=%d\n", b); break; }
				drv = (BYTE)p1; sect = p2 + 1;
				xprintf("PD#:%u, Sector:%lu\n", (BYTE)p1, p2);
				for (ptr=(char*)pBuff, ofs = 0; ofs < 0x200; ptr += 16, ofs += 16)
					put_dump((BYTE*)ptr, ofs, 16, DW_CHAR);
				break;

			case 'i' :	/* di <pd#> - Initialize physical drive */
				if (!xatoi(&ptr, &p1)) break;
				xprintf("rc=%d\n", disk_initialize((BYTE)p1));
				break;

			case 's' :	/* ds <pd#> - Show disk status */
				if (!xatoi(&ptr, &p1)) break;
				if (disk_ioctl((BYTE)p1, GET_SECTOR_COUNT, &p2) == RES_OK)
					{ xprintf("Drive size: %lu sectors\n", p2); }
				if (disk_ioctl((BYTE)p1, GET_BLOCK_SIZE, &p2) == RES_OK)
					{ xprintf("Erase block: %lu sectors\n", p2); }
				if (disk_ioctl((BYTE)p1, MMC_GET_TYPE, &b) == RES_OK)
					{ xprintf("MMC/SDC type: %u\n", b); }
				if (disk_ioctl((BYTE)p1, MMC_GET_CSD, pBuff) == RES_OK)
					{ xputs("CSD:\n"); put_dump(pBuff, 0, 16, DW_CHAR); }
				if (disk_ioctl((BYTE)p1, MMC_GET_CID, pBuff) == RES_OK)
					{ xputs("CID:\n"); put_dump(pBuff, 0, 16, DW_CHAR); }
				if (disk_ioctl((BYTE)p1, MMC_GET_OCR, pBuff) == RES_OK)
					{ xputs("OCR:\n"); put_dump(pBuff, 0, 4, DW_CHAR); }
				if (disk_ioctl((BYTE)p1, MMC_GET_SDSTAT, pBuff) == RES_OK) {
					xputs("SD Status:\n");
					for (s1 = 0; s1 < 64; s1 += 16) put_dump(pBuff+s1, s1, 16, DW_CHAR);
				}
				break;
            default:
                xputs("? FatFs command Error.\n");	// 入力エラー
                break;
			}
			break;

		case 'b' :
			switch (*ptr++) {
			case 'd' :	/* bd <ofs> - Dump R/W buffer */
				if (!xatoi(&ptr, &p1)) break;
				for (ptr=(char*)&pBuff[p1], ofs = p1, cnt = 32; cnt; cnt--, ptr += 16, ofs += 16)
					put_dump((BYTE*)ptr, ofs, 16, DW_CHAR);
				break;
/*
			case 'e' :	// be <ofs> [<data>] ... - Edit R/W buffer 
				if (!xatoi(&ptr, &p1)) break;
				if (xatoi(&ptr, &p2)) {
					do {
						pBuff[p1++] = (BYTE)p2;
					} while (xatoi(&ptr, &p2));
					break;
				}
				for (;;) {
					xprintf("%04X %02X-", (WORD)p1, pBuff[p1]);
					xgets(Line, sizeof Line);
					ptr = Line;
					if (*ptr == '.') break;
					if (*ptr < ' ') { p1++; continue; }
					if (xatoi(&ptr, &p2))
						pBuff[p1++] = (BYTE)p2;
					else
						xputs("???\n");
				}
				break;
*/
			case 'r' :	/* br <pd#> <sector> <count> - Read disk into R/W buffer */
				if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
				xprintf("rc=%u\n", disk_read((BYTE)p1, pBuff, p2, (BYTE)p3));
				break;

			case 'w' :	/* bw <pd#> <sector> <count> - Write R/W buffer into disk */
				if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
				xprintf("rc=%u\n", disk_write((BYTE)p1, pBuff, p2, (BYTE)p3));
				break;

			case 'f' :	/* bf <n> - Fill working buffer */
				if (!xatoi(&ptr, &p1)) break;
				memset(pBuff, (int)p1, sizeof pBuff);
				break;

            default:
                xputs("? FatFs command Error.\n");	// 入力エラー
                break;
			}
			break;

		case 'f' :
			switch (*ptr++) {

			case 'i' :	/* fi [<mount>] - Force initialized the logical drive */
				if (!xatoi(&ptr, &p2)) p2 = 0;
				put_rc(f_mount(&FatFs, "", (BYTE)p2));
				break;

#if !_FS_READONLY
			case 's' :	/* fs [<path>] - Show logical drive status */
				while (*ptr == ' ') ptr++;
				res = f_getfree(ptr, (DWORD*)&p2, &fs);
				if (res) { put_rc(res); break; }
				xprintf("FAT type = FAT%u\nBytes/Cluster = %lu\nNumber of FATs = %u\n"
						"Root DIR entries = %u\nSectors/FAT = %lu\nNumber of clusters = %lu\n"
						"Volume start (lba) = %lu\nFAT start (lba) = %lu\nDIR start (lba,clustor) = %lu\nData start (lba) = %lu\n\n...",
						ft[fs->fs_type & 3], fs->csize * 512UL, fs->n_fats,
						fs->n_rootdir, fs->fsize, fs->n_fatent - 2,
						fs->volbase, fs->fatbase, fs->dirbase, fs->database
				);
				AccSize = AccFiles = AccDirs = 0;
				res = scan_files(ptr);
				if (res) { put_rc(res); break; }
				xprintf("\r%u files, %lu bytes.\n%u folders.\n"
						"%lu KiB total disk space.\n%lu KiB available.\n",
						AccFiles, AccSize, AccDirs,
						(fs->n_fatent - 2) * (fs->csize / 2), p2 * (fs->csize / 2)
				);
				break;
#endif
			case 'l' :	/* fl [<path>] - Directory listing */
				while (*ptr == ' ') ptr++;
				res = f_opendir(&dir, ptr);
				if (res) { put_rc(res); break; }
				p1 = s1 = s2 = 0;
				for(;;) {
					res = f_readdir(&dir, &Finfo);
					if ((res != FR_OK) || !Finfo.fname[0]) break;
					if (Finfo.fattrib & AM_DIR) {
						s2++;
					} else {
						s1++; p1 += Finfo.fsize;
					}
					xprintf("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9lu  %s\n",
							(Finfo.fattrib & AM_DIR) ? 'D' : '-',
							(Finfo.fattrib & AM_RDO) ? 'R' : '-',
							(Finfo.fattrib & AM_HID) ? 'H' : '-',
							(Finfo.fattrib & AM_SYS) ? 'S' : '-',
							(Finfo.fattrib & AM_ARC) ? 'A' : '-',
							(Finfo.fdate >> 9) + 1980, (Finfo.fdate >> 5) & 15, Finfo.fdate & 31,
							(Finfo.ftime >> 11), (Finfo.ftime >> 5) & 63, Finfo.fsize, Finfo.fname);
				}
				xprintf("%4u File(s),%10lu bytes total\n%4u Dir(s)", s1, p1, s2);
#if _FS_READONLY
				xprintf("\n");
#else
				if (f_getfree(ptr, (DWORD*)&p1, &fs) == FR_OK)
					xprintf(", %10lu bytes free\n", p1 * fs->csize * 512);
#endif
				break;
#if _USE_FIND
			case 'L' :	/* fL <path> <pattern> - Directory search */
				while (*ptr == ' ') ptr++;
				ptr2 = ptr;
				while (*ptr != ' ') ptr++;
				*ptr++ = 0;
				res = f_findfirst(&dir, &Finfo, ptr2, ptr);
				while (res == FR_OK && Finfo.fname[0]) {
					xprintf("%s", Finfo.fname);
#if _USE_LFN
					for (p2 = strlen(Finfo.fname); p2 < 12; p2++) xprintf(" ");
					xprintf("  %s", Lfname); 
#endif
					xprintf("\n");
					res = f_findnext(&dir, &Finfo);
				}
				if (res) put_rc(res);
				f_closedir(&dir);
				break;
#endif
			case 'o' :	/* fo <mode> <file> - Open a file */
				if (!xatoi(&ptr, &p1)) break;
				while (*ptr == ' ') ptr++;
				put_rc(f_open(&File[SD_FILE_0], ptr, (BYTE)p1));
				break;

			case 'c' :	/* fc - Close a file */
				put_rc(f_close(&File[SD_FILE_0]));
				break;

			case 'e' :	/* fe <ofs> - Seek file pointer */
				if (!xatoi(&ptr, &p1)) break;
				res = f_lseek(&File[SD_FILE_0], p1);
				put_rc(res);
				if (res == FR_OK)
					xprintf("fptr = %lu(0x%lX)\n", f_tell(&File[SD_FILE_0]), f_tell(&File[SD_FILE_0]));
				break;

			case 'r' :	/* fr <len> - read file */
				if (!xatoi(&ptr, &p1)) break;
				p2 = 0;
				uTimer = 0;
				while (p1) {
					if ((DWORD)p1 >= sizeof pBuff) {
						cnt = sizeof pBuff; p1 -= sizeof pBuff;
					} else {
						cnt = p1; p1 = 0;
					}
					res = f_read(&File[SD_FILE_0], pBuff, cnt, &s2);
					if (res != FR_OK) { put_rc(res); break; }
					p2 += s2;
					if (cnt != s2) break;
				}
				xprintf("%lu bytes read with %lu kB/sec.\n", p2, uTimer ? (p2 / uTimer) : 0);
				break;

			case 'd' :	/* fd <len> - read and dump file from current fp */
				if (!xatoi(&ptr, &p1)) break;
				ofs = f_tell(&File[SD_FILE_0]);
				while (p1) {
					if ((UINT)p1 >= 16) { cnt = 16; p1 -= 16; }
					else 				{ cnt = p1; p1 = 0; }
					res = f_read(&File[SD_FILE_0], pBuff, cnt, &cnt);
					if (res != FR_OK) { put_rc(res); break; }
					if (!cnt) break;
					put_dump(pBuff, ofs, cnt, DW_CHAR);
					ofs += 16;
				}
				break;

#if !_FS_READONLY 
			case 'w' :	/* fw <len> <val> - write file */
				if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2)) break;
				memset(pBuff, (int)p2, sizeof pBuff);
				p2 = 0;
				uTimer = 0;
				while (p1) {
					if ((DWORD)p1 >= sizeof pBuff) {
						cnt = sizeof pBuff; p1 -= sizeof pBuff;
					} else {
						cnt = p1; p1 = 0;
					}
					res = f_write(&File[SD_FILE_0], pBuff, cnt, &s2);
					if (res != FR_OK) { put_rc(res); break; }
					p2 += s2;
					if (cnt != s2) break;
				}
				xprintf("%lu bytes written with %lu kB/sec.\n", p2, uTimer ? (p2 / uTimer) : 0);
				break;

			case 'n' :	/* fn <old_name> <new_name> - Change file/dir name */
				while (*ptr == ' ') ptr++;
				ptr2 = strchr(ptr, ' ');
				if (!ptr2) break;
				*ptr2++ = 0;
				while (*ptr2 == ' ') ptr2++;
				put_rc(f_rename(ptr, ptr2));
				break;

			case 'u' :	/* fu <path> - Unlink a file or dir */
				while (*ptr == ' ') ptr++;
				put_rc(f_unlink(ptr));
				break;

			case 'v' :	/* fv - Truncate file */
				put_rc(f_truncate(&File[SD_FILE_0]));
				break;

			case 'k' :	/* fk <path> - Create a directory */
				while (*ptr == ' ') ptr++;
				put_rc(f_mkdir(ptr));
				break;
#endif
#if _USE_CHMOD && !_FS_READONLY
			case 'a' :	/* fa <atrr> <mask> <name> - Change file/dir attribute */
				if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2)) break;
				while (*ptr == ' ') ptr++;
				put_rc(f_chmod(ptr, p1, p2));
				break;

			case 't' :	/* ft <year> <month> <day> <hour> <min> <sec> <name> - Change timestamp */
				if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
				Finfo.fdate = (WORD)(((p1 - 1980) << 9) | ((p2 & 15) << 5) | (p3 & 31));
				if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
				Finfo.ftime = (WORD)(((p1 & 31) << 11) | ((p1 & 63) << 5) | ((p1 >> 1) & 31));
				put_rc(f_utime(ptr, &Finfo));
				break;
#endif

#if !_FS_READONLY
			case 'x' : /* fx <src_name> <dst_name> - Copy file */
				while (*ptr == ' ') ptr++;
				ptr2 = strchr(ptr, ' ');
				if (!ptr2) break;
				*ptr2++ = 0;
				while (*ptr2 == ' ') ptr2++;
				xprintf("Opening \"%s\"", ptr);
				res = f_open(&File[SD_FILE_0], ptr, FA_OPEN_EXISTING | FA_READ);
				xputc('\n');
				if (res) {
					put_rc(res);
					break;
				}
				xprintf("Creating \"%s\"", ptr2);
				res = f_open(&File[SD_FILE_1], ptr2, FA_CREATE_ALWAYS | FA_WRITE);
				xputc('\n');
				if (res) {
					put_rc(res);
					f_close(&File[SD_FILE_0]);
					break;
				}
				xprintf("Copying...");
				p1 = 0;
				for (;;) {
					res = f_read(&File[SD_FILE_0], pBuff, sizeof pBuff, &s1);
					if (res || s1 == 0) break;   /* error or eof */
					res = f_write(&File[SD_FILE_1], pBuff, s1, &s2);
					p1 += s2;
					if (res || s2 < s1) break;   /* error or disk full */
				}
				xprintf("\n%lu bytes copied.\n", p1);
				f_close(&File[SD_FILE_0]);
				f_close(&File[SD_FILE_1]);
				break;
#endif
#if _FS_RPATH >= 1
			case 'g' :	/* fg <path> - Change current directory */
				while (*ptr == ' ') ptr++;
				put_rc(f_chdir(ptr));
				break;
#if _FS_RPATH >= 2
			case 'q' :	/* fq - Show current dir path */
				res = f_getcwd(Line, sizeof Line);
				if (res)
					put_rc(res);
				else
					xprintf("%s\n", Line);
				break;
#endif
#endif
#if _USE_MKFS
			case 'm' :	/* fm <partition rule> <sect/clust> - Create file system */
				if (!xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
				xprintf("The memory card will be formatted. Are you sure? (Y/n)=", p1);
				xgets(Line, sizeof Line);
				if (Line[0] == 'Y')
					put_rc(f_mkfs("", (BYTE)p2, (DWORD)p3, pBuff, sizeof pBuff));
				break;
#endif
            default:
                xputs("? FatFs command Error.\n");	// 入力エラー
                break;
			}
			break;

		}
	
}


//******************************************************************************
//* WAVE 
//******************************************************************************
void vCommand_WAVE(void) 
{
   	char *ptr;

    ptr = &cCmdBuf[0];
    switch (*ptr++) {
    case 'w' :
    case 'W' :
        switch (*ptr++) {
        case 'd' :	// wd Dump text file
            while(*ptr == ' ') ptr++;
            rFFF_open(ptr, SD_FILE_0);
            break;

        case 'o' :	// wo Open wave file and show properties
            while(*ptr == ' ') ptr++;
            rWAVE_file_open(ptr);
            break;

        case 'p' :	// wp wave playing start
            vWAVE_play_start();
            break;

        case 'c' :	// wc close wave play
            vWAVE_close();
            break;

        default:
            xputs("? WAVE command Error.\n");	// 入力エラー
            break;
        }
        break;
    }
}


//******************************************************************************
//* 改行&入力指示プロンプト
//******************************************************************************
void vXputs_return(void) 
{
	xputs(">");					//改行&入力指示プロンプト
}


//******************************************************************************
//* pFatFs Moniter
//******************************************************************************
void put_rc (
    FRESULT rc
) 
{		//ステータスOUTPUT
	const char *str =
		"OK\0" "DISK_ERR\0" "INT_ERR\0" "NOT_READY\0" "NO_FILE\0" "NO_PATH\0"
		"INVALID_NAME\0" "DENIED\0" "EXIST\0" "INVALID_OBJECT\0" "WRITE_PROTECTED\0"
		"INVALID_DRIVE\0" "NOT_ENABLED\0" "NO_FILE_SYSTEM\0" "MKFS_ABORTED\0" "TIMEOUT\0"
		"LOCKED\0" "NOT_ENOUGH_CORE\0" "TOO_MANY_OPEN_FILES\0";
	FRESULT i;

	for (i = 0; i != rc && *str; i++) {
		while (*str++) ;
	}
	xprintf("rc=%u FR_%s\n", (UINT)rc, str);

}


