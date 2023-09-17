#ifndef OS_OS_H_
#define OS_OS_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include <Utilities/std_types.h>
#include <HAL/ultrasonic.h>
#include <HAL/motor.h>
#include <HAL/LCD/LCD_interface.h>
#include <HAL/hal.h>
#include <HAL/temp_sensor.h>
#include <HAL/LDR.h>

/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/
#define LDR_PERIODICITY 160
#define ULTRASONIC_PERIODICITY 80
#define LCD_PERIODICITY 400
#define NUM_OF_TASKS 3

/*******************************************************************************
 *                               Type Definitions                              *
 *******************************************************************************/
typedef struct{
    void (*task_ptr)(void); /* function pointer to task which will be used to point to each task*/
    uint32 task_periodicity; /*task period will be used to indicate the task duration*/
}TaskControlBlock;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/***************************************************************************************************
* Function Name: scheduler_init
* Parameters (in): void
* Return value: void
* Description: initializing the scheduler by applying the setup and the initializations
  needed for the hardware and by setting the call back function
****************************************************************************************************/
void scheduler_init(void);

/***************************************************************************************************
* Function Name: OS_tickTime
* Parameters (in): void
* Return value: void
* Description: this function will increment the function counter on each systick interrupt with
  the value equal to SYSTICK_TIMEOUT and this function sets a flag on each SysTick interrupt
****************************************************************************************************/
void OS_tickTime(void);

/***************************************************************************************************
* Function Name: create_task
* Parameters (in): void (*task)(void), uint32 task_period_ms
* Return value: void
* Description: this function is used to fill the array of structs with the desired tasks that
  the scheduler will execute based on the tasks' periodicity
****************************************************************************************************/
void create_task (void (*task)(void), uint32 task_period_ms);

/***************************************************************************************************
* Function Name: tasks_scheduler
* Parameters (in): void
* Return value: void
* Description: this function is responsible for deciding whether to start or stop the engine based
  on cheking switch0_flag and switch4_flag which are set by interrupts when pressing the kit buttons
****************************************************************************************************/
void tasks_scheduler(void);

#endif /* OS_OS_H_ */
