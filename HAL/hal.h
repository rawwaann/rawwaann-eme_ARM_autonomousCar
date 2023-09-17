#ifndef HAL_HAL_H_
#define HAL_HAL_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <MCAL/DIO.h>
#include <MCAL/GPTM.h>
#include <MCAL/PWM.h>
#include <MCAL/systick.h>
#include <MCAL/ADC.h>


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/***************************************************************************************************
* Function Name: Get_LDRReads
* Parameters (in): void
* Return value: void
* Description: initializing the modules needed by the HAL from the MCAL
****************************************************************************************************/
void MCAL_init(void);

#endif /* HAL_HAL_H_ */
