
#ifndef MCAL_SYSTICK_H_
#define MCAL_SYSTICK_H_

/************************************************************************************************
 *                                includes                                                      *
 ************************************************************************************************/
#include "Tiva_Registers.h"
#include <Utilities/std_types.h>
#include <Utilities/Bitwise_Operations.h>
/************************************************************************************************
 *                               Definitions                                                    *
 ************************************************************************************************/
#define SYSTICK_TIMEOUT         80   /*the worst case time for executing the 3
                                        tasks consecutively in milliseconds*/

/************************************************************************************************
 *                               extern variables                                               *
 ************************************************************************************************/
extern volatile uint8 current_time;

/*************************************************************************************************
 *                              Functions Prototypes                                             *
 *************************************************************************************************/

/*************************************************************************************************
* Function Name: systick_init
* Parameters (in): None
* Return value:None
* Description: configure and init the systick timer with the pre-defined timeout.
**************************************************************************************************/
void systick_init(void);

/***************************************************************************************************
* Function Name: SysTick_SetCallBack
* Parameters (in): void (*ptr_to_func)(void)
* Return value:None
* Description:set the global callback pointer to the provided pointer to function.
****************************************************************************************************/
void SysTick_SetCallBack(void (*ptr_to_func)(void));

/***************************************************************************************************
* Function Name: SysTick_Stop
* Parameters (in): None
* Return value:None
* Description:suspend the systick module by clearing the enable bit in the control register.
****************************************************************************************************/
void SysTick_Stop(void);

/***************************************************************************************************
* Function Name: SysTick_resume
* Parameters (in): None
* Return value:None
* Description:resume the systick module by setting the enable bit in the control register.
****************************************************************************************************/
void SysTick_resume(void);


#endif /* MCAL_SYSTICK_H_ */
