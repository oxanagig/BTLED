#include <xc.h>
#include <string.h>
#include "serialCommand.h"
#include "LED.h"

static char inputCommand[INPUT_COMMAND_BUFFER_SIZE];

/*Predefined Command*/
const char const CMD_SET_OFF[]     = "SetLED Off\r\n";
const char const CMD_SET_STARRY[]  = "SetLED STARRY\r\n";
const char const CMD_SET_XMAS[]    = "SetLED XMAS\r\n";
const char const CMD_SET_PARTY[]   = "SetLED PARTY\r\n";
const char const CMD_SET_DIRECT[]  = "SetLED DIRECT ";

const char const CMD_GET_STATE[]   = "GetLEDState\r\n";

const char const CMD_TEST_LED[]    = "TEST LED\r\n";
const char const CMD_TEST_SRAM[]   = "TEST SRAM\r\n";


/*local function*/
static uint8_t command_GetMinimumNameLength(const struct commandStruct*);
static uint8_t command_GetnumberofCommands(const struct commandStruct*);
static void setCommandProcess(char*);
static void getCommandProcess(char*);
static void testCommandProcess(char*);
static uint8_t oneByte_HexSrtingToBinary(char*);


const struct commandStruct const commands[]=
{
    {"SetLED",6,&setCommandProcess, "Set LED Mode: Off,DIRECT,STARRY,XMAS,PARTY.\r\n"},
    {"GetLED",6,&getCommandProcess, "Get the current LED status.\r\n"},
    {"Test",  4,&testCommandProcess,"System self-test:LED, SRAM, ALL\r\n" },
    {"",0,0,""}
};

static uint8_t command_GetMinimumNameLength(const struct commandStruct* commandArray)
{
    static uint8_t minimumNameLength = 0;
    uint8_t i = 0;
    
    if(minimumNameLength==0)
    {
        while(commandArray[i].nameLength !=0)
        {
            if(commandArray[i].nameLength>minimumNameLength)
                minimumNameLength = commandArray[i].nameLength;
            i++;
        }
    }
    return minimumNameLength;
}

static uint8_t command_GetnumberofCommands(const struct commandStruct* commandArray)
{
    static uint8_t numberofCommands = 0;
    uint8_t i = 0;
    
    if(numberofCommands==0)
    {
        while(commandArray[i].nameLength !=0)
        {
            i++;
        }
        numberofCommands = i;
    }
    return numberofCommands;
}

static void setCommandProcess(char* input)
{
    if(strcmp(CMD_SET_OFF,input)==0)
    {
        LED_mode = LED_OFF;
        printf("DONE!\r\n");
    }
    else if(strcmp(CMD_SET_STARRY,input)==0)
    {
        LED_mode = LED_STARRY;
        printf("DONE!\r\n");
    }
    else if(strcmp(CMD_SET_XMAS,input)==0)
    {
        LED_mode = LED_XMAS;
        printf("DONE!\r\n");
    }
    else if(strcmp(CMD_SET_PARTY,input)==0)
    {
        LED_mode = LED_PARTY;
        printf("DONE!\r\n");
    }
    else if(strncmp(CMD_SET_DIRECT,input,strlen(CMD_SET_DIRECT))==0)
    {
        input = input + strlen(CMD_SET_DIRECT);         /* Extract the color information form the command*/
        
        if(strlen(input) == COLOR_COMMAND_LENGTH)
        {
            LED_SetColor.Red   = oneByte_HexSrtingToBinary(input);
            LED_SetColor.Green = oneByte_HexSrtingToBinary(input+2);
            LED_SetColor.Blue  = oneByte_HexSrtingToBinary(input+4);
            printf("DONE!\r\n");     
            LED_mode = LED_DIRECT;
        }
        else
        {
            printf("Invalid Command \r\n");   
        }
    }
    else
    {
        printf("Invalid Command \r\n");
    }
}


static void getCommandProcess(char* input)
{
    if(strcmp(CMD_GET_STATE,input)==0)
    {
        switch(LED_mode)
        {
            case LED_OFF:
                printf("LED is OFF\r\n");
                break;
            case LED_DIRECT:
                printf("Direct color\r\n");
                break;
            case LED_STARRY:
                printf("Starry\r\n");
                break;
            case LED_XMAS:
                printf("Xmas\r\n");
                break;
            case LED_PARTY:
                printf("Party\r\n");
                break;
            default:
                printf("ERROR\r\n");
                break;
        }
    }
    else
    {
        printf("Invalid Command \r\n");
    }
}

static void testCommandProcess(char* input)
{
    if(strcmp(CMD_TEST_LED,input)==0)
    {
        LED_Test();
    }
    else if(strcmp(CMD_TEST_SRAM,input)==0)
    {
        //
    }
    else
    {
        printf("Invalid Command \r\n");
    }
}

static uint8_t oneByte_HexSrtingToBinary(char* data)
{
    for(uint8_t i=0; i<2; i++)
    {
        if(data[i]>='0' && data[i]<='9')      /*if it is 0-9*/
        {
            data[i] = data[i]-'0';
        }
        else if(data[i]>='A' && data[i]<='F')
        {
            data[i] = data[i] -'A' +10;      /*if it is A-F*/
        }
        else if(data[i]>='a' && data[i]<='f')
        {
            data[i] = data[i] -'a' +10;      /*if it is a-f*/
        }
        else
        {
            data[i] = 0;
        }
    }
    return ((uint8_t)(data[0]<<4)+(uint8_t)data[1]);
}

void COMM_Task(void)
{
    uint8_t receiveData;
    static COMM_RECEIVE_STATE UART_ReceiveState = COMM_IDEL;
    static uint8_t receiveCounter;

    if(EUSART_DataReady)
    {
        receiveData = EUSART_Read();      /* Receive Character from UART  */
        //EUSART_Write(receiveData);      /* echo back character on TX line*/

        /* command process state machine*/
        switch(UART_ReceiveState)
        {
            case COMM_IDEL:
                memset(inputCommand,0,INPUT_COMMAND_BUFFER_SIZE);   /* clear command buffer*/

                if(receiveData == 'S' || receiveData == 'G' ||receiveData == 'T')
                {
                    UART_ReceiveState = COMM_PROCESS_COMMAND;
                    inputCommand[0] = receiveData;
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
            case COMM_PROCESS_COMMAND:
                inputCommand[++receiveCounter] = receiveData;
                if(receiveData == '\n')
                {
                    uint8_t i = 0;
                    do
                    {
                        if(strncmp(inputCommand,commands[i].name,commands[i].nameLength)>=0)
                        {
                            commands[i].execute(inputCommand);              /*execute the receiver of matching command*/
                            break;
                        }
                        i++;
                    }while(commands[i].nameLength!=0);
                    if(i>=command_GetnumberofCommands(&commands))
                        printf("Invalid Command \r\n");
                    UART_ReceiveState = COMM_IDEL;
                }
                else if(receiveCounter>=INPUT_COMMAND_BUFFER_SIZE-1)
                {
                    UART_ReceiveState = COMM_PROCESS_TRASH;
                }
                break;
            case COMM_PROCESS_TRASH:
                if(receiveData == '\n')
                {
                    UART_ReceiveState = COMM_IDEL;
                    printf("Invalid Command \r\n");
                }
                break;
            default:UART_ReceiveState = COMM_IDEL;
        }

    }
}