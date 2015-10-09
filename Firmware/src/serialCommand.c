#include <xc.h>
#include <string.h>
#include "serialCommand.h"
#include "LED.h"

typedef enum
{
    COMM_IDEL,
    COMM_PROCESS_SET_COMMAND,
    COMM_PROCESS_GET_COMMAND,
    COMM_PROCESS_COLOR,
    COMM_PROCESS_TRASH,
}COMM_RECEIVE_STATE;

static uint8_t inputCommand[INPUT_COMMAND_BUFFER_SIZE];

/*Predefined Command*/
const uint8_t CMD_SET_OFF[]="SetLED Off\r\n";
const uint8_t CMD_SET_DIRECT[]="SetLED DIRECT\r\n";
const uint8_t CMD_SET_STARRY[]="SetLED STARRY\r\n";
const uint8_t CMD_SET_XMAS[]="SetLED XMAS\r\n";
const uint8_t CMD_SET_PARTY[]="SetLED PARTY\r\n";

const uint8_t CMD_GET_STATE[]="GetLEDState\r\n";


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

void COMM_Task(void)
{
    uint8_t receiveData,r,g,b;
    static COMM_RECEIVE_STATE UART_ReceiveState = COMM_IDEL;
    static uint8_t receiveCounter;

    if(EUSART_DataReady)
    {
        receiveData = EUSART_Read();    /* Receive Character from Uart*/
        //EUSART_Write(receiveData);      /* echo back character on TX line*/

        /* command process state machine*/
        switch(UART_ReceiveState)
        {
            case COMM_IDEL:
                memset(inputCommand,0,INPUT_COMMAND_BUFFER_SIZE);   /* clear command buffer*/

                if(receiveData == 'S')
                {
                    UART_ReceiveState = COMM_PROCESS_SET_COMMAND;
                    inputCommand[0] = 'S';
                    receiveCounter = 0;
                }
                else if(receiveData == 'G')
                {
                    UART_ReceiveState = COMM_PROCESS_GET_COMMAND;
                    inputCommand[0] = 'G';
                    receiveCounter = 0;
                }
                else if (receiveData == 'C')
                {
                    UART_ReceiveState = COMM_PROCESS_COLOR;
                    receiveCounter = 0;
                }
                else if (receiveData == '\r'||receiveData =='\n')
                {
                    //skip
                }
                else
                {
                    UART_ReceiveState = COMM_PROCESS_TRASH;
                }
                break;
            case COMM_PROCESS_GET_COMMAND:
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
                    UART_ReceiveState = COMM_IDEL;
                }
                break;
            case COMM_PROCESS_SET_COMMAND:
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
                        LED_SetColor.Green = 64;
                        LED_SetColor.Red = 64;
                        LED_SetColor.Blue = 64;
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
                    UART_ReceiveState = COMM_IDEL;

                }
                break;
            case COMM_PROCESS_COLOR:
                inputCommand[receiveCounter++] = receiveData;
                if(receiveCounter == 2)
                {
                   r = UART_HexSrtingToBinary(inputCommand);
                }
                else if(receiveCounter == 4)
                {
                   g = UART_HexSrtingToBinary(inputCommand+2);
                }
                else if(receiveCounter == 6)
                {
                   b = UART_HexSrtingToBinary(inputCommand+4);
                }
                if(receiveData =='\n') 
                {
                    if(receiveCounter == 8)
                    {
                        LED_SetColor.Green = g;
                        LED_SetColor.Red   = r;
                        LED_SetColor.Blue  = b;
                        outputString("DONE!\r\n");
                    }
                    else
                    {    
                        outputString("Invalid Command \r\n");
                    }
                    UART_ReceiveState = COMM_IDEL;
                }
                break;
            case COMM_PROCESS_TRASH:
                if(receiveData == '\n')
                {
                    UART_ReceiveState = COMM_IDEL;
                    outputString("Invalid Command \r\n");
                }
                break;
            default:UART_ReceiveState = COMM_IDEL;
        }

    }
}