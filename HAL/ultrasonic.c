#include "ultrasonic.h"

/***************************************************************************************************
* Function Name: ultrasonic_init
* Parameters (in): void
* Return value: void
* Description: ultrasonic initialization
****************************************************************************************************/
void ultrasonic_init(void)
{
    GPTM_ipEdgeTimeCapture_init();
    GPTM_WTIMER1_oneShot_init();

    /*configure trigger pin of the ultrasonic as an output GPIO pin*/
    DIO_SetPinDirection(PORTD,BIT1,OUTPUT);
    SET_BIT(GPIO_PORTD_DEN_R,1);
    DIO_WritePin(PORTD,BIT1,LOW);
}

/***************************************************************************************************
* Function Name: ultrasonicTrigger
* Parameters (in): void
* Return value: void
* Description: generating the trigger signal that is needed by the ultrasonic to send its echo signal
****************************************************************************************************/
void ultrasonicTrigger(void)
{
    DIO_WritePin(PORTD,BIT1,HIGH);
    GPTM_delay_us(100);
    DIO_WritePin(PORTD,BIT1,LOW);
}
