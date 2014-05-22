/*==============================================================================
        File: Input.c
        Version: 3.1				Date: April 17, 2013
        Target: CHRP3				Processor: PIC16F886

        A back and forth light chaser demonstrating port output, bit sensing using
        symbolic constants and the use of a hardware time delay function.
==============================================================================*/

#include    "xc.h"              // XC general include file

#include    "stdint.h"          // Integer definition
#include    "stdbool.h"         // Boolean (true/false) definition

#include    "system.h"          // User-created system-level functions
#include    "user.h"            // User-created variables and functions
#include    <stdlib.h>
/*==============================================================================
        Main program code
==============================================================================*/
#define BIT4    RB4
#define BIT7    RB7
unsigned char counter;

unsigned char IRPing(unsigned char pulses) { //Ping to check for enemy
    for (counter = pulses; counter != 0; counter--) {
        LED11 = 1;
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        LED11 = 0;
        asm("nop");
        asm("nop");
    }
    if (U5 == 0)
        return 1; //if you see something return one
    else return 0;
}

void lightshow() { //Light show for 5 seconds delay
    if (!BIT7 == 1) {
        PORTB = (PORTB << 1);
    } else {
        PORTB = 0b00010000;
    }
}

void snsfwd() {
    while (Q1 == 1 && Q2 == 1) {//If the bot is on the board
        if (IRPing() == 1) { // If you see someone
            PORTB = 0b00000110; //Go Foraward
        }
        if (IRPing() == 0) { //You see no one
            PORTB = 0b00000101; //keep turning -> Change
        }
    }
    if (Q1 == 0 || Q2 == 0) { //if the bot is seeing white completely
        PORTB = 0b00001001; //BackUp
        __delay_ms(1000);
    }
}

void doFive() { // Five seconds delay with light show
    int nCount = 4200;
    for (int i = 5; i != 0; i--) {
        while (nCount > 0) {
            Beeper = 1;
            __delay_us(100);
            Beeper = 0;
            __delay_us(100);
            nCount--;
        }
        nCount = 4420;
        lightshow();
    }

}

int main(void) {
    // Configure the oscillator
    initOsc();

    // Initialize I/O and peripherals
    initPorts();
    // Set starting conditions
    PORTB = 0b00010000; //prepare for 5 seconds delay
    while (S6 == 1); //wait till S6 is pressed
    doFive(); //do 5 seconds delay
    LED12 = 1;
    for (int i = 12; i > 0; i--) {//Jiggle back and forth to unfold our UberRamps
        PORTB = 0b00001001;
        __delay_ms(100);
        PORTB = 0b00000110;
        __delay_ms(100);
    }
    __delay_ms(1000);
    while (true) {
        snsfwd(); //call to do the main code forever
    }
}

