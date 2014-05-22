/*==============================================================================
	System variable #define macros

	Set up (optional) system variables for system.c functions.
==============================================================================*/

// TODO Set system frequency and define any variables used in system.c

#define _XTAL_FREQ		4000000			// Set xtal frequency for time delays
#define FCY				_XTAL_FREQ/4	// Set processor cycle time

int initOsc(void);		// Optional oscillator initialization functions.
