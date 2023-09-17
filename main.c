#include <APP/tasks.h>
int main(void);
int main(void)
{
    scheduler_init();

    /* creating 3 tasks:
       1- Task to swing the car based on the LDR.s [void ldr_swing_car(void)]
       3- Task to avoid obstacles based on the readings of the ultrasonic sensor. [void avoid_obstacles(void)]
       2- Task to display on the LCD. [void lcd_display(void)]
     */
    create_task(ldr_swing_car, LDR_PERIODICITY);
    create_task(avoid_obstacles, ULTRASONIC_PERIODICITY);
    create_task(lcd_display, LCD_PERIODICITY);

    tasks_scheduler();

    while(1){}
    return 0;
}

