/*******************************************************************************
 *	処理タイミング用 TIMER1 設定
 *  1000Hz 1msec interval
 *	author  :hiroshi murakami
 *	created :20161225
 *	modified:-
 ******************************************************************************/
#ifndef _vTMR1_H
#define _vTMR1_H

/*****************************
 * VARIABLES
 *****************************/
#if defined _vTMR1_C
//    static volatile
volatile unsigned int uiTMR001;             // used for main signal
volatile unsigned int uiTMR002, uiTMR003;   // used for FatFs
volatile unsigned int uiTMR004;             // used for test
#else
volatile extern unsigned int uiTMR001, uiTMR002, uiTMR003, uiTMR004;
#endif

/*****************************
 * PROTOTYPES
 *****************************/
void Intrupt_TMR1(void);    //decrease timer parameter step by 1msec.
#define IS_uiTMR001_FINISH (uiTMR001==0)
#define IS_uiTMR002_FINISH (uiTMR002==0)
#define IS_uiTMR003_FINISH (uiTMR003==0)
#define IS_uiTMR004_FINISH (uiTMR004==0)

#endif