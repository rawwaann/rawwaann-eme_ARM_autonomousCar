#include <HAL/temp_sensor.h>

/***************************************************************************************************
* Function Name: Temp_sensorInit
* Parameters (in): void
* Return value: void
* Description: initializing the temperature sensor module
****************************************************************************************************/
void Temp_sensorInit(void)
{
    ADC_INIT();
    TS_ADC_INIT();
}


/***************************************************************************************************
* Function Name: Temp_sensorRead
* Parameters (in): void
* Return value: void
* Description: obtaining the reading of the temperature sensor from the ADC
****************************************************************************************************/
void Temp_sensorRead(void)
{
    TS_ADC_GETDATA();
}
