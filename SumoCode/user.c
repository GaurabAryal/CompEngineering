/*==============================================================================
	User functions and hardware initialization/set-up

	Initialize user variables in user.h and add user functions here.
==============================================================================*/

#include	"xc.h"				// XC general include file

#include	"stdint.h"			// Integer definition
#include	"stdbool.h"			// Boolean (true/false) definition

#include	"user.h"			// For optional user variable definitions

int initPorts(void)
{
	// TODO Insert user functions here.

	// Initialize user ports and peripherals.

	ANSEL = 0b00000000;			// Make all PORTA pins digital I/O
	ANSELH = 0b00000000;		// Make all PORTB pins digital I/O
	OPTION_REG = 0b01010111;	// PORTB pull-ups on, TMR0 interal div 256

	// Set port directions: 0 = Output, 1 = Input

	TRISA = 0b00101111;			// Set runLED, IR LEDs as outputs in PORTA
	TRISB = 0b00010000;			// Set PORTB for LED output, S2 and S3 input
	TRISC = 0b10110100;			// Set receive and transmit lines for IR
								// demodulator U5 and LED11, servo outputs

	// Set starting I/O conditions.

	PORTA = 0;					// Turn off all PORTA outputs, turn on run LED
	PORTB = 0;					// Turn off all PORTB LEDs
	PORTC = 0;					// Turn off all PORTC outputs

	// Enable interrupts, if needed.
}
