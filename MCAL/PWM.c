
#include "PWM.h"
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:
****************************************************************************************************/

void PWM_Init(void)
{
    SET_BIT(SYSCTL_RCGCPWM_R,0U);

    DIO_Init(PORTB,PB);
    DIO_Init(PORTE,PE);


    SET_BIT(GPIO_PORTB_AFSEL_R,BIT4);
    GPIO_PORTB_PCTL_R |= 0x00040000;   /*VALUE 4    M0PWM2*/

    SET_BIT(GPIO_PORTE_AFSEL_R,BIT5);
    GPIO_PORTE_PCTL_R |= 0x00400000;   /*VALUE 4    M0PWM5*/

    SET_BIT(GPIO_PORTB_DEN_R,BIT4);      /* B4*/
    SET_BIT(GPIO_PORTE_DEN_R,BIT5);     /* E5*/

    SET_BIT(SYSCTL_RCC_R,20); /*use the PWM divide (USEPWMDIV)*/
    /****set the divider (PWMDIV) to divide by 2 (000).*****/
    CLEAR_BIT(SYSCTL_RCC_R,17);
    CLEAR_BIT(SYSCTL_RCC_R,18);
    CLEAR_BIT(SYSCTL_RCC_R,19);


    /** countdown mode**/
    PWM0_1_CTL_R= 0; /*disable generator*/
    PWM0_2_CTL_R=0x00000000;
    PWM0_1_GENA_R=0x0000008C;
    PWM0_2_GENB_R=0x0000080C;
    /**period**/
    PWM0_1_LOAD_R=0xFFFF;
    PWM0_1_CMPA_R=0x00FF;
    PWM0_2_LOAD_R= 0xFFFF;
    PWM0_2_CMPB_R=0x00FF;
    /*********************start timer********************/
    SET_BIT(PWM0_1_CTL_R,0);
    SET_BIT(PWM0_2_CTL_R,0);
    /*************************enable*********************/
    SET_BIT(PWM0_ENABLE_R,BIT2);
    SET_BIT(PWM0_ENABLE_R,BIT5);

}



