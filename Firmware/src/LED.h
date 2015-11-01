/* 
 * File:   LED.h
 * Author: c14652
 *
 * Created on January 23, 2015, 6:50 PM
 */

#ifndef LED_H
#define	LED_H

#define WS2812
#define NUMBER_OF_LED       6


typedef enum
{
    LED_OFF,
    LED_DIRECT,
    LED_STARRY,
    LED_XMAS,
    LED_PARTY,
}LED_MODE;

typedef struct
{
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
}RGB_t;

typedef struct
{
    uint8_t Hue;
    uint8_t Saturation;
    uint8_t Value;
}HSV_t;

extern LED_MODE LED_mode;
extern RGB_t LED_SetColor;    
    

void LED_Test(void);
void LED_Task(void);


#define SetRGB(RGB_color,red,green,blue)    RGB_color.Red = red; RGB_color.Green = green; RGB_color.Blue = blue
#define SetHSV(HSV_color,hue,saturation,value)    RGB_color.Hue = hue; RGB_color.Saturation = satruation; RGB_color.Value = value

#define LED_DATA_SetHigh() LATA5 = 1
#define LED_DATA_SetLow()  LATA5 = 0 
#define SPI_RX_IN_PROGRESS 0x00


#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

