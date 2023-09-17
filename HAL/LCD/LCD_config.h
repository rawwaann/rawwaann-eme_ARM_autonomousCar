
/*
  Author:      Ehab Roshdy                                                                      
  Version:     0.1                                                                       
  Date:        21/8/2023                                                                             
  Description: LCD driver configuration file                                 
*/

#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#include <Utilities/std_types.h>
#include <MCAL/DIO.h>
//#include "LCD_interface.h"

#define LCD_DATA_MODE       MODE_4_BIT

static uint8 dataPin0Pin = 7;
static uint8 dataPin0Port = PORTD;

static uint8 dataPin1Pin = 2;
static uint8 dataPin1Port = PORTA;

static uint8 dataPin2Pin = 3;
static uint8 dataPin2Port = PORTA;

static uint8 dataPin3Pin = 4;
static uint8 dataPin3Port = PORTA;

static uint8 rsPin = 2;
static uint8 rsPort = PORTD;

static uint8 rwPin = 3;
static uint8 rwPort = PORTD;

static uint8 enPin = 3;
static uint8 enPort = PORTB;




#endif

