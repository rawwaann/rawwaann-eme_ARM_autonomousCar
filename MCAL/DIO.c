/*
 * DIO.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Shrook
 *      This Source file aims to implement the configuration file
 *      of the Microcontroller Abstraction Layer (MCAL) in Tiva C Series
 *      including GPIO ports(pins, properties and Interrupts).
 *
 */




#include "DIO.h"
/***************************************************************************************************
*                                           Global variables                                       *
****************************************************************************************************/
uint8 switch0_flag = 0; /*start flag*/
uint8 switch4_flag = 0; /*stop flag*/

/***************************************************************************************************
*                                  GPIO Properties functionalities                                  *
****************************************************************************************************/
/* function for GPIO ports initialization*/
void DIO_Init(DIO_PORT_et port_id, DIO_PORT_LOCATION_et port_location){
    SET_BIT(SYSCTL_RCGCGPIO_R, port_location);
    while(GET_BIT(SYSCTL_PRGPIO_R, port_location) == 0){};

    GPIO_PORT_LOCK(port_id) = 0x4C4F434B;
    GPIO_PORT_CR(port_id) = 0x1F;
}


/* function to write data into a specific port*/
void DIO_WritePort(DIO_PORT_et port_id, uint8 byte){
    GPIO_PORT_DATA(port_id) = byte;
}

/* function to write data into a specific port pin*/
void DIO_WritePin(DIO_PORT_et port_id, DIO_BIT_et bit_num, DIO_PIN_STATE_et pin_state){
    if(pin_state == LOW)
    {
        CLEAR_BIT(GPIO_PORT_DATA(port_id), bit_num);
    }
    else
    {
        SET_BIT(GPIO_PORT_DATA(port_id), bit_num);
    }
}

/* function to read data from a specific port*/
uint8 DIO_ReadPort(DIO_PORT_et port_id){
    uint8 byte = GPIO_PORT_DATA(port_id);
    return byte;
}

/* function to read data from a specific port pin*/
uint8 DIO_ReadPin(DIO_PORT_et port_id, DIO_BIT_et bit_num){
    uint8 pin_state = GET_BIT(GPIO_PORT_DATA(port_id), bit_num);
    return pin_state;
}


/* function to set port direction (input or output)*/
void DIO_SetPortDirection(DIO_PORT_et port_id, uint8 byte, DIO_PIN_DIRECTION_et port_direction){
    GPIO_PORT_DIR(port_id) = byte;
    GPIO_PORT_DEN(port_id) = 0xFF;
}

/* function to set pin direction (input or output)*/
void DIO_SetPinDirection(DIO_PORT_et port_id, DIO_BIT_et bit_num, DIO_PIN_DIRECTION_et pin_direction){
    if(pin_direction == INPUT)
    {
        CLEAR_BIT(GPIO_PORT_DIR(port_id), bit_num);
    }
    else
    {
        SET_BIT(GPIO_PORT_DIR(port_id), bit_num);
    }
    SET_BIT(GPIO_PORT_DEN(port_id), bit_num);
}

/* function to set port specific pins control mode (pull-up or pull-down)*/
void DIO_SetPortControlMode(DIO_PORT_et port_id, DIO_BIT_et bit_num, DIO_PORT_CONTROL_et port_resistor){
    if (port_resistor == PULL_UP)
    {
        SET_BIT(GPIO_PORT_PUR(port_id), bit_num);
    }
    else
    {
        SET_BIT(GPIO_PORT_PDR(port_id), bit_num);
    }
}


/***************************************************************************************************
*                                  GPIO Interrupts functionalities                                  *
****************************************************************************************************/

/* function to enable port specific pins interrupt*/
void DIO_EnablePortInterrupt(DIO_PORT_et port_id, DIO_PORT_INTERRUPT_NUM_et interrupt_num, DIO_BIT_et bit_num, DIO_PORT_INTERRUPT_SENSE_et port_sense, DIO_PORT_INTERRUPT_EDGE_et port_edge, DIO_PORT_INTERRUPT_EVENT_et port_event){
    if(port_sense == LEVEL){
        DIO_PortLevelInterrupt(port_id, bit_num, port_event);
    }
    else{
        DIO_PortEdgeInterrupt(port_id, bit_num, port_edge, port_event);
    }
    SET_BIT(GPIO_PORT_Interrupt_IM(port_id), bit_num);
    SET_BIT(NVIC_EN0_R, interrupt_num);
}

/*function to enable port specific pins level interrupt*/
void DIO_PortLevelInterrupt(DIO_PORT_et port_id, DIO_BIT_et bit_num, DIO_PORT_INTERRUPT_EVENT_et port_event){
    SET_BIT(GPIO_PORT_Interrupt_IS(port_id), bit_num);
    if(port_event == FALLING_LOW){
        CLEAR_BIT(GPIO_PORT_Interrupt_IEV(port_id), bit_num);
    }
    else{
        SET_BIT(GPIO_PORT_Interrupt_IEV(port_id), bit_num);
    }

}
/* function to enable port specific pins edge interrupt*/
void DIO_PortEdgeInterrupt(DIO_PORT_et port_id, DIO_BIT_et bit_num, DIO_PORT_INTERRUPT_EDGE_et port_edge, DIO_PORT_INTERRUPT_EVENT_et port_event){
    CLEAR_BIT(GPIO_PORT_Interrupt_IS(port_id), bit_num);
    if(port_edge == SINGLE_EDGE){
        CLEAR_BIT(GPIO_PORT_Interrupt_IBE(port_id), bit_num);
    }
    else{
        SET_BIT(GPIO_PORT_Interrupt_IBE(port_id), bit_num);
    }
    if(port_event == FALLING_LOW){
        CLEAR_BIT(GPIO_PORT_Interrupt_IEV(port_id), bit_num);
    }
    else{
        SET_BIT(GPIO_PORT_Interrupt_IEV(port_id), bit_num);
    }

}
/**************************************************************************************************
* Function Name: DIO_switches_handler
* Parameters (in):None
* Return value:None
* Description: interrupt handler for each of switch 0 and switch 4

**************************************************************************************************/
void DIO_switches_handler(void)
{

    if(GET_BIT(GPIO_PORTF_RIS_R,0)) /*sw0 is pressed*/
    {
       /*Start the car*/
        switch0_flag = 1;
        switch4_flag = 0;
        SysTick_resume();
    }

    else if(GET_BIT(GPIO_PORTF_RIS_R,4)) /*sw4  is pressed*/
    {
        /*stop the car*/
        switch4_flag = 1;
        switch0_flag = 0;
    }
    SET_BIT(GPIO_PORTF_ICR_R,0);
    SET_BIT(GPIO_PORTF_ICR_R,4);
}


/**************************************************************************************************
* Function Name: DIO_switches_init
* Parameters (in):None
* Return value:None
* Description: init the dio switches , including their interrupt configuration

**************************************************************************************************/
void DIO_switches_init(void)
{
    DIO_Init(PORTF,PF);

    DIO_SetPinDirection(PORTF,  BIT0, INPUT);
    DIO_SetPinDirection(PORTF,  BIT4, INPUT);
    DIO_SetPortControlMode( PORTF,  BIT0, PULL_UP);
    DIO_SetPortControlMode( PORTF,  BIT4, PULL_UP);
    /*mask the interrupts for switch 0 and 4 during the configuration */
    CLEAR_BIT(GPIO_PORTF_IM_R,0);
    CLEAR_BIT(GPIO_PORTF_IM_R,4);
    /*Edge trigger to sw0 and sw4*/
    CLEAR_BIT(GPIO_PORTF_IS_R,0);
    CLEAR_BIT(GPIO_PORTF_IS_R,4);
    /*Single edge trigger*/
    CLEAR_BIT(GPIO_PORTF_IBE_R,0);
    CLEAR_BIT(GPIO_PORTF_IBE_R,4);
    /*clear interrupts' flags*/
    CLEAR_BIT(GPIO_PORTF_ICR_R,0);
    CLEAR_BIT(GPIO_PORTF_ICR_R,4);
    /*un-mask the interrupts for switch 0 and four */
    SET_BIT(GPIO_PORTF_IM_R,0);
    SET_BIT(GPIO_PORTF_IM_R,4);
    /*detect falling edges*/
    CLEAR_BIT(GPIO_PORTF_IEV_R,0);
    CLEAR_BIT(GPIO_PORTF_IEV_R,4);
    /*Enable the PORT F interrupt in NVIC */
    SET_BIT(NVIC_EN0_R,30);

}

