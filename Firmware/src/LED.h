/* 
 * File:   LED.h
 * Author: c14652
 *
 * Created on January 23, 2015, 6:50 PM
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif


#define WS2812
#define NUMBER_OF_LED       20


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
}LED_COLOR;

extern LED_MODE LED_mode;
extern LED_COLOR LED_SetColor;    
    

void LED_Test(void);
void LED_Task(void);
void ledSendByte(uint8_t);
void ledSetColor(LED_COLOR);
void ledStripSetColor(LED_COLOR*, uint8_t);


#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

