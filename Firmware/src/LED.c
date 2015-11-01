#include <xc.h>
#include <stdint.h>
#include "LED.h"
#include "SRAM.h"
#include "../BT_LED_strip.X/mcc_generated_files/mcc.h"


/* local variable*/
static  RGB_t   LED_currentColor = {0,0,0};
static  uint8_t currentLEDIndex;

/* global variable*/
LED_MODE  LED_mode;
RGB_t LED_SetColor = {0,0,0}; 

/* constant */
const   RGB_t ledFullOn  = {0xFF,0xFF,0xFF};
const   RGB_t ledFullOff = {0,0,0};

/* local functions*/
static void ledEnable(void);
static void ledDisable(void);
static inline void ledSendByte(uint8_t);
static inline void ledSendColor(uint8_t,uint8_t,uint8_t);
static RGB_t HsvToRgb(HSV_t);
static void LED_directColor(RGB_t);


void LED_Intialization(void)
{
    LED_mode = LED_OFF; 
    currentLEDIndex = 0;
    ledDisable();
}

uint8_t LED_getCurrentIndex(void)
{
    return currentLEDIndex;
}

void LED_Test(void)
{
    ledEnable();
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
    ledDisable();
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
                LED_directColor(ledFullOff);
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
                LED_directColor(LED_SetColor);
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

static void ledSetColor(RGB_t ledColor)
{
    currentLEDIndex++;
    if(currentLEDIndex<NUMBER_OF_LED)
    {
        SRAMWriteByte(ledColor.Green);
        SRAMWriteByte(ledColor.Red);
        SRAMWriteByte(ledColor.Blue);
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

static inline void ledSendColor(uint8_t red,uint8_t green,uint8_t blue)
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


static RGB_t HsvToRgb(HSV_t hsv)
{
    RGB_t rgb;
    unsigned char region, remainder, p, q, t;

    if (hsv.Saturation == 0)
    {
        rgb.Red = hsv.Value;
        rgb.Green = hsv.Value;
        rgb.Blue = hsv.Value;
        return rgb;
    }

    region = hsv.Hue / 43;
    remainder = (hsv.Hue - (region * 43)) * 6; 

    p = (hsv.Value * (255 - hsv.Saturation)) >> 8;
    q = (hsv.Value * (255 - ((hsv.Saturation * remainder) >> 8))) >> 8;
    t = (hsv.Value * (255 - ((hsv.Saturation * (255 - remainder)) >> 8))) >> 8;

    switch (region)
    {
        case 0:
            rgb.Red = hsv.Value; rgb.Green = t; rgb.Blue = p;
            break;
        case 1:
            rgb.Red = q; rgb.Green = hsv.Value; rgb.Blue = p;
            break;
        case 2:
            rgb.Red = p; rgb.Green = hsv.Value; rgb.Blue = t;
            break;
        case 3:
            rgb.Red = p; rgb.Green = q; rgb.Blue = hsv.Value;
            break;
        case 4:
            rgb.Red = t; rgb.Green = p; rgb.Blue = hsv.Value;
            break;
        default:
            rgb.Red = hsv.Value; rgb.Green = p; rgb.Blue = q;
            break;
    }

    return rgb;
}

static void SRAMtoLED(void)
{
    uint8_t data;
    while (SSP1STATbits.BF == SPI_RX_IN_PROGRESS);  /* wait the buffer to be filled with byte received from SRAM */
    data = SSP1BUF;                                 /* Get the last received byte in the SPI buffer, which came from SRAM */
    SSP1BUF = data;                                 /* transmit the byte from SRAM to SPI data line, which writes to LED and read a new byte from SRAM at the same time */
}

static void LED_Show()
{
    uint8_t i;
    SRAMStartRead(0x00);            /* Start address*/
    SPI_Exchange8bit(0X00);         /* Write a dummy byte to read out the first byte in SRAM */
    
    ledEnable();
    
    for(i=0;i<NUMBER_OF_LED;i++)
    {
        SRAMtoLED();
    }
    
    ledDisable();
}

//---------------------------------------LED Patterns-----------------------------------------
static void LED_directColor(RGB_t ledColor)
{
    SRAMStarWrite(0x00);
    uint8_t i;
    for(i=0;i<NUMBER_OF_LED;i++)
    {
        ledSetColor(ledColor);
    }
    deselectSRAM();
    LED_Show();
}

static void LED_party(void)
{
    SRAMStarWrite(0x00);
    uint8_t i;
    RGB_t ledRGB;
    
    SetRGB(ledRGB,20,40,50);
    for(i=0;i<NUMBER_OF_LED;i++)
    {
        ledSetColor(ledRGB);
    }
}