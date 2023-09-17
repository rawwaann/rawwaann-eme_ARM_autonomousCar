

/* Declare static helper functions*/
static void delayMs(unsigned int delay);    /* Function to introduce a delay in milliseconds*/
static void sendEnablePulse();              /* Function to send the enable pulse to the LCD*/
static void lcdSetMode();

static unsigned char dataPorts[4];
static unsigned char dataPins[4];
