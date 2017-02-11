/*******************************************************************************
 *	RTCC処理
 *	author  :hiroshi murakami
 *	created :20161225
 *	modified:-
 ******************************************************************************/
#define _vRTCC_C

#include "mcc_generated_files/mcc.h"
#include "vRTCC.h"

/*****************************
 * VARIABLES
 *****************************/


//******************************************************************************
/*---------------------------------------------------------*/
/* User Provided RTC Function for FatFs module             */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support an RTC.                     */
/* This function is not required in read-only cfg.         */
DWORD get_fattime (void)
{
	struct tm currentTime;
	DWORD tmr;

	RTCC_TimeGet(&currentTime);
	tmr =	 (((DWORD)currentTime.tm_year + 2000 - 1980) << 25)
			 | ((DWORD)currentTime.tm_mon << 21)
			 | ((DWORD)currentTime.tm_mday << 16)
			 | (WORD)(currentTime.tm_hour << 11)
			 | (WORD)(currentTime.tm_min << 5)
			 | (WORD)(currentTime.tm_sec >> 1);

	return tmr;
}
