/*This is the code for the three main tasks of the system which are:
1- Task to swing the car based on the LDR.s [void ldr_swing_car(void)]
2- Task to avoid obstacles based on the readings of the ultrasonic sensor. [void avoid_obstacles(void)]
3- Task to display on the LCD. [void lcd_display(void)] */

#include "tasks.h"


sint32 ldr_diff ;  /*global variable to hold the current time to be printed on the LCD*/
avoid_obstacles_state current_state=NORMAL;

/***************************************************************************************************
* Task Name: ldr_swing_car
* Parameters (in): void
* Return value: void
* Description: Task to swing the car based on the higher LDR reading
****************************************************************************************************/
void ldr_swing_car(void)
{
    if(current_state==NORMAL){
            Get_LDRReads();
            motor_moveForward();
            ldr_diff = ldr2_buffer-ldr1_buffer;      /* ldr1--> right(PD2), ldr2--> left(PD3) */

            if(ldr_diff>500)
            {
                motor_moveLeft();
            }
            else if(ldr_diff<-1500)
            {
                motor_moveRight();
            }
            else
              {
                  /*for MISRA*/
              }
    }
    else
      {
          /*for MISRA*/
      }
}

/***************************************************************************************************
* Task Name: lcd_display
* Parameters (in): void
* Return value: void
* Description: Task to display temperature reading and current time on the LCD.
****************************************************************************************************/
void lcd_display(void)
{
//    LcdSendCommand(CLEAR_DISPLAY);
    LcdGoTo(ROW1, COL1);
    LcdSendString("Temp: ");
    Temp_sensorRead();
    LCDSendInt(TEMP);
    LcdGoTo(ROW2,COL1);

    LcdSendString("Time:");
    LcdSendString("  ");
    LcdGoTo(ROW2, COL6);
    LCDSendInt(g_currentTime_ms/1000);
}

/***************************************************************************************************
* Task Name: avoid_obstacles
* Parameters (in): void
* Return value: void
* Description: Task that uses ultrasonic sensor to detect and avoid obstacles.
****************************************************************************************************/
void avoid_obstacles(void)
{
    static uint8 steps_count=0;
    ultrasonicTrigger();
    switch(current_state)
    {
        case NORMAL:
            if(distance<= COLLISION_DISTANCE)
            {
                current_state=BACKWARD;
            }

            break;
        case BACKWARD:
            motor_moveBackward();
            if(distance>= AVOIDANCE_DISTANCE)
            {
                current_state=NINTY_ROTATION;
            }
            break;
        case NINTY_ROTATION:
            motor_moveRight();
            steps_count++;
            if(steps_count>15)
            {
                current_state=NORMAL;
                steps_count=0;
                motor_moveForward();
            }
            break;
        default:
            current_state=NORMAL;
            break;
    }
}

