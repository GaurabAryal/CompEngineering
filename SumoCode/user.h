/*==============================================================================
	User variable #define macros

	Set up (optional) user variables for user.c and main.c functions.
==============================================================================*/

// TODO User variable definitions used in user.c may go here.

// CHRP3 digital I/O pin names

#define Q1			RA0			// Phototransistor Q1 input
#define Q2			RA1			// Phototransistor Q2 input
#define VR1			RA2			// Potentiometer VR1 input
#define T1			RA3			// Temperature sensor T1 input
#define LED2		RA4			// Run LED, LED2 output
#define RunLED      RA4         // Run LED, LED2 output
#define LCDbacklight	RA4		// LCD backlight cathode output
#define VM			RA5			// Motor supply voltage divider input
#define Beeper		RA6			// Piezo beeper P1 output
#define P1			RA6			// Piezo beeper P1 output
#define LED12		RA7			// Floor/phototransistor LED, LED12 output

#define LED10		RB0			// LED10 output (LSB)
#define M1A			RB0			// Motor 1 A output
#define S2			RB0			// Switch S2 input
#define	LED9		RB1			// LED9 output
#define M1B			RB1			// Motor 1 B output
#define S3			RB1			// Switch S3 input
#define LED8		RB2			// LED8 output
#define M2A			RB2			// Motor 2 A output
#define	S4			RB2			// Switch S4 input
#define LED7		RB3			// LED7 output
#define M2B			RB3			// Motor 2 B output
#define S5			RB3			// Switch S5 input
#define LED6		RB4			// LED6 output
#define	S6			RB4			// Switch S6 input
#define LED5		RB5			// LED5 output
#define S7			RB5			// Switch S7 input
#define LED4		RB6			// LED4 output
#define LED3		RB7			// LED3 output (MSB)

#define LCDE		RC0			// LCD Enable output
#define Servo1		RC0			// Servo 1 output (external header)
#define LCDRW		RC1			// LCD Read/!Write output
#define	Servo2		RC1			// Servo 2 output (external header)
#define LCDRS		RC2			// LCD Register Select output
#define	Servo3		RC2			// Servo 3 output (external header)
#define Servo4		RC3			// Servo 4 output (external header)
#define LED11		RC6			// Communication/sensor LED, LED11 output
#define IR			RC7			// IR demodulator U5 input
#define U5			RC7			// IR demodulator U5 input

int initPorts(void);    // Hardware port configuration and user functions.
