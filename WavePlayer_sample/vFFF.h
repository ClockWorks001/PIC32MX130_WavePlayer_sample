/*******************************************************************************
 *	FatFs interface with FIFO
 *	author  :hiroshi murakami
 *	created :20170121
 *	modified:-
 ******************************************************************************/
#ifndef _vFFF_H
#define _vFFF_H

#include "integer.h"
#include "ff.h"		//FatFs定義体取得の為
#include "vFIFO.h"

#define SD_BUFFER_BLOCK 4			//2
#define SD_BUFFER_SIZE _MAX_SS		//512
#define SD_FILES        2           //number of file object
#define SD_FILE_0       0           //file object name
#define SD_FILE_1       1           //file object name
#define WAVE_FILE_1     1           //file object name

/*****************************
 * VARIABLES
 *****************************/
typedef union {
BYTE	bBuff[SD_BUFFER_BLOCK * SD_BUFFER_SIZE];        // FIFO buffer//
BYTE	bBlockBuff[SD_BUFFER_BLOCK][SD_BUFFER_SIZE];    // FIFO buffer Byte line//
SHORT	sBlockBuff[SD_BUFFER_BLOCK][SD_BUFFER_SIZE/2];	// FIFO buffer Word line//
}FFF_BUFF;

#if defined _vFFF_C
    FATFS FatFs;                // File system object */
    FIL   File[SD_FILES];       // File objects */
//    DIR   Dir;				//Directory object
	FILINFO Finfo;				//File information
    FFF_BUFF fffBuff[SD_FILES];
    FIFO_STRUCT ffFifo[SD_FILES];
#else
    extern FATFS FatFs;                 // File system object 
    extern FIL   File[SD_FILES];		// File objects 
	extern FILINFO Finfo;				//File information
    extern FFF_BUFF fffBuff[SD_FILES];
    extern FIFO_STRUCT ffFifo[SD_FILES];
#endif

/*****************************
 * PROTOTYPES
 *****************************/
void vFFF_init(void);
void vFFF_FIFO_init(int fileNo);
FRESULT rFFF_open(BYTE* fileName, int fileNo);
FRESULT rFFF_close(int fileNo);
FRESULT rFFF_BlockRead(int fileNo);
BYTE bFFF_getc(int fileNo);
BYTE* pbFFF_gets(BYTE* out_buffer, int length, int fileNo );
int iFFF_remains(int fileNo);   // check remaining bytes of data existing of FIFO. "zero" means no data.
int iFFF_eof(int fileNo);
int iFFF_space(int fileNo);
BYTE bFFF_text_getc(int fileNo);
BYTE* pbFFF_text_line_get(BYTE* out_buffer, int length,int fileNo);

#define rFFF_mount(Fifop)       f_mount((Fifop),"",0)
        
#endif

