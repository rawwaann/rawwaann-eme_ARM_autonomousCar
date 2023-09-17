#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <MCAL/DIO.h>
#include <MCAL/GPTM.h>

/*******************************************************************************
 *                                extern variables                             *
 *******************************************************************************/
extern uint32 distance;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/***************************************************************************************************
* Function Name: ultrasonic_init
* Parameters (in): void
* Return value: void
* Description: ultrasonic initialization
****************************************************************************************************/
void ultrasonic_init(void);

/***************************************************************************************************
* Function Name: ultrasonicTrigger
* Parameters (in): void
* Return value: void
* Description: generating the trigger signal that is needed by the ultrasonic to send its echo signal
****************************************************************************************************/
void ultrasonicTrigger(void);


#endif /* HAL_ULTRASONIC_H_ */
