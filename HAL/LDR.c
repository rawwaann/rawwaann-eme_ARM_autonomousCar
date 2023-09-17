#include "LDR.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/***************************************************************************************************
* Function Name: LDR_INIT
* Parameters (in): void
* Return value: void
* Description: LDR initialization
****************************************************************************************************/
void LDR_INIT(void)
{
    ADC_INIT();
    LDR1_ADC_INIT();
    LDR2_ADC_INIT();
}

/***************************************************************************************************
* Function Name: Get_LDRReads
* Parameters (in): void
* Return value: void
* Description: getting the LDR readings obtained by the ADC module
****************************************************************************************************/
void Get_LDRReads(void)
{
    LDR1_ADC_GETDATA();
    LDR2_ADC_GETDATA();
}
