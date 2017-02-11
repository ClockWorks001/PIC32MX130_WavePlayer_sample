/*******************************************************************************
 *	FIFO buffer for serial data
 *	author  :hiroshi murakami
 *	created :20160827
 *	modified:-
 ******************************************************************************/
#ifndef _vFIFO_H
#define _vFIFO_H

#include "integer.h"

#define FIFO_BUFFER_STORED 0
#define FIFO_BUFFER_EMPTY -1
#define FIFO_BUSY -8
#define FIFO_BUFFER_FULL -9

/*****************************
 * VARIABLES
 *****************************/
typedef volatile struct
{
	int     ri, wi, ct;             // Read index, Write index, Data counter
	int     status;                 // status -1:empty, -9:full
	int     buffer_size;            // buffer_size
	BYTE    *buffer; // FIFO buffer
} FIFO_STRUCT;

/*****************************
 * PROTOTYPES
 *****************************/
void vFIFO_init (FIFO_STRUCT* Fifo, int buffer_size, BYTE* buffer);
int  iFIFO_putc (FIFO_STRUCT* Fifo, BYTE d);    // Get a byte from FIFO. *return a data from buffer
BYTE bFIFO_getc (FIFO_STRUCT* Fifo);            // Put a byte into FIFO. *return a status
#define iFIFO_remains(Fifop)  ((Fifop)->ct)      // return remaining bytes of data existing of FIFO. if zero there are no data.
#define iFIFO_full(Fifop)  ((Fifop)->ct == (Fifop)->buffer_size)     
#define iFIFO_space(Fifop)  ((Fifop)->buffer_size - (Fifop)->ct)     

#endif

