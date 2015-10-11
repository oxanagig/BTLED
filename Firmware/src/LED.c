#include <xc.h>
#include <stdint.h>
#include "LED.h"
#include "../BT_LED_strip.X/mcc_generated_files/mcc.h"

        LED_MODE  LED_mode = LED_OFF;
        LED_COLOR LED_SetColor = {0,0,0}; 
static  LED_COLOR LED_currentColor = {0,0,0};
const   LED_COLOR ledFullOn  = {20,20,20};
const   LED_COLOR ledFullOff = {0,0,0};
const   LED_COLOR ledRed     = {1,0,0};

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
        __delay_ms(50);
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
                for(uint16_t i=0;i<NUMBER_OF_LED;i++)
                {
                    ledSetColor(ledFullOff);
                }
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
                for(uint16_t i=0;i<NUMBER_OF_LED;i++)
                {
                    ledSetColor(LED_SetColor);
                }
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

inline void ledSetColor(LED_COLOR ledColor)
{
    ledSendByte(ledColor.Green);       //Green
    ledSendByte(ledColor.Red);         //Red
    ledSendByte(ledColor.Blue);        //Blue
}

void ledStripSetColor(LED_COLOR* ledColor, uint8_t numberOfLED)
{
    uint16_t    i;
    
    for(i=0;i<numberOfLED;i++)
    {
        if(sizeof(ledColor)<=sizeof(ledColor[0])*i)  // exit if the assigned color is less than expected
            break;
        ledSetColor(*(ledColor+i));
    }
}

//#define bit_banged_protocol

inline void ledSendByte(uint8_t data)
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
