#include "os.h"

/* Enable IRQ Interrupts, This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()   __asm(" CPSIE I")

/* Disable IRQ Interrupts, This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()  __asm(" CPSID I")

static uint8 task_counter = 0;

volatile uint32 g_currentTime_ms = 0;
uint8 g_systick_newTick_flag = 0;

TaskControlBlock tasks[NUM_OF_TASKS];   /*array of structs that holds the tasks and their periodicity*/


/***************************************************************************************************
* Function Name: scheduler_init
* Parameters (in): void
* Return value: void
* Description: initializing the scheduler by applying the setup and the initializations
  needed for the hardware and by setting the call back function
****************************************************************************************************/
void scheduler_init(void)
{
    Enable_Interrupts();

/*setup and initializing the hardware*/
    MCAL_init();
    LcdInit();
    motorControl_init();
    ultrasonic_init();
    LDR_INIT();
    Temp_sensorInit();

/* Set the Call Back function to call OS_tickTime function
   this function will be called every SysTick Interrupt (every SYSTICK_TIMEOUT) */
    SysTick_SetCallBack(OS_tickTime);
}

/***************************************************************************************************
* Function Name: OS_tickTime
* Parameters (in): void
* Return value: void
* Description: this function will increment the function counter on each systick interrupt with
  the value equal to SYSTICK_TIMEOUT and this function sets a flag on each SysTick interrupt
****************************************************************************************************/
void OS_tickTime(void)
{
    g_currentTime_ms += SYSTICK_TIMEOUT;
    g_systick_newTick_flag = 1; /*this flag is set each systick interrupt*/
}

/***************************************************************************************************
* Function Name: create_task
* Parameters (in): void (*task)(void), uint32 task_period_ms
* Return value: void
* Description: this function is used to fill the array of structs with the desired tasks that
  the scheduler will execute based on the tasks' periodicity
****************************************************************************************************/
void create_task (void (*task)(void), uint32 task_period_ms)
{
    if(task_counter < NUM_OF_TASKS){
        tasks[task_counter].task_ptr = task;
        tasks[task_counter].task_periodicity = task_period_ms;
        task_counter++;
    }
    else
    {
        /*for MISRA*/
    }
}

/***************************************************************************************************
* Function Name: tasks_scheduler
* Parameters (in): void
* Return value: void
* Description: this function is responsible for deciding whether to start or stop the engine based
  on cheking switch0_flag and switch4_flag which are set by interrupts when pressing the kit buttons
****************************************************************************************************/
void tasks_scheduler(void)
{
    uint8 i;
    while(1)
    {
        /* starting the system condition */
        if(switch0_flag)
        {
            g_currentTime_ms = 0;
            systick_init();
            switch0_flag = 0;
        }
        else
          {
              /*for MISRA*/
          }

        /* stopping the system condition */
        if((switch4_flag==1) || (g_currentTime_ms >= 60000))
        {
            switch0_flag=0;
            g_currentTime_ms = 0;
            g_systick_newTick_flag = 0;
            motor_brakes();
            SysTick_Stop();

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
        else
          {
              /*for MISRA*/
          }

        if(g_systick_newTick_flag) /*checking the scheduling condition*/
        {
            for(i=0 ;i<task_counter;i++)
            {
                if(g_currentTime_ms%tasks[i].task_periodicity==0)   /*checking the matching condition between the task periodicity
                                                                       and the sysTick time*/
                {
                    tasks[i].task_ptr();
                }
                else
                {
                    /*for MISRA*/
                }
            }
            g_systick_newTick_flag=0;
        }
        else
          {
              /*for MISRA*/
          }
    }

}
