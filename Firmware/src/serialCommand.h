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

#include "mcc_generated_files/eusart.h"


#define INPUT_COMMAND_BUFFER_SIZE 16

void COMM_Task(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SERIALCOMMAND_H */

