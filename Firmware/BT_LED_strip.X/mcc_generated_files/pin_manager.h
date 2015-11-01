/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC16F1619
        Version           :  1.01
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PWM4 aliases
#define PWM4_TRIS               TRISA1
#define PWM4_LAT                LATA1
#define PWM4_PORT               RA1
#define PWM4_ANS                ANSA1
#define PWM4_SetHigh()    do { LATA1 = 1; } while(0)
#define PWM4_SetLow()   do { LATA1 = 0; } while(0)
#define PWM4_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define PWM4_GetValue()         RA1
#define PWM4_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define PWM4_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define PWM4_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define PWM4_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set RX aliases
#define RX_TRIS               TRISA2
#define RX_LAT                LATA2
#define RX_PORT               RA2
#define RX_ANS                ANSA2
#define RX_SetHigh()    do { LATA2 = 1; } while(0)
#define RX_SetLow()   do { LATA2 = 0; } while(0)
#define RX_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define RX_GetValue()         RA2
#define RX_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define RX_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define RX_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set Photoresistor aliases
#define Photoresistor_TRIS               TRISA4
#define Photoresistor_LAT                LATA4
#define Photoresistor_PORT               RA4
#define Photoresistor_ANS                ANSA4
#define Photoresistor_SetHigh()    do { LATA4 = 1; } while(0)
#define Photoresistor_SetLow()   do { LATA4 = 0; } while(0)
#define Photoresistor_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define Photoresistor_GetValue()         RA4
#define Photoresistor_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define Photoresistor_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define Photoresistor_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define Photoresistor_SetDigitalMode()   do { ANSA4 = 0; } while(0)
// get/set CLC4OUT aliases
#define CLC4OUT_TRIS               TRISA5
#define CLC4OUT_LAT                LATA5
#define CLC4OUT_PORT               RA5
#define CLC4OUT_SetHigh()    do { LATA5 = 1; } while(0)
#define CLC4OUT_SetLow()   do { LATA5 = 0; } while(0)
#define CLC4OUT_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define CLC4OUT_GetValue()         RA5
#define CLC4OUT_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define CLC4OUT_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS               TRISB4
#define SDO_LAT                LATB4
#define SDO_PORT               RB4
#define SDO_ANS                ANSB4
#define SDO_SetHigh()    do { LATB4 = 1; } while(0)
#define SDO_SetLow()   do { LATB4 = 0; } while(0)
#define SDO_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define SDO_GetValue()         RB4
#define SDO_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define SDO_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define SDO_SetDigitalMode()   do { ANSB4 = 0; } while(0)
// get/set nCS aliases
#define nCS_TRIS               TRISB5
#define nCS_LAT                LATB5
#define nCS_PORT               RB5
#define nCS_ANS                ANSB5
#define nCS_SetHigh()    do { LATB5 = 1; } while(0)
#define nCS_SetLow()   do { LATB5 = 0; } while(0)
#define nCS_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define nCS_GetValue()         RB5
#define nCS_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define nCS_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define nCS_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define nCS_SetDigitalMode()   do { ANSB5 = 0; } while(0)
// get/set motionDetect aliases
#define motionDetect_TRIS               TRISB6
#define motionDetect_LAT                LATB6
#define motionDetect_PORT               RB6
#define motionDetect_WPU                WPUB6
#define motionDetect_SetHigh()    do { LATB6 = 1; } while(0)
#define motionDetect_SetLow()   do { LATB6 = 0; } while(0)
#define motionDetect_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define motionDetect_GetValue()         RB6
#define motionDetect_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define motionDetect_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define motionDetect_SetPullup()    do { WPUB6 = 1; } while(0)
#define motionDetect_ResetPullup()   do { WPUB6 = 0; } while(0)
// get/set gesturePort5 aliases
#define gesturePort5_TRIS               TRISB7
#define gesturePort5_LAT                LATB7
#define gesturePort5_PORT               RB7
#define gesturePort5_WPU                WPUB7
#define gesturePort5_SetHigh()    do { LATB7 = 1; } while(0)
#define gesturePort5_SetLow()   do { LATB7 = 0; } while(0)
#define gesturePort5_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define gesturePort5_GetValue()         RB7
#define gesturePort5_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define gesturePort5_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define gesturePort5_SetPullup()    do { WPUB7 = 1; } while(0)
#define gesturePort5_ResetPullup()   do { WPUB7 = 0; } while(0)
// get/set TX aliases
#define TX_TRIS               TRISC0
#define TX_LAT                LATC0
#define TX_PORT               RC0
#define TX_ANS                ANSC0
#define TX_SetHigh()    do { LATC0 = 1; } while(0)
#define TX_SetLow()   do { LATC0 = 0; } while(0)
#define TX_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define TX_GetValue()         RC0
#define TX_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

#define TX_SetAnalogMode()   do { ANSC0 = 1; } while(0)
#define TX_SetDigitalMode()   do { ANSC0 = 0; } while(0)
// get/set SCK aliases
#define SCK_TRIS               TRISC1
#define SCK_LAT                LATC1
#define SCK_PORT               RC1
#define SCK_ANS                ANSC1
#define SCK_SetHigh()    do { LATC1 = 1; } while(0)
#define SCK_SetLow()   do { LATC1 = 0; } while(0)
#define SCK_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define SCK_GetValue()         RC1
#define SCK_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define SCK_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define SCK_SetDigitalMode()   do { ANSC1 = 0; } while(0)
// get/set SDI aliases
#define SDI_TRIS               TRISC2
#define SDI_LAT                LATC2
#define SDI_PORT               RC2
#define SDI_ANS                ANSC2
#define SDI_SetHigh()    do { LATC2 = 1; } while(0)
#define SDI_SetLow()   do { LATC2 = 0; } while(0)
#define SDI_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define SDI_GetValue()         RC2
#define SDI_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define SDI_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define SDI_SetDigitalMode()   do { ANSC2 = 0; } while(0)
// get/set gesturePort2 aliases
#define gesturePort2_TRIS               TRISC3
#define gesturePort2_LAT                LATC3
#define gesturePort2_PORT               RC3
#define gesturePort2_ANS                ANSC3
#define gesturePort2_SetHigh()    do { LATC3 = 1; } while(0)
#define gesturePort2_SetLow()   do { LATC3 = 0; } while(0)
#define gesturePort2_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define gesturePort2_GetValue()         RC3
#define gesturePort2_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define gesturePort2_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

#define gesturePort2_SetAnalogMode()   do { ANSC3 = 1; } while(0)
#define gesturePort2_SetDigitalMode()   do { ANSC3 = 0; } while(0)
// get/set gesturePort1 aliases
#define gesturePort1_TRIS               TRISC4
#define gesturePort1_LAT                LATC4
#define gesturePort1_PORT               RC4
#define gesturePort1_WPU                WPUC4
#define gesturePort1_SetHigh()    do { LATC4 = 1; } while(0)
#define gesturePort1_SetLow()   do { LATC4 = 0; } while(0)
#define gesturePort1_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define gesturePort1_GetValue()         RC4
#define gesturePort1_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define gesturePort1_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

#define gesturePort1_SetPullup()    do { WPUC4 = 1; } while(0)
#define gesturePort1_ResetPullup()   do { WPUC4 = 0; } while(0)
// get/set gesturePort0 aliases
#define gesturePort0_TRIS               TRISC5
#define gesturePort0_LAT                LATC5
#define gesturePort0_PORT               RC5
#define gesturePort0_WPU                WPUC5
#define gesturePort0_SetHigh()    do { LATC5 = 1; } while(0)
#define gesturePort0_SetLow()   do { LATC5 = 0; } while(0)
#define gesturePort0_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define gesturePort0_GetValue()         RC5
#define gesturePort0_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define gesturePort0_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define gesturePort0_SetPullup()    do { WPUC5 = 1; } while(0)
#define gesturePort0_ResetPullup()   do { WPUC5 = 0; } while(0)
// get/set gesturePort3 aliases
#define gesturePort3_TRIS               TRISC6
#define gesturePort3_LAT                LATC6
#define gesturePort3_PORT               RC6
#define gesturePort3_ANS                ANSC6
#define gesturePort3_SetHigh()    do { LATC6 = 1; } while(0)
#define gesturePort3_SetLow()   do { LATC6 = 0; } while(0)
#define gesturePort3_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define gesturePort3_GetValue()         RC6
#define gesturePort3_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define gesturePort3_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define gesturePort3_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define gesturePort3_SetDigitalMode()   do { ANSC6 = 0; } while(0)
// get/set gesturePort4 aliases
#define gesturePort4_TRIS               TRISC7
#define gesturePort4_LAT                LATC7
#define gesturePort4_PORT               RC7
#define gesturePort4_ANS                ANSC7
#define gesturePort4_SetHigh()    do { LATC7 = 1; } while(0)
#define gesturePort4_SetLow()   do { LATC7 = 0; } while(0)
#define gesturePort4_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define gesturePort4_GetValue()         RC7
#define gesturePort4_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define gesturePort4_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

#define gesturePort4_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define gesturePort4_SetDigitalMode()   do { ANSC7 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */