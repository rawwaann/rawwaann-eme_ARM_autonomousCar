#include "./HAL/LCD/LCD_interface.h"
#include "./HAL/LCD/LCD_private.h"
#include "./HAL/LCD/LCD_config.h"
#include "MCAL/GPTM.h"

#include "./MCAL/GPIO/GPIO_interface.h"

#include <Utilities/std_types.h>


/* Initialize the LCD module*/
void LcdInit()
{
    dataPorts[0] = dataPin0Port;
    dataPorts[1] = dataPin1Port;
    dataPorts[2] = dataPin2Port;
    dataPorts[3] = dataPin3Port;
    
    dataPins[0] = dataPin0Pin;
    dataPins[1] = dataPin1Pin;
    dataPins[2] = dataPin2Pin;
    dataPins[3] = dataPin3Pin;
    
    /* Initialize the data port pins for output*/
    int i;
    for (i = 0; i < 4; ++i)
    {
        GPIO_Init_Port(dataPorts[i], 0x00, (1 << dataPins[i]));
    }
    GPIO_Init_Port(rsPort, 0x00, (1 << rsPin));
    GPIO_Init_Port(rwPort, 0x00, (1 << rwPin));
    GPIO_Init_Port(enPort, 0x00, (1 << enPin));

    GPIO_Write_Pins(rwPort, 1<<rwPin, 0x00);


    /* Initialize the LCD module*/
    lcdSetMode();

    /* Send commands to configure the LCD*/
    LcdSendCommand(LCD_DATA_MODE|DISPLAY_2_LINE|FONT_5X7); /* Set display mode to 2 lines, 4-bit, 5x7 dot*/
    LcdSendCommand(CURSOR_AUTO_SHIFT_RIGHT); /* Set cursor increment mode, no display shift*/
    LcdSendCommand(DISPLAY_ON); /* Turn on display, cursor, and blinking*/
    LcdSendCommand(CLEAR_DISPLAY); /* Clear display*/
}

/* Send a data byte to the LCD*/
void LcdSendData(char c)
{
    GPIO_Write_Pins(rsPort, (1 << rsPin), (1 << rsPin)); /* Set RS to indicate data*/

    /* Send the higher 4 bits of the data*/
    int i;
    for (i = 0; i < 4; ++i)
    {
        GPIO_Write_Pins(dataPorts[i], (1 << dataPins[i]), ((c >> (4+i))&1)<<dataPins[i]);
    }
    sendEnablePulse();

    /* Send the lower 4 bits of the data*/

    for (i = 0; i < 4; ++i)
    {
        GPIO_Write_Pins(dataPorts[i], (1 << dataPins[i]), ((c>>i) & 1)<<dataPins[i]);
    }
    sendEnablePulse();
}

/* Send a command byte to the LCD*/
void LcdSendCommand(char c)
{
    GPIO_Write_Pins(rsPort, (1<<rsPin), (0<<rsPin)); /* Clear RS to indicate command*/

    /* Send the higher 4 bits of the data*/
    int i;
    for (i = 0; i < 4; ++i)
    {
        GPIO_Write_Pins(dataPorts[i], (1 << dataPins[i]), ((c >> (4+i))&1)<<dataPins[i]);
    }
    sendEnablePulse();

    /* Send the lower 4 bits of the data*/

    for (i = 0; i < 4; ++i)
    {
        GPIO_Write_Pins(dataPorts[i], (1 << dataPins[i]), ((c>>i) & 1)<<dataPins[i]);
    }
    sendEnablePulse();
}

/* Send a string of characters to the LCD*/
void LcdSendString(char* str)
{
    int i = 0;
    for (i = 0; str[i] && (i < 16); ++i)
    {
        LcdSendData(str[i]);
    }
}

/* Function to introduce a delay in milliseconds*/
static void delayMs(unsigned int delay)
{
    int i, j;
    for (i = 0; i < delay; i++)
        for (j = 0; j < 3180; j++){} /* Delay*/
}

/* Function to send the enable pulse to the LCD*/
static void sendEnablePulse(void)
{
    GPIO_Write_Pins(enPort, 1<<enPin, (1<<enPin)); /* Set EN to high*/
    GPTM_delay_us(50); /* Delay for stability*/
    GPIO_Write_Pins(enPort, 1<<enPin, (0<<enPin)); /* Set EN to low*/
    GPTM_delay_us(50); /* Delay for stability*/
}

void LcdGoTo(unsigned char row, unsigned char col)
{
    LcdSendCommand(0x80 + (row * 0x40) + (col));
}

void LcdSaveCustomChar(unsigned char c[8], uint8 ID)
{
    LcdSendCommand(0x40 + ID*8);

    int i = 0;
    for(i = 0; i < 8; i++)
    {
        LcdSendData(c[i]);
    }

    LcdGoTo(ROW1, COL1);
}

static void lcdSetMode(void)
{
    if (LCD_DATA_MODE == MODE_4_BIT)
    {
        /* Set up the 4-bit data communication*/
        GPIO_Write_Pins(dataPorts[0], 1<<dataPins[0], 0); /* Set 4-bit mode*/
        GPIO_Write_Pins(dataPorts[1], 1<<dataPins[1], 0xFF); /* Set 4-bit mode*/
        GPIO_Write_Pins(dataPorts[2], 1<<dataPins[2], 0); /* Set 4-bit mode*/
        GPIO_Write_Pins(dataPorts[3], 1<<dataPins[3], 0); /* Set 4-bit mode*/
        sendEnablePulse();

    }
    else
    {

    }
}

void LCDSendInt(uint32 num)
{
    int j;
    char i = 0;
    char str[32];
    while(num != 0)
    {
        str[i] = num % 10;
        num = num/10;
        i++;
    }
    for(j = i-1; j >=0 ; j--)
        LcdSendData('0' + str[j]);
}
