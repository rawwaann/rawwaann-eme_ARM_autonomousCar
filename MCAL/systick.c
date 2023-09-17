
#include"systick.h"
/***************************************************************************************************
* Global pointer to function used to point upper layer functions to be used in Call Back           *
****************************************************************************************************/
static void (*g_SysTick_Call_Back_Ptr)(void) = NULL;

/***************************************************************************************************
* Function Name: systick_init
* Parameters (in): None
* Return value:None
* Description: configure and init the systick timer module with the pre-defined timeout.
****************************************************************************************************/
void systick_init(void)
{
    NVIC_ST_CTRL_R=0U;
    NVIC_ST_RELOAD_R=((uint8)(15999U))*SYSTICK_TIMEOUT; /* Set the Reload value to the desired time to give an interrupt in milli-seconds*/
    NVIC_ST_CURRENT_R=0U;
    NVIC_ST_CTRL_R |= 0x07U;
}

/***************************************************************************************************
* Function Name: systick_handler
* Parameters (in): None
* Return value:None
* Description: call the callback function for each time systick fires an interrupt.
****************************************************************************************************/
void systick_handler(void)
{

    /* Check if the SysTick_SetCallBack is already called */
       if(g_SysTick_Call_Back_Ptr != NULL)
       {
           (*g_SysTick_Call_Back_Ptr)(); /* call the function in the scheduler using call-back concept */
       }
       /* No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW */

}


/***************************************************************************************************
* Function Name: SysTick_SetCallBack
* Parameters (in): void (*ptr_to_func)(void)
* Return value:None
* Description:set the global callback pointer to the provided pointer to function.
****************************************************************************************************/

void SysTick_SetCallBack(void (*ptr_to_func)(void))
{
    g_SysTick_Call_Back_Ptr = ptr_to_func;
}

/***************************************************************************************************
* Function Name: SysTick_Stop
* Parameters (in): None
* Return value:None
* Description:suspend the systick module by clearing the enable bit in the control register.
****************************************************************************************************/
void SysTick_Stop(void)
{
    NVIC_ST_CTRL_R = 0U; /* Disable the SysTick Timer by Clear the ENABLE Bit */
}

/***************************************************************************************************
* Function Name: SysTick_resume
* Parameters (in): None
* Return value:None
* Description:resume the systick module by setting the enable bit in the control register.
****************************************************************************************************/
void SysTick_resume(void)
{
    NVIC_ST_CTRL_R = 1U; /* enable the SysTick Timer by setting the ENABLE Bit */
}


