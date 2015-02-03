/**
  CMP1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cmp1.c

  @Summary
    This is the generated driver implementation file for the CMP1 driver using MPLAB� Code Configurator

  @Description
    This source file provides APIs for CMP1.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.10
        Device            :  PIC12F1822
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.33
        MPLAB             :  MPLAB X 2.26
*/

/*
Copyright (c) 2013 - 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "cmp1.h"

/**
  Section: CMP1 APIs
*/

void CMP1_Initialize(void)
{

    /* Disable CMP1 interrupt before configuring the CMP1
       control register.Although a comparator is disabled, an interrupt can be
       generated by changing the output polarity with the CxPOL bit of the
       CMxCON0 register,or by switching the comparator on or off with the CxON
       bit of the CMxCON0 register.*/
    PIE2bits.C1IE = 0;

    // set the CMP to the options selected in MPLAB� Code Configurator
    // C1POL not inverted; C1ON enabled; C1HYS disabled; C1SYNC asynchronous; C1OUT CPOL_VPVN; C1SP hi_speed; C1OE COUT_internal;                          
    CM1CON0 = 0x84;

    // C1PCH FVR_pin; C1INTN no_intFlag; C1INTP no_intFlag; C1NCH0 CIN1-;                          
    CM1CON1 = 0x21;


    // Clearing IF flag before enabling the interrupt.
    PIR2bits.C1IF = 0;

    // Enabling CMP1 interrupt.
    PIE2bits.C1IE = 1;
}


bool CMP1_GetOutputStatus(void)
{
     return (CM1CON0bits.C1OUT);
}

void CMP1_ISR(void)
{
    // clear the CMP1 interrupt flag
    PIR2bits.C1IF = 0;
}

/**
 End of File
*/