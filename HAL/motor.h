#ifndef MOTOR_H_
#define MOTOR_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <Utilities/std_types.h>
#include <MCAL/DIO.h>
#include <Tiva_Registers.h>
#include <Utilities/Bitwise_Operations.h>
#include <MCAL/PWM.h>


/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/
/*input pins for motors*/
#define MOTOR_PORT_IN1 PORTE
#define MOTOR_PIN_IN1 BIT3          /*IN1 --> PE3*/

#define MOTOR_PORT_IN2 PORTE
#define MOTOR_PIN_IN2 BIT4          /* IN2 --> PE4 */

#define MOTOR_PORT_IN3 PORTB
#define MOTOR_PIN_IN3 BIT5          /*IN3 --> PB5 */

#define MOTOR_PORT_IN4 PORTE
#define MOTOR_PIN_IN4 BIT0          /*IN4 --> PE0 */

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/***************************************************************************************************
* Function Name: motorControl_init
* Parameters (in): void
* Return value: void
* Description: DC motor initialization
****************************************************************************************************/
void motorControl_init(void);

/***************************************************************************************************
* Function Name: motor_moveForward
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> forward direction
****************************************************************************************************/
void motor_moveForward(void);

/***************************************************************************************************
* Function Name: motor_moveBackward
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> backward direction
****************************************************************************************************/
void motor_moveBackward(void);

/***************************************************************************************************
* Function Name: motor_moveRight
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> right direction
****************************************************************************************************/
void motor_moveRight(void);

/***************************************************************************************************
* Function Name: motor_moveLeft
* Parameters (in): void
* Return value: void
* Description: controlling the car movement --> left direction
****************************************************************************************************/
void motor_moveLeft(void);

/***************************************************************************************************
* Function Name: motor_brakes
* Parameters (in): void
* Return value: void
* Description: stopping the car
****************************************************************************************************/
void motor_brakes(void);

#endif /* MOTOR_H_ */
