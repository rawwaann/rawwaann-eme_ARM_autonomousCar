#include "hal.h"

/***************************************************************************************************
* Function Name: Get_LDRReads
* Parameters (in): void
* Return value: void
* Description: initializing the modules needed by the HAL from the MCAL
****************************************************************************************************/
void MCAL_init(void)
{
    GPTM_ipEdgeTimeCapture_init();
    GPTM_WTIMER1_oneShot_init();
//    GPTM_WTIMER4_periodic_init();
    PWM_Init();
    DIO_switches_init();

    /*ADC init is called in in LDR init function, not needed here*/
}
