
#ifndef MCAL_GPTM_H_
#define MCAL_GPTM_H_

/********************************************************************************************
 *                                includes                                                  *
 ********************************************************************************************/
#include <Utilities/Bitwise_Operations.h>
#include <Utilities/std_types.h>
#include <Tiva_Registers.h>
#include "DIO.h"

/************************************************************************************************
 *                               Definitions                                                    *
 ************************************************************************************************/
#define TIMER2  2
#define TAEN_bit 0
/*WTIMER2_CTL_R register pins*/
#define TAEVENT_bit1    2
#define TAEVENT_bit2    3
/*GPTMTMR register pins*/
#define TAMR0   0
#define TAMR1   1
#define TACMR   2
#define TACDIR   4
#define TICKS_FOR_MAX_DIST 0xFFFFFFFF
#define CAECINT 2 /*interrupt flag for Timer Module for Input Edge time Capture mode
                    in GPTMICR register*/
/*defines for one-shot timer mode*/
#define TIME_FACTOR_MILLI_SECONDS       16000
#define TIME_FACTOR_MICRO_SECONDS       16
/************************************************************************************************
 *                               extern variables                                               *
 ************************************************************************************************/
extern uint32 distance; /*used in avoid_obstacles task in tasks.c*/
extern uint8 g_current_time; /*used in ldr_swing_car task to stop the system when reaching
                               60 seconds and in lcd_display to display the time (in tasks.c)*/

/************************************************************************************************
 *                              Functions Prototypes                                            *
 ************************************************************************************************/

/*function prototypes for Input Edge time Capture mode */
void GPTM_ipEdgeTimeCapture_init(void);

/*function prototypes for one-shot timer mode*/
void GPTM_WTIMER1_oneShot_init(void);
void GPTM_delay_us(uint32 time);
void GPTM_delay_ms(uint32 time);

/*function prototypes for one-shot timer mode*/
void GPTM_WTIMER4_periodic_init(void);


#endif /* MCAL_GPTM_H_ */
