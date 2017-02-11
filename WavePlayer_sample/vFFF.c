/*******************************************************************************
 *	FatFs interface with FIFO
 *	author  :hiroshi murakami
 *	created :20170121
 *	modified:-
 ******************************************************************************/
#define _vFFF_C

#include "string.h"
#include "xprintf.h"
#include "vFFF.h"

//******************************************************************************
// Initialize FFF
//******************************************************************************
void vFFF_init(void)
{
	int i;

	// Clear FIFO buffers & File object
	for(i = 0 ; i < SD_FILES ; i++){
		vFFF_FIFO_init(i);
		f_close(&File[i]);
	}
}

//******************************************************************************
// Initialize FFF FIFO
//******************************************************************************
void vFFF_FIFO_init(
    int fileNo
)
{
	// Clear FIFOs
	vFIFO_init (&ffFifo[fileNo], sizeof(fffBuff[fileNo].bBuff), fffBuff[fileNo].bBuff);
}

//******************************************************************************
// FFF open
//******************************************************************************
FRESULT rFFF_open (
    BYTE* fileName,
    int fileNo
)
{
	FRESULT res;
    vFFF_FIFO_init(fileNo);
    res = f_open(&File[fileNo], fileName,  FA_READ);
    put_rc(res);
    return res;
}

//******************************************************************************
// FFF close
//******************************************************************************
FRESULT rFFF_close (
    int fileNo
)
{
	return f_close(&File[fileNo]);
}


//******************************************************************************
// FFF block read
//******************************************************************************
FRESULT rFFF_BlockRead(
    int fileNo
)
{
	FRESULT res;
  	UINT read_out_byte,block;
    FSIZE_t buffSector, fsPtr;

    if(File[fileNo].obj.fs){             //File[SD_FILE_0].obj.fsポンタ=nullはファイルオブジェクトなし
        if(f_eof(&File[fileNo])){
            f_close(&File[fileNo]);
        }else{
            if(SD_BUFFER_SIZE <= iFIFO_space(&ffFifo[fileNo])){
                if( FIFO_BUSY < ffFifo[fileNo].status){
                    ffFifo[fileNo].status = FIFO_BUSY;
                    fsPtr =  f_tell(&File[fileNo]);
                    buffSector = fsPtr / SD_BUFFER_SIZE; 
                    block = buffSector % SD_BUFFER_BLOCK;
                    res = f_read(&File[fileNo], &fffBuff[fileNo].bBlockBuff[block][0], SD_BUFFER_SIZE, &read_out_byte);
                    if (res != FR_OK) {
                        put_rc(res);
                        xputs("rFFF_mount\n");
                        put_rc(rFFF_mount(&FatFs));     // file system mount
                        vFFF_init ();
                        return res;
                    }
                    ffFifo[fileNo].ct = ffFifo[fileNo].ct + read_out_byte;
                    ffFifo[fileNo].status = FIFO_BUFFER_STORED;
                }
            } 
        }
    }else{
        return FR_NO_FILE;
    }
    return res;
}

//******************************************************************************
// FFF remains
//******************************************************************************
int iFFF_remains(
    int fileNo
)
{
    return iFIFO_remains(&ffFifo[fileNo]);
}

//******************************************************************************
// return end of file = 1
//******************************************************************************
int iFFF_eof(
    int fileNo
)
{
	if(ffFifo[fileNo].ct == 0){
		if(f_eof(&File[fileNo])){
			return 1;
		}else{
            return 0;
		}
	}
	return 0;
}

//******************************************************************************
// FFF getc
//******************************************************************************
BYTE bFFF_getc(
    int fileNo
)
{
    if(0 == iFIFO_remains(&ffFifo[fileNo])) return 0x00;
    return bFIFO_getc(&ffFifo[fileNo]);
}

//******************************************************************************
// return buffer space bytes
//******************************************************************************
int iFFF_space(
    int fileNo
)
{
    return (ffFifo[fileNo].buffer_size - ffFifo[fileNo].ct);
}

//******************************************************************************
// pbFFF gets
// put in out_buffer from vFFF 
// return buffer address
//******************************************************************************
BYTE* pbFFF_gets(
    BYTE* out_buffer,
    int length,
    int fileNo
)
{
    int i;
    BYTE* buff;

    if(iFFF_eof(fileNo)) return NULL;
    buff = out_buffer;
    for(i = 0; i < length ; i++){
    	*buff = bFFF_getc(fileNo);
	    buff++;
	}
	return out_buffer;
}


//******************************************************************************
// FFF text getc (it return only text character code
//     0x20(space)---0x7e(~), 0x0d(CR) (*0x0a(LF) is not return.)
//******************************************************************************
BYTE bFFF_text_getc(
    int fileNo
)
{
	BYTE a;

    while(!(iFFF_eof(fileNo)))
    {
    	a = bFIFO_getc(&ffFifo[fileNo]);
		if(0x20 <= a && a <= 0x7e) return a;
		if(0x0a == a) return a;                 // 0x0a = \n = LF
		if(0x0d == a) return 0x0a;              // 0x0d = CR => LF
		if(0x09 == a) return 0x20;              // 0x09 = TAB => SPACE
    }
    return 0x00;
}

//******************************************************************************
// pbFFF get a text line
//
// skip Space characters when there are Space characters hed of line.
// put in out_buffer from vFFF
// return buffer address
//******************************************************************************
BYTE* pbFFF_text_line_get(
    BYTE* out_buffer,
    int length,			// it is need one character byte for \0.
    int fileNo
)
{
    int i;
    BYTE* buff;

    if(iFFF_eof(fileNo)) return NULL;

    buff = out_buffer;
	*buff = bFFF_text_getc(fileNo);
	while(0x20 == *buff || 0x0a == *buff)	// head of space or LF are skip
	{
		*buff = bFFF_text_getc(fileNo);
        buff++;
	}

	length--;
    for(i = 1; i < length ; i++){
    	*buff = bFFF_text_getc(fileNo);
    	if(0x0d == *buff || 0x00 == *buff) break;			// stop when CR exist.
	    buff++;
	}
	*buff = '\0';
	return out_buffer;
}
