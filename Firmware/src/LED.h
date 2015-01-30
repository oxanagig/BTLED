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


void LED_Task(void);
void ledSendByte(uint8_t);

typedef enum
{
    LED_OFF,
    LED_DIRECT,
    LED_STARRY,
    LED_XMAS,
    LED_PARTY,
}LED_MODE;

extern LED_MODE LED_mode;
extern uint8_t LED_color[3];

#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

