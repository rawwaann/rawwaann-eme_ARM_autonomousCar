#ifndef HAL_TEMP_SENSOR_H_
#define HAL_TEMP_SENSOR_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <MCAL/ADC.h>

/***************************************************************************************************
* Function Name: Temp_sensorInit
* Parameters (in): void
* Return value: void
* Description: initializing the temperature sensor module
****************************************************************************************************/
void Temp_sensorInit(void);

/***************************************************************************************************
* Function Name: Temp_sensorRead
* Parameters (in): void
* Return value: void
* Description: obtaining the reading of the temperature sensor from the ADC
****************************************************************************************************/
void Temp_sensorRead(void);

#endif /* HAL_TEMP_SENSOR_H_ */
