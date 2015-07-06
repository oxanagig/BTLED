/**
  CLC4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    clc4.c

  @Summary
    This is the generated driver implementation file for the CLC4 driver using MPLAB® Code Configurator

  @Description
    This source file provides implementations for driver APIs for CLC4.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC16F1619
        Driver Version    :  2.00
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

/**
  Section: Included Files
 */

#include <xc.h>
#include "clc4.h"

/**
  Section: CLC4 APIs
 */

void CLC4_Initialize(void) {
    // Set the CLC4 to the options selected in the User Interface

    // LC4G1POL not_inverted; LC4POL not_inverted; LC4G4POL not_inverted; LC4G2POL inverted; LC4G3POL not_inverted; 
    CLC4POL = 0x02;

    // LC4D1S FOSC; 
    CLC4SEL0 = 0x21;

    // LC4D2S LC2_out; 
    CLC4SEL1 = 0x05;

    // LC4D3S SDO from MSSP; 
    CLC4SEL2 = 0x28;

    // LC4D4S SCK from MSSP; 
    CLC4SEL3 = 0x27;

    // LC4G1D3N disabled; LC4G1D2N disabled; LC4G1D4T disabled; LC4G1D2T disabled; LC4G1D3T disabled; LC4G1D4N disabled; LC4G1D1T enabled; LC4G1D1N disabled; 
    CLC4GLS0 = 0x02;

    // LC4G2D2T disabled; LC4G2D1T disabled; LC4G2D1N disabled; LC4G2D4N disabled; LC4G2D2N enabled; LC4G2D3N disabled; LC4G2D3T enabled; LC4G2D4T enabled; 
    CLC4GLS1 = 0xA4;

    // LC4G3D3N disabled; LC4G3D2N disabled; LC4G3D4T disabled; LC4G3D2T disabled; LC4G3D1N disabled; LC4G3D3T disabled; LC4G3D4N disabled; LC4G3D1T disabled; 
    CLC4GLS2 = 0x00;

    // LC4G4D3N enabled; LC4G4D4N disabled; LC4G4D2N disabled; LC4G4D1N disabled; LC4G4D1T disabled; LC4G4D4T enabled; LC4G4D3T disabled; LC4G4D2T disabled; 
    CLC4GLS3 = 0x90;

    // LC4EN enabled; INTN disabled; INTP disabled; MODE 2-input D flip-flop with R; LC4OUT disabled; 
    CLC4CON = 0x85;

}

bool CLC4_OutputStatusGet(void) {
    return (CLC4CONbits.LC4OUT);

}
/**
 End of File
 */