/*******************************************************************************
 *	FIFO buffer for serial data
 *	author  :hiroshi murakami
 *	created :20160827
 *	modified:-
 ******************************************************************************/
#define _vFIFO_C

#include "string.h"
#include "integer.h"
#include "vFIFO.h"

//******************************************************************************
// Get a byte from FIFO *return a data from buffer
//******************************************************************************
BYTE bFIFO_getc (
	FIFO_STRUCT* Fifo
)
{
	BYTE d;
	int i;

	Fifo->status = FIFO_BUFFER_STORED;
	if (!Fifo->ct)            	//when FIFO buffer empty */
		{
			Fifo->status = FIFO_BUFFER_EMPTY;
			return 0x00;
		}

	i = Fifo->ri;             	// Get a byte from FIFO
	d = Fifo->buffer[i++];
	Fifo->ri = i % Fifo->buffer_size;
	Fifo->ct--;

	return d;					//return a data
}

//******************************************************************************
// Put a byte into FIFO *return a status
//******************************************************************************
int iFIFO_putc (
	FIFO_STRUCT* Fifo,
	BYTE d
)
{
	int i;

	if (iFIFO_full(Fifo))         	// Return when FIFO is full
		{
			Fifo->status = FIFO_BUFFER_FULL;
			return  FIFO_BUFFER_FULL;
		}

	Fifo->status = 0;
	i = Fifo->wi;     				// Put a data into the FIFO
	Fifo->buffer[i++] = d;
	Fifo->wi = i % Fifo->buffer_size;
	Fifo->ct++;
	return  FIFO_BUFFER_STORED;

}

//******************************************************************************
// Initialize FIFO instance
//******************************************************************************
void vFIFO_init (
	FIFO_STRUCT* Fifo,
	int buffer_size,
	BYTE* buffer
)
{
	/* Clear FIFOs */
	Fifo->ri = 0;
	Fifo->wi = 0;
	Fifo->ct = 0;
	Fifo->status = FIFO_BUFFER_EMPTY;
	Fifo->buffer_size = buffer_size;
	Fifo->buffer = buffer;
	memset( (Fifo->buffer) , 0x00 , Fifo->buffer_size );
}


