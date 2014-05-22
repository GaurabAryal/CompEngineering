/*==============================================================================
	Buddy symbolic constants for user.c and main.c functions.
==============================================================================*/

// TODO Add user constant definitions for in user.c and main.c here.
// These definitions give names to all CHRP 3 I/O port devices.

// PORTA I/O devices
#define Trans1		GP0		// Phototransistor 
#define LED1		GP4		
#define LED2            GP2
#define P1              GP5
#define S1              GP3
#define TS              GP1

void initPorts(void);    // Hardware port configuration and user functions.
