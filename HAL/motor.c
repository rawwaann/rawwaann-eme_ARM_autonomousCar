#include "motor.h"

/***************************************************************************************************
* Function Name: motorControl_init
* Parameters (in): void
* Return value: void
* Description: DC motor initialization
****************************************************************************************************/
void motorControl_init(void)
{

    DIO_Init(MOTOR_PORT_IN1,PE);
    DIO_Init(MOTOR_PORT_IN3,PB);

    SET_BIT(GPIO_PORTE_CR_R,MOTOR_PIN_IN1);
    SET_BIT(GPIO_PORTE_CR_R,MOTOR_PIN_IN2);
    SET_BIT(GPIO_PORTB_CR_R,MOTOR_PIN_IN3);
    SET_BIT(GPIO_PORTE_CR_R,MOTOR_PIN_IN4);

    DIO_SetPinDirection(MOTOR_PORT_IN1,MOTOR_PIN_IN1,OUTPUT);
    DIO_SetPinDirection(MOTOR_PORT_IN2,MOTOR_PIN_IN2,OUTPUT);
    DIO_SetPinDirection(MOTOR_PORT_IN3,MOTOR_PIN_IN3,OUTPUT);
    DIO_SetPinDirection(MOTOR_PORT_IN4,MOTOR_PIN_IN4,OUTPUT);

    DIO_WritePin(MOTOR_PORT_IN1,MOTOR_PIN_IN1,LOW);
    DIO_WritePin(MOTOR_PORT_IN2,MOTOR_PIN_IN2,LOW);
    DIO_WritePin(MOTOR_PORT_IN3,MOTOR_PIN_IN3,LOW);
    DIO_WritePin(MOTOR_PORT_IN4,MOTOR_PIN_IN4,LOW);
}

/***************************************************************************************************
* Function Name: motor_moveForward
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> forward direction
****************************************************************************************************/
void motor_moveForward(void)
{
    DIO_WritePin(MOTOR_PORT_IN1,MOTOR_PIN_IN1, LOW);
    DIO_WritePin(MOTOR_PORT_IN2,MOTOR_PIN_IN2, HIGH);
    DIO_WritePin(MOTOR_PORT_IN3,MOTOR_PIN_IN3, HIGH);
    DIO_WritePin(MOTOR_PORT_IN4,MOTOR_PIN_IN4, LOW);
}

/***************************************************************************************************
* Function Name: motor_moveBackward
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> backward direction
****************************************************************************************************/
void motor_moveBackward(void)
{
    DIO_WritePin(MOTOR_PORT_IN1,MOTOR_PIN_IN1, HIGH);
    DIO_WritePin(MOTOR_PORT_IN2,MOTOR_PIN_IN2, LOW);
    DIO_WritePin(MOTOR_PORT_IN3,MOTOR_PIN_IN3, LOW);
    DIO_WritePin(MOTOR_PORT_IN4,MOTOR_PIN_IN4, HIGH);
}

/***************************************************************************************************
* Function Name: motor_moveRight
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> right direction
****************************************************************************************************/
void motor_moveRight(void)
{
    DIO_WritePin(MOTOR_PORT_IN1,MOTOR_PIN_IN1, HIGH);
    DIO_WritePin(MOTOR_PORT_IN2,MOTOR_PIN_IN2, HIGH);
    DIO_WritePin(MOTOR_PORT_IN3,MOTOR_PIN_IN3, HIGH);
    DIO_WritePin(MOTOR_PORT_IN4,MOTOR_PIN_IN4, LOW);
}

/***************************************************************************************************
* Function Name: motor_moveLeft
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> left direction
****************************************************************************************************/
void motor_moveLeft(void)
{
    DIO_WritePin(MOTOR_PORT_IN1,MOTOR_PIN_IN1, LOW);
    DIO_WritePin(MOTOR_PORT_IN2,MOTOR_PIN_IN2, HIGH);
    DIO_WritePin(MOTOR_PORT_IN3,MOTOR_PIN_IN3, HIGH);
    DIO_WritePin(MOTOR_PORT_IN4,MOTOR_PIN_IN4, HIGH);

}

/***************************************************************************************************
* Function Name: motor_brakes
* Parameters (in): void
* Return value: void
* Description: stopping the car
****************************************************************************************************/
void motor_brakes(void)
{
    DIO_WritePin(MOTOR_PORT_IN1,MOTOR_PIN_IN1, LOW);
    DIO_WritePin(MOTOR_PORT_IN2,MOTOR_PIN_IN2, LOW);
    DIO_WritePin(MOTOR_PORT_IN3,MOTOR_PIN_IN3, LOW);
    DIO_WritePin(MOTOR_PORT_IN4,MOTOR_PIN_IN4, LOW);
}
