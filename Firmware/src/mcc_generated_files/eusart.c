/**
  EUSART Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart.c

  @Summary
    This is the generated driver implementation file for the EUSART driver using MPLAB® Code Configurator

  @Description
    This header file provides implementations for driver APIs for EUSART.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.10
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

#include "eusart.h"
#include "string.h"
#include "../LED.h"

/**
  Section: Macro Declarations
*/
#define EUSART_TX_BUFFER_SIZE 8
#define EUSART_RX_BUFFER_SIZE 16
#define INPUT_COMMAND_BUFFER_SIZE 16

/**
  Section: Global Variables
*/

static uint8_t eusartTxHead = 0;
static uint8_t eusartTxTail = 0;
static uint8_t eusartTxBuffer[EUSART_TX_BUFFER_SIZE];
volatile uint8_t eusartTxBufferRemaining;

static uint8_t eusartRxHead = 0;
static uint8_t eusartRxTail = 0;
static uint8_t eusartRxBuffer[EUSART_RX_BUFFER_SIZE];
volatile uint8_t eusartRxCount;

typedef enum
{
    UART_IDEL,
    UART_PROCESS_SET_COMMAND,
    UART_PROCESS_GET_COMMAND,
    UART_PROCESS_COLOR,
    UART_PROCESS_TRASH,
}UART_RECEIVE_STATE;

static uint8_t inputCommand[INPUT_COMMAND_BUFFER_SIZE];

/*Predefined Command*/
const uint8_t CMD_SET_OFF[]="SetLED Off\r\n";
const uint8_t CMD_SET_DIRECT[]="SetLED DIRECT\r\n";
const uint8_t CMD_SET_STARRY[]="SetLED STARRY\r\n";
const uint8_t CMD_SET_XMAS[]="SetLED XMAS\r\n";
const uint8_t CMD_SET_PARTY[]="SetLED PARTY\r\n";

const uint8_t CMD_GET_STATE[]="GetLEDState\r\n";

/**
  Section: EUSART APIs
*/

void EUSART_Initialize(void)
{
    // disable interrupts before changing states
    PIE1bits.RCIE = 0;
    PIE1bits.TXIE = 0;

    // Set the EUSART module to the options selected in the user interface.

    // ABDEN disabled; WUE disabled; RCIDL idle; ABDOVF no_overflow; SCKP async_noninverted_sync_fallingedge; BRG16 16bit_generator;
    BAUDCON = 0x48;

    // ADDEN disabled; RX9 8-bit; RX9D 0x0; FERR no_error; CREN enabled; SPEN enabled; SREN disabled; OERR no_error;
    RCSTA = 0x90;

    // CSRC slave_mode; TRMT TSR_empty; TXEN enabled; BRGH hi_speed; SYNC asynchronous; SENDB sync_break_complete; TX9D 0x0; TX9 8-bit;
    TXSTA = 0x26;

    // Baud Rate = 115200;
    SPBRGL = 0x44;

    // Baud Rate = 115200; SP1BRGH 0;
    SPBRGH = 0x00;


    // initializing the driver state
    eusartTxHead = 0;
    eusartTxTail = 0;
    eusartTxBufferRemaining = sizeof(eusartTxBuffer);

    eusartRxHead = 0;
    eusartRxTail = 0;
    eusartRxCount = 0;

    // enable receive interrupt
    PIE1bits.RCIE = 1;
}

uint8_t EUSART_Read(void)
{
    uint8_t readValue  = 0;

    while(0 == eusartRxCount)
    {
    }

    PIE1bits.RCIE = 0;

    readValue = eusartRxBuffer[eusartRxTail++];
    if(sizeof(eusartRxBuffer) <= eusartRxTail)
    {
        eusartRxTail = 0;
    }
    eusartRxCount--;
    PIE1bits.RCIE = 1;

    return readValue;
}

void EUSART_Write(uint8_t txData)
{
    while(0 == eusartTxBufferRemaining)
    {
    }

    if(0 == PIE1bits.TXIE)
    {
        TXREG = txData;
    }
    else
    {
        PIE1bits.TXIE = 0;
        eusartTxBuffer[eusartTxHead++] = txData;
        if(sizeof(eusartTxBuffer) <= eusartTxHead)
        {
            eusartTxHead = 0;
        }
        eusartTxBufferRemaining--;
    }
    PIE1bits.TXIE = 1;
}

char getch(void)
{
    return EUSART_Read();
}

void putch(char txData)
{
    EUSART_Write(txData);
}

void EUSART_Transmit_ISR(void)
{

    // add your EUSART interrupt custom code
    if(sizeof(eusartTxBuffer) > eusartTxBufferRemaining)
    {
        TXREG = eusartTxBuffer[eusartTxTail++];
        if(sizeof(eusartTxBuffer) <= eusartTxTail)
        {
            eusartTxTail = 0;
        }
        eusartTxBufferRemaining++;
    }
    else
    {
        PIE1bits.TXIE = 0;
    }
}

void EUSART_Receive_ISR(void)
{
    if(1 == RCSTAbits.OERR)
    {
        // EUSART error - restart

        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
    }

    // buffer overruns are ignored
    eusartRxBuffer[eusartRxHead++] = RCREG;
    if(sizeof(eusartRxBuffer) <= eusartRxHead)
    {
        eusartRxHead = 0;
    }
    eusartRxCount++;
}

void outputString(const uint8_t *string)
{
    for(uint8_t i =0;i<strlen(string);i++)
    {
        EUSART_Write(string[i]);
    }
}

uint8_t UART_HexSrtingToBinary(uint8_t *data)
{
    for(uint8_t i=0; i<2; i++)
    {
        if(data[i]>=0x30 && data[i]<=0x39)      /*if it is 0-9*/
        {
            data[i] = data[i]-0x30;
        }
        else
        {
            data[i] = data[i] -0x41 +0x0A;      /*if it is A-F*/
        }
    }
    return ((data[0]<<4)+data[1]);

}

void UART_Task(void)
{
    uint8_t receiveData;
    static UART_RECEIVE_STATE UART_ReceiveState = UART_IDEL;
    static uint8_t receiveCounter;

    if(EUSART_DataReady)
    {
        receiveData = EUSART_Read();    /* Receive Character from Uart*/
        EUSART_Write(receiveData);      /* echo back character on TX line*/

        /* command process state machine*/
        switch(UART_ReceiveState)
        {
            case UART_IDEL:
                memset(inputCommand,0,INPUT_COMMAND_BUFFER_SIZE);   /* clear command buffer*/

                if(receiveData == 'S')
                {
                    UART_ReceiveState = UART_PROCESS_SET_COMMAND;
                    inputCommand[0] = 'S';
                    receiveCounter = 0;
                }
                else if(receiveData == 'G')
                {
                    UART_ReceiveState = UART_PROCESS_GET_COMMAND;
                    inputCommand[0] = 'G';
                    receiveCounter = 0;
                }
                else if (receiveData == 'C')
                {
                    UART_ReceiveState = UART_PROCESS_COLOR;
                    inputCommand[0] = 'C';
                    receiveCounter = 0;
                }
                else if (receiveData == '\r'||receiveData =='\n')
                {
                    //skip
                }
                else
                {
                    UART_ReceiveState = UART_PROCESS_TRASH;
                }
                break;
            case UART_PROCESS_GET_COMMAND:
                inputCommand[++receiveCounter] = receiveData;
                if(receiveData == '\n')
                {
                    if(strcmp(CMD_GET_STATE,inputCommand)==0)
                    {
                        switch(LED_mode)
                        {
                            case LED_OFF:
                                outputString("LED is OFF\r\n");
                                break;
                            case LED_DIRECT:
                                outputString("Direct color\r\n");
                                break;
                            case LED_STARRY:
                                outputString("Starry\r\n");
                                break;
                            case LED_XMAS:
                                outputString("Xmas\r\n");
                                break;
                            case LED_PARTY:
                                outputString("Party\r\n");
                                break;
                            default:
                                outputString("ERROR\r\n");
                                break;
                        }
                    }
                    else
                    {
                        outputString("Invalid Command \r\n");
                    }
                    UART_ReceiveState = UART_IDEL;
                }
                break;
            case UART_PROCESS_SET_COMMAND:
                inputCommand[++receiveCounter] = receiveData;
                if(receiveData == '\n')
                {
                    if(strcmp(CMD_SET_OFF,inputCommand)==0)
                    {
                        LED_mode = LED_OFF;
                        outputString("DONE!\r\n");
                    }
                    else if(strcmp(CMD_SET_DIRECT,inputCommand)==0)
                    {
                        LED_mode = LED_DIRECT;
                        outputString("DONE!\r\n");
                    }
                    else if(strcmp(CMD_SET_STARRY,inputCommand)==0)
                    {
                        LED_mode = LED_STARRY;
                        outputString("DONE!\r\n");
                    }
                    else if(strcmp(CMD_SET_XMAS,inputCommand)==0)
                    {
                        LED_mode = LED_XMAS;
                        outputString("DONE!\r\n");
                    }
                    else if(strcmp(CMD_SET_PARTY,inputCommand)==0)
                    {
                        LED_mode = LED_PARTY;
                        outputString("DONE!\r\n");
                    } 
                    else
                    {
                        outputString("Invalid Command \r\n");
                    }
                    UART_ReceiveState = UART_IDEL;

                }
                break;
            case UART_PROCESS_COLOR:
                inputCommand[++receiveCounter] = receiveData;
                   if(receiveCounter == 2)
                   {
                        UART_HexSrtingToBinary(inputCommand);

                   }
            case UART_PROCESS_TRASH:
                if(receiveData == '\n')
                {
                    UART_ReceiveState = UART_IDEL;
                    outputString("Invalid Command \r\n");
                }
                break;
            default:UART_ReceiveState = UART_IDEL;
        }

    }
}
/**
  End of File
*/
