#include <xc.h>
#include <stdint.h>
#include "LED.h"
#include "SRAM.h"
#include "../BT_LED_strip.X/mcc_generated_files/mcc.h"


/* local variable*/
static  LED_COLOR LED_currentColor = {0,0,0};
static  uint8_t currentLEDIndex;

/* global variable*/
LED_MODE  LED_mode;
LED_COLOR LED_SetColor = {0,0,0}; 

/* constant */
const   LED_COLOR ledFullOn  = {0xFF,0xFF,0xFF};
const   LED_COLOR ledFullOff = {0,0,0};

/* local functions*/
static void ledEnable(void);
static void ledDisable(void);
static inline void ledSendByte(uint8_t);
static void ledSendColor(uint8_t,uint8_t,uint8_t);



void LED_Intialization(void)
{
    LED_mode = LED_OFF; 
    currentLEDIndex = 0;
}

uint8_t LED_getCurrentIndex(void)
{
    return currentLEDIndex;
}

void LED_Test(void)
{
    for(uint8_t i=0; i<NUMBER_OF_LED; i++)
    {
        for(uint8_t j=0;j<NUMBER_OF_LED;j++)
        {
            if(j==i)
            {
               ledSendByte(ledFullOn.Green);
               ledSendByte(ledFullOn.Red);
               ledSendByte(ledFullOn.Blue);
            }
            else
            {
               ledSendByte(ledFullOff.Green);
               ledSendByte(ledFullOff.Red);
               ledSendByte(ledFullOff.Blue);
            }
        }
        __delay_ms(100);
    }

}

static void LED_directColor(uint8_t red,uint8_t green,uint8_t blue)
{
    uint8_t i;
    for(i=0;i<NUMBER_OF_LED;i++)
    {
        ledSendColor(red,green,blue);
    }

}

void LED_Task(void)
{
    static uint8_t ledOFF = 0;
    switch(LED_mode)
    {
        case LED_OFF:
            if(ledOFF ==0)
            {
                GIE = 0;
                
                GIE = 1;
                ledOFF = 1;
            }
            break;
        case LED_DIRECT:
            if(LED_currentColor.Blue!=LED_SetColor.Blue 
            || LED_currentColor.Red!=LED_SetColor.Red
            || LED_currentColor.Green!=LED_SetColor.Green)
            {
                GIE = 0;
               
                GIE = 1;
                LED_currentColor = LED_SetColor;
                ledOFF = 0;
            }
            break;
        case LED_STARRY:
            ledOFF = 0;
            break;
        case LED_XMAS:
            ledOFF = 0;
            break;
        case LED_PARTY:
            ledOFF = 0;
            break;
        default:
            break;
    }
}

static void ledSetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    currentLEDIndex++;
    if(currentLEDIndex<NUMBER_OF_LED)
    {
        SRAMWriteByte(green);
        SRAMWriteByte(red);
        SRAMWriteByte(blue);
    }
    else
    {
        currentLEDIndex--;
    }
}

static void ledEnable(void)
{
    CLC4CONbits.LC4EN = 1;
}
static void ledDisable(void)
{
    CLC4CONbits.LC4EN = 0;
}

static void ledSendColor(uint8_t red,uint8_t green,uint8_t blue)
{
    ledSendByte(green);       //Green
    ledSendByte(red);         //Red
    ledSendByte(blue);        //Blue
}

static inline void ledSendByte(uint8_t data)
{
#if defined (bit_banged_protocol)
    #if defined(WS2811)
        for(uint8_t i = 0; i< 8;i++)
        {
            SCK = 0;
            SDO = (data & 0x80)>>7;     /* Transmit the MSB first*/
            data = data <<1;
            SCK = 1;
        }

        _delay(30);                     /* hold SCK high for 4us*/

        SCK = 0;

    #elif defined(WS2812)
        GIE = 0;
        for(uint8_t i = 0; i<8;i++)
        {
            if(data&0x80)
            {
                LED_DATA_SetHigh();
                NOP();
                NOP();
                LED_DATA_SetLow();
            }
            else
            {
                LED_DATA_SetHigh();
                NOP();
                LED_DATA_SetLow();
            }
            data = data<<1;
        }
        GIE= 1;
    #endif
#else
        SPI_Exchange8bit(data);
#endif
}
