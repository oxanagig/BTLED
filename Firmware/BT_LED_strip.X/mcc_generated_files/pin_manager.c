/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB� Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC16F1619
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

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

#include <xc.h>
#include "pin_manager.h"
#include <stdbool.h>

void PIN_MANAGER_Initialize(void) {
    LATA = 0x00;
    TRISA = 0x1D;
    ANSELA = 0x11;

    LATB = 0x20;
    TRISB = 0xC0;
    ANSELB = 0x00;
    WPUB = 0x00;

    LATC = 0x00;
    TRISC = 0xFD;
    ANSELC = 0x00;
    WPUC = 0x04;

    OPTION_REGbits.nWPUEN = 0x00;

    // enable interrupt-on-change individually    
    IOCBP6 = 1;
    IOCBP7 = 1;
    IOCCP3 = 1;
    IOCCP4 = 1;
    IOCCP5 = 1;
    IOCCP6 = 1;
    IOCCP7 = 1;

    // enable interrupt-on-change globally
    INTCONbits.IOCIE = 1;

    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    RA1PPS = 0x0F; // RA1->PWM4:PWM4OUT
    RXPPS = 0x02; // RA2->EUSART:RX
    RA5PPS = 0x07; // RA5->CLC4:CLC4OUT
    RB4PPS = 0x11; // RB4->MSSP:SDO
    RC0PPS = 0x12; // RC0->EUSART:TX
    SSPCLKPPS = 0x11; // RC1->MSSP:SCK
    RC1PPS = 0x10; // RC1->MSSP:SCK
    SSPDATPPS = 0x12; // RC2->MSSP:SDI
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
    GIE = state;
}

void PIN_MANAGER_IOC(void) {
    static volatile char counter = 0;
    if ((IOCBP6 == 1) && (IOCBF6 == 1)) {
        //@TODO Add handling code for IOC on pin RB6

        // clear interrupt-on-change flag
        IOCBF6 = 0;
    } else if ((IOCBP7 == 1) && (IOCBF7 == 1)) {
        //@TODO Add handling code for IOC on pin RB7
        counter++;
        // clear interrupt-on-change flag
        IOCBF7 = 0;
    } else if ((IOCCP3 == 1) && (IOCCF3 == 1)) {
        //@TODO Add handling code for IOC on pin RC3

        // clear interrupt-on-change flag
        IOCCF3 = 0;
    } else if ((IOCCP4 == 1) && (IOCCF4 == 1)) {
        //@TODO Add handling code for IOC on pin RC4

        // clear interrupt-on-change flag
        IOCCF4 = 0;
    } else if ((IOCCP5 == 1) && (IOCCF5 == 1)) {
        //@TODO Add handling code for IOC on pin RC5

        // clear interrupt-on-change flag
        IOCCF5 = 0;
    } else if ((IOCCP6 == 1) && (IOCCF6 == 1)) {
        //@TODO Add handling code for IOC on pin RC6

        // clear interrupt-on-change flag
        IOCCF6 = 0;
    } else if ((IOCCP7 == 1) && (IOCCF7 == 1)) {
        //@TODO Add handling code for IOC on pin RC7

        // clear interrupt-on-change flag
        IOCCF7 = 0;
    }
}
/**
 End of File
 */