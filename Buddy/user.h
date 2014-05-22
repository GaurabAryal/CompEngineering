/*==============================================================================
	Buddy symbolic constants for user.c and main.c functions.
==============================================================================*/

// TODO Add user constant definitions for in user.c and main.c here.
// These definitions give names to all CHRP 3 I/O port devices.

// PORTA I/O devices
#define P1		GP0		// Phototransistor Q1 input
#define LED3		GP1		// Phototransistor Q2 input
#define LED2            GP4
#define LED1            GP5
#define S1              GP3
#define U1              GP2

void initPorts(void);    // Hardware port configuration and user functions.
