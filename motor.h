#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

typedef enum
{
	/* Application's state machine's initial state. */
	MOTOR_STATE_INIT=0,
	MOTOR_STATE_SERVICE_TASKS,
            
    Motor_Test_1,

} MOTOR_STATES;

typedef struct
{
    /* The application's current state */
    MOTOR_STATES state;
    QueueHandle_t myQueue;
    /* TODO: Define any additional data used by the application. */
    char message[2];
    char type;
    
    uint8_t data; //direction data
    
} MOTOR_DATA;
//this is the global struct to add to motor queue
MOTOR_DATA motorsData;


void MOTOR_Initialize ( void );
void MOTOR_Tasks( void );

void MOTORS_Initialize (void);
void MOTORS_Tasks (void);
void processMotorCommands(void);
void AssembleMotorCommands(char letter);

#endif /* _MOTOR_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

