#ifndef APP_TASKS_H_
#define APP_TASKS_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <OS/os.h>

/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/
#define COLLISION_DISTANCE 10
#define AVOIDANCE_DISTANCE 20

/*******************************************************************************
 *                               Type Definitions                              *
 *******************************************************************************/
typedef enum{
    BACKWARD,NINTY_ROTATION,NORMAL
}avoid_obstacles_state;

/*******************************************************************************
 *                               extern variables                              *
 *******************************************************************************/
extern uint32 g_currentTime_ms;
extern sint32 ldr_diff ;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/***************************************************************************************************
* Task Name: ldr_swing_car
* Parameters (in): void
* Return value: void
* Description: Task to swing the car based on the higher LDR reading
****************************************************************************************************/
void ldr_swing_car(void);

/***************************************************************************************************
* Task Name: avoid_obstacles
* Parameters (in): void
* Return value: void
* Description: Task that uses ultrasonic sensor to detect and avoid obstacles.
****************************************************************************************************/
void avoid_obstacles(void);

/***************************************************************************************************
* Task Name: lcd_display
* Parameters (in): void
* Return value: void
* Description: Task to display temperature reading and current time on the LCD.
****************************************************************************************************/
void lcd_display(void);

#endif /* APP_TASKS_H_ */
