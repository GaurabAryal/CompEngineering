/*==============================================================================
	CHRP 3.1 user functions and hardware initialization/set-up.

	Initialize user constants in user.h and add user function code here.
==============================================================================*/

#include	"xc.h"				// XC compiler general include file

#include	"stdint.h"			// Integer definition
#include	"stdbool.h"			// Boolean (true/false) definition

#include	"user.h"			// For optional user variable definitions

void initPorts(void)
{
	// TODO Initialize ports and insert user functions here.

	// Initialize user ports  peripherals.

        CMCON0 = 7;
        ANSEL = 0b00010011;			// Make all PORTA pins digital I/O
        ADCON0 = 0b00000000;		// Set 4MHz conversion clock, A/D off,
        
	OPTION_REG = 0b10010111;	// PORTB pull-ups on, TMR0 internal div 256


	TRISIO = 0b00101011;			// Set runLED, IR LEDs as outputs in PORTA


	// Set starting I/O conditions.

	GPIO = 0;					// Turn off all PORTA outputs, turn on run LED

}
