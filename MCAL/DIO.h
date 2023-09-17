/*
 * DIO.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Shrook
 *      This Header file aims to Build configuration file
 *      of the Microcontroller Abstraction Layer (MCAL) in Tiva C Series
 *      including GPIO ports(pins, properties and Interrupts).
 *
 *
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#include <Utilities/std_types.h>
#include "Tiva_Registers.h"
#include <Utilities/Bitwise_Operations.h>
#include <MCAL/systick.h>


/*******************************************************************************************************
 *                                   GPIO Properties Macros                                            *
 *******************************************************************************************************/
/*macro for port registers*/
#define GPIO_PORT_DATA(port_id) (*((volatile unsigned long *)((GPIO_PORTA_DATA_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_LOCK(port_id) (*((volatile unsigned long *)((GPIO_PORTA_LOCK_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_CR(port_id) (*((volatile unsigned long *)((GPIO_PORTA_CR_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_DIR(port_id) (*((volatile unsigned long *)((GPIO_PORTA_DIR_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_PUR(port_id) (*((volatile unsigned long *)((GPIO_PORTA_PUR_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_PDR(port_id) (*((volatile unsigned long *)((GPIO_PORTA_PDR_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_DEN(port_id) (*((volatile unsigned long *)((GPIO_PORTA_DEN_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_Interrupt_IS(port_id) (*((volatile unsigned long *)((GPIO_PORTA_IS_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_Interrupt_IBE(port_id) (*((volatile unsigned long *)((GPIO_PORTA_IBE_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_Interrupt_IEV(port_id) (*((volatile unsigned long *)((GPIO_PORTA_IEV_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_Interrupt_IM(port_id) (*((volatile unsigned long *)((GPIO_PORTA_IM_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_Interrupt_RIS(port_id) (*((volatile unsigned long *)((GPIO_PORTA_RIS_R_P) + ((port_id)*0x1000))))
#define GPIO_PORT_Interrupt_MIS(port_id) (*((volatile unsigned long *)((GPIO_PORTA_MIS_R_P )+ ((port_id)*0x1000))))
#define GPIO_PORT_Interrupt_ICR(port_id) (*((volatile unsigned long *)((GPIO_PORTA_ICR_R_P )+ ((port_id)*0x1000))))


/*******************************************************************************************************
 *                                   GPIO Properties typedefs                                          *
 *******************************************************************************************************/

/*typedef enumeration for GPIO Ports Names*/
typedef enum{
    PORTA=0,
    PORTB,
    PORTC,
    PORTD,
    PORTE=32,
    PORTF
} DIO_PORT_et;

/*typedef enumeration for GPIO Ports Location*/
typedef enum{
    PA,
    PB,
    PC,
    PD,
    PE,
    PF
} DIO_PORT_LOCATION_et;

/*typedef enumeration for GPIO Port Bits*/
typedef enum{
    BIT0,
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7
} DIO_BIT_et;

/*typedef enumeration for GPIO Port Pin State*/
typedef enum{
    LOW,
    HIGH
} DIO_PIN_STATE_et;

/*typedef enumeration for GPIO Port Pin Direction*/
typedef enum{
    INPUT,
    OUTPUT
} DIO_PIN_DIRECTION_et;

/*typedef enumeration for GPIO Port Control Register => (resistor)*/
typedef enum{
    PULL_DOWN,
    PULL_UP
} DIO_PORT_CONTROL_et;

/*typedef enumeration for GPIO Ports Interrupts Vector Table*/
typedef enum{
    PORTA_INTERRUPT=0,
    PORTB_INTERRUPT=1,
    PORTC_INTERRUPT=2,
    PORTD_INTERRUPT=3,
    PORTE_INTERRUPT=4,
    PORTF_INTERRUPT=30
} DIO_PORT_INTERRUPT_NUM_et;

/*typedef enumeration for GPIO Port Interrupt Sense*/
typedef enum{
    LEVEL,
    EDGE
} DIO_PORT_INTERRUPT_SENSE_et;

/*typedef enumeration for GPIO Port Interrupt Edge*/
typedef enum{
    SINGLE_EDGE,
    BOTH_EDGES
} DIO_PORT_INTERRUPT_EDGE_et;

/*typedef enumeration for GPIO Port Interrupt Event*/
typedef enum{
    FALLING_LOW,
    RISING_HIGH
} DIO_PORT_INTERRUPT_EVENT_et;




/*******************************************************************************
 *                               extern variables                              *
 *******************************************************************************/
extern uint8 switch0_flag; /*start flag*/
extern uint8 switch4_flag; /*stop flag*/


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/* function for GPIO ports initialization*/
void DIO_Init(DIO_PORT_et, DIO_PORT_LOCATION_et);

/* function to write data into a specific port*/
void DIO_WritePort(DIO_PORT_et, uint8);

/* function to write data into a specific port pin*/
void DIO_WritePin(DIO_PORT_et, DIO_BIT_et, DIO_PIN_STATE_et);

/* function to read data from a specific port*/
uint8 DIO_ReadPort(DIO_PORT_et);

/* function to read data from a specific port pin*/
uint8 DIO_ReadPin(DIO_PORT_et, DIO_BIT_et);

/* function to set port direction (input or output)*/
void DIO_SetPortDirection(DIO_PORT_et, uint8, DIO_PIN_DIRECTION_et);

/* function to set pin direction (input or output)*/
void DIO_SetPinDirection(DIO_PORT_et, DIO_BIT_et, DIO_PIN_DIRECTION_et);

/* function to set port specific pins control mode (pull-up or pull-down)*/
void DIO_SetPortControlMode(DIO_PORT_et, DIO_BIT_et, DIO_PORT_CONTROL_et);

/********************GPIO Interrupts functionalities*********************************/
/*function to enable port specific pins interrupt*/
void DIO_EnablePortInterrupt(DIO_PORT_et port, DIO_PORT_INTERRUPT_NUM_et ir_num, DIO_BIT_et bit, DIO_PORT_INTERRUPT_SENSE_et ir_sense, DIO_PORT_INTERRUPT_EDGE_et edge , DIO_PORT_INTERRUPT_EVENT_et ev );

/* function to enable port specific pins level interrupt*/
void DIO_PortLevelInterrupt(DIO_PORT_et port, DIO_BIT_et bit, DIO_PORT_INTERRUPT_EVENT_et ev);

/* function to enable port specific pins edge interrupt*/
void DIO_PortEdgeInterrupt(DIO_PORT_et port, DIO_BIT_et bit, DIO_PORT_INTERRUPT_EDGE_et edge, DIO_PORT_INTERRUPT_EVENT_et ev);
void DIO_switches_init(void);




#endif /* MCAL_DIO_H_ */
