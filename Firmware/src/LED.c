#include <xc.h>
#include <stdint.h>
#include "LED.h"
#include "mcc_generated_files/pin_manager.h"

        LED_MODE LED_mode = LED_OFF;
        uint8_t  LED_color[3]={0,0,0}; 
static  uint8_t  LED_currentColor[3]={0,0,0};

void LED_Task()
{
    static uint8_t ledOFF;
    switch(LED_mode)
    {
        case LED_OFF:
            if(ledOFF ==0)
            {
                GIE = 0;
                for(uint16_t i=0;i<NUMBER_OF_LED;i++)
                {
                    ledSendByte(0);        //Green
                    ledSendByte(0);        //Red
                    ledSendByte(0);        //Blue
                }
                GIE = 1;
                ledOFF = 1;
            }
            break;
        case LED_DIRECT:
            if(LED_color[0]!=LED_currentColor[0]||\
               LED_color[1]!=LED_currentColor[1]||\
               LED_color[2]!=LED_currentColor[2])
            {
                GIE = 0;
                for(uint16_t i=0;i<NUMBER_OF_LED;i++)
                {
                    ledSendByte(LED_color[0]);        //Green
                    ledSendByte(LED_color[1]);        //Red
                    ledSendByte(LED_color[2]);        //Blue
                }
                GIE = 1;
                for(uint8_t i=0;i<3;i++)
                    LED_currentColor[i] = LED_color[i];
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

void ledSendByte(uint8_t data)
{

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
    #endif
}
