/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.0
        Device            :  PIC32MX130F064B
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC32 1.40
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "integer.h"
#include "xprintf.h"
#include "vTMR1.h"
//#include "vUART_CMND.h"
#include "vUART_MENU.h"
//#include "vFIFO.h"
//#include "vFFF.h"
#include "vWAVE.h"

#define LED1_Toggle() IO_RB6_Toggle() 

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    uiTMR001 = 0;
    uiTMR004 = 0;
    vUART_CMND_Init();
    vUART_menu_init();

    xputs("rFFF_mount\n");
    put_rc(rFFF_mount(&FatFs));     // file system mount
    put_rc(rFFF_mount(&FatFs));     // file system mount
    vFFF_init ();
    TMR3_Stop();    //★★★★★★★★★★★
    AUDIO_EN();
    
    while (1)
    {
        // Add your application code

        if(iFFF_remains(SD_FILE_0)) xputc(bFFF_getc(SD_FILE_0)); // output test for vFFF
//        if(iFFF_remains(WAVE_FILE_1)) xputc(bFFF_getc(WAVE_FILE_1)); // test for vFFF
        rFFF_BlockRead(SD_FILE_0);
        rFFF_BlockRead(WAVE_FILE_1);

        if(IS_uiTMR001_FINISH){
            uiTMR001 = 500; //500msec period
            LED1_Toggle();
        }

        vUART_TxPutc();
        vModeUartControl11();

    }

    return -1;
}

/**
 End of File
*/