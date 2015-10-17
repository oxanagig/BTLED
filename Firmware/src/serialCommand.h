/* 
 * File:   serialCommand.h
 * Author: c14652
 *
 * Created on February 2, 2015, 2:33 PM
 */

#ifndef SERIALCOMMAND_H
#define	SERIALCOMMAND_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../BT_LED_strip.X/mcc_generated_files/mcc.h"


#define INPUT_COMMAND_BUFFER_SIZE 16
#define COLOR_COMMAND_LENGTH      8    /* RRGGBB\r\n*/

void COMM_Task(void);

typedef enum
{
    COMM_IDEL,
    COMM_PROCESS_COMMAND,
    COMM_PROCESS_TRASH,
}COMM_RECEIVE_STATE;

typedef void(*functionPointerType)(char*);

struct commandStruct
{
    char const *name;
    uint8_t nameLength;
    functionPointerType execute;
    char const *helpMessage;
};

#ifdef	__cplusplus
}
#endif

#endif	/* SERIALCOMMAND_H */

