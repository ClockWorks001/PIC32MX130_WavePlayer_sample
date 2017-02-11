/*******************************************************************************
 *	RTCC処理
 *	author  :hiroshi murakami
 *	created :20161225
 *	modified:-
 ******************************************************************************/
#ifndef _vRTCC_H
#define _vRTCC_H

#include "integer.h"

/*****************************
 * VARIABLES
 *****************************/
#if defined _vRTCC_C

char cFlag1Minute;
#else

extern char cFlag1Minute;
#endif

/*****************************
 * PROTOTYPES
 *****************************/
DWORD get_fattime (void);						//FatFs書き込み時の現在時間取得用


#endif

