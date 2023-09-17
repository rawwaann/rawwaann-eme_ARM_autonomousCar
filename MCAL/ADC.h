

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#define ADC_H_
/***************************************************************************************************
 *                                includes                                                          *
 ***************************************************************************************************/
#include <Utilities/std_types.h>
#include <Tiva_Registers.h>
#include <Utilities/Bitwise_Operations.h>
#include <MCAL/DIO.h>

extern uint32 ldr1_buffer;
extern uint32 ldr2_buffer;
extern uint32 ts_buffer;
extern volatile uint32 TEMP;

/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/
void configurePLL(void);
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/
void ADC_INIT(void);
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/
void LDR1_ADC_INIT(void);
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/
void LDR1_ADC_GETDATA(void);
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/
void LDR2_ADC_INIT(void);
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/
void LDR2_ADC_GETDATA(void);
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/

void TS_ADC_INIT(void);
/***************************************************************************************************
* Function Name:
* Parameters (in):
* Return value:
* Description:

****************************************************************************************************/
void TS_ADC_GETDATA(void);


#endif /* MCAL_ADC_H_ */
