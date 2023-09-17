
#include "GPTM.h"

/*************************************************************************************************
*                                    Global variables                                             *
***************************************************************************************************/
uint8 g_intEdge = 0;
float total_time = 0;
uint32 distance = 25; /*initialize the distance between the car and the obstacle with any value
                         which is  larger than the COLLISION DISTANCE*/

/***************************************************************************************************
* Function Name: GPTM_ipEdgeTimeCapture_init
* Parameters (in):None
* Return value:None
* Description: initialize the wide timer 2 module in Input Edge Time Capture mode .

****************************************************************************************************/
void GPTM_ipEdgeTimeCapture_init(void)
{
    DIO_Init(PORTD, PD); /*Clk initialization for port D*/
    /*configure echo pin of the ultrasonic as an input to WTIMER2 (PD0)*/
    SET_BIT(GPIO_PORTD_DEN_R,0);
    SET_BIT(GPIO_PORTD_AFSEL_R,0);
    GPIO_PORTD_PCTL_R |= 0x7;  /*choosing wide timer2 on PD0*/

    SET_BIT(SYSCTL_RCGCWTIMER_R,TIMER2); /*enabling clock for WTIMER2*/
    CLEAR_BIT(WTIMER2_CTL_R,TAEN_bit);   /*disable the timer by clearing TAEN_bit in register */
    WTIMER2_CFG_R |= 0x4;  /*using 32 bit wide mode (timer A)*/

    WTIMER2_TAMR_R |= 0x07; /*write the TnCMR field to 0x1 and the TnMR
                            field to 0x3 and select a count direction by programming the TnCDIR bit.*/
    SET_BIT(WTIMER2_CTL_R,TAEVENT_bit1);
    SET_BIT(WTIMER2_CTL_R,TAEVENT_bit2); /* event edge is set to both edges*/
    WTIMER2_TAILR_R = TICKS_FOR_MAX_DIST;
    SET_BIT(WTIMER2_IMR_R,2); /*Enabling timer interrupt*/
    SET_BIT(NVIC_EN3_R,2);    /*Enabling the global interrupts*/
    SET_BIT(WTIMER2_CTL_R,TAEN_bit); /*enable the timer*/
}
/***************************************************************************************************
* Function Name: GPTM_ipEdgeTimeCaptureHandler
* Parameters (in):None
* Return value:None
* Description: interrupt handler for the wide timer2 in which calculates the difference between the
*              raising and falling edges .
****************************************************************************************************/
void GPTM_ipEdgeTimeCaptureHandler(void)
{
    SET_BIT(WTIMER2_ICR_R,CAECINT);     /*clear flag*/
    static uint32 rising_time;
    static uint32 falling_time;
    g_intEdge++;
    if(g_intEdge==1) /*Raising Edge detected*/
    {
        rising_time = WTIMER2_TAR_R;
    }
    else if(g_intEdge==2) /*Falling Edge detected*/
    {
        g_intEdge=0;
        falling_time= WTIMER2_TAR_R;
        total_time = (rising_time - falling_time) / 16000.0;
        distance = (34 *total_time)/2;
        rising_time = 0;
        falling_time = 0;
    }
    else
    {
        /*FOR MISRA*/
    }
}

/***************************************************************************************************
* Function Name: GPTM_WTIMER1_oneShot_init
* Parameters (in):None
* Return value:None
* Description:  initialize the wide timer 1 module in one shot mode for a delay purposes
****************************************************************************************************/
void GPTM_WTIMER1_oneShot_init(void)
{
    SET_BIT(SYSCTL_RCGCWTIMER_R, 1);    /*Enable wide timer 1 in Run mode*/
    CLEAR_BIT(WTIMER1_CTL_R, 0);        /*Disable the timer 1  module */
    WTIMER1_CFG_R=0x04;
    SET_BIT(WTIMER1_TAMR_R, 0);         /*One shot mode*/

}

/***************************************************************************************************
* Function Name: GPTM_delay_us
* Parameters (in):uint32 time
* Return value:None
* Description:  delay function in microseconds
****************************************************************************************************/
void GPTM_delay_us(uint32 time)
{
    WTIMER1_TAILR_R=time*TIME_FACTOR_MICRO_SECONDS -1;
    SET_BIT(WTIMER1_CTL_R, 0);          /*Enable the timer */
    while (!(GET_BIT(WTIMER1_RIS_R,0))){}
    SET_BIT(WTIMER1_ICR_R,0);
    CLEAR_BIT(WTIMER1_CTL_R, 0);
}

/***************************************************************************************************
* Function Name: GPTM_delay_ms
* Parameters (in):uint32 time
* Return value:None
* Description:  delay function in milliseconds
****************************************************************************************************/
void GPTM_delay_ms(uint32 time)
{

    WTIMER1_TAILR_R=time*TIME_FACTOR_MILLI_SECONDS -1;
    SET_BIT(WTIMER1_CTL_R, 0);         /*Enable the timer */
    while (!(GET_BIT(WTIMER1_RIS_R,0))){}
    SET_BIT(WTIMER1_ICR_R,0);
    CLEAR_BIT(WTIMER1_CTL_R, 0);       /*disable the timer */
}

/***************************************************************************************************
* Function Name: GPTM_WTIMER4_periodic_init
* Parameters (in):None
* Return value:None
* Description:initialize wide timer 4 in periodic mode for measuring each task duration .
****************************************************************************************************/
void GPTM_WTIMER4_periodic_init(void)
{
    SET_BIT(SYSCTL_RCGCWTIMER_R, 4);    /*Enable wide timer 1 in Run mode*/
    CLEAR_BIT(WTIMER4_CTL_R, 0);        /*Disable the timer 1  module */
    WTIMER4_CFG_R=0x04;
    SET_BIT(WTIMER4_TAMR_R, 0);         /*One shot mode*/
    SET_BIT(WTIMER4_TAMR_R, 4);
    WTIMER4_TAILR_R=4294967296-1;
    SET_BIT(WTIMER4_CTL_R, 0);          /*Enable the timer */
}
