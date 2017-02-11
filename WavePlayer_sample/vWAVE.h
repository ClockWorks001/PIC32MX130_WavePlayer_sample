/*******************************************************************************
 *	WAVE file process
 *	author  :hiroshi murakami
 *	created :20170129
 *	modified:-
 *  Timer2 : for PWM source clock
 *  Timer3 : for sampling rate of WAVE play
 ******************************************************************************/
#ifndef _vWAVE_H
#define _vWAVE_H

#include "integer.h"
#include "vFFF.h"

/*****************************
 * VARIABLES
 *****************************/

#define AUDIO_EN()		LATBbits.LATB5 = 0	/* CS = L */
#define	AUDIO_DISEN()	LATBbits.LATB5 = 1	/* CS = H */

#define SD_POWER_EN()		LATBbits.LATB10 = 1	/* CS = H */
#define	SD_POWER_DISEN()	LATBbits.LATB10 = 0	/* CS = L */

#define	PWM_CENTER_VALUE	128	

//---------------------------------------------------------
// WAVE parameter
//---------------------------------------------------------
typedef enum 
{
	eWave_idle = 0,
	eWave_busy,
	eWave_end,
	eWave_close
} WAVE_STATUS;

typedef struct{
	int		iFmtByte, iFmtID, iChannel, iSamplingRate, 
            iDataSpeed,  iBlockSize, iBits;	//WAV Format Parameters1
	unsigned long ulDataByte;						//WAV Format Parameters2
	WAVE_STATUS 	eWaveStatus;		// 1:Busy, 0:idle
} WAVE_STRUCT;


#if defined  _vWAVE_C
    //---------------------------------------------------------
    // FatFs Work Area
    //---------------------------------------------------------
	BYTE res;
	WORD s1, s2, s3, ofs, cnt, w;

    //---------------------------------------------------------
    // WAVE Work Area
    //---------------------------------------------------------
	WAVE_STRUCT wave;	

#else
    //---------------------------------------------------------
    // pFatFs Work Area
    //---------------------------------------------------------
	extern BYTE res;
	extern WORD s1, s2, s3, ofs, cnt, w;

    //---------------------------------------------------------
    // pFatFs Work Area
    //---------------------------------------------------------
	extern struct WAVE_STRUCT wave;	

#endif

/*****************************
 * PROTOTYPES
 *****************************/
WORD wSwab_w(unsigned char *A);	//change 2bytes stream to word (unsigned short)
DWORD dwSwab_dw(unsigned char *A);	//change 4bytes stream to double word (unsigned long)
void vWAVE_init(void) ;		//TIMER & PWM initialize
void vWAVE_close(void) ;	//TIMER & PWM close
void vTMR3_init(unsigned int T3_PR);
void Interrupt_TMR3(void);
unsigned short usGetPwmValue(void);
void vReadNextSector(void);
FRESULT rWAVE_file_open(BYTE *WaveFileName);
void vWAVE_play_start(void); 


#endif
