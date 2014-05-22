/*==============================================================================
        Project: Count
        Version: 3.1				Date: December 1, 2013
        Target: CHRP3				Processor: PIC16F886

        A simple binary count program that demonstrates the use of included
        header and system files, and also the use of Port B as a register.
==============================================================================*/

#include    "xc.h"              // XC compiler general include file

#include    "stdint.h"          // Integer definition
#include    "stdbool.h"         // Boolean (true/false) definition

#include    "system.h"          // User-created system-level functions
#include    "user.h"            // User-created variables and functions

/*==============================================================================
        Main program code
==============================================================================*/
unsigned char counter;
unsigned char counter2 = 0;
unsigned char bTrack = 0;
unsigned char i;
unsigned char bCheck = 0;

void Greet() { //Blink and Make greeting sound
    LED1 = 1;
    LED2 = 1;
    __delay_ms(100);
    LED1 = 0;
    LED2 = 0;
    __delay_ms(100);
    for (i = 10; i != 0; i--) {
        P1 = 0;
        __delay_us(1000);
        P1 = 1;
        __delay_us(1000);
    }
}

unsigned char IRPing(unsigned char pulses) {
    for (counter = pulses; counter != 0; counter--) {
        LED3 = 1;
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
        LED3 = 0;
        asm("nop");
        asm("nop");
    }
    if (U1 == 0)
        return 1; //if you see something return one
    else return 0;
}

int main(void) {
    // Configure the oscillator
    initOsc();

    // Initialize I/O and peripherals for PORTB output
    initPorts();


    while (1) {
        if (bTrack == 1) {//if S1 was pressed reset all values
            counter2 = 0;
            bCheck = 0;
            bTrack = 0;
        }
        while (IRPing(16) == 1) {//if you see the door is close
            __delay_ms(100); //just do the delay and remain asleep
        }
        counter2++; //increment to signify someone has been here
        while (counter2 == 1 && IRPing(16) == 0) { // as long as the door is open and it is the first time it has been opened
            __delay_ms(100);
            Greet(); //Greet the person
            if (S1 == 0) {//check if S1 is pressed
                __delay_ms(100);
                bTrack = 1; //denote that we have to reset since S1 was pressed
            } else
                bCheck++; //Keep incrementing to signify S1 wasn't pressed
        }
        if (bCheck != 0 && counter2 > 1 && bTrack != 1) { //Verify S1 wasn't pressed (bCheck and bTrack) also see if this was the second time the door has been open

            while (1) {// go into an infitine loop of alert!
                LED1 = 1;
                LED2 = 1;
                __delay_ms(100);
                LED1 = 0;
                LED2 = 0;
                __delay_ms(100);
                for (i = 30; i != 0; i--) {
                    P1 = 0;
                    __delay_us(5000);
                    P1 = 1;
                    __delay_us(3000);
                }
                if (S1 == 0) { // if S1 is pressed then reset everything and break out of this loop
                    bTrack = 1;
                    break;
                }
            }
        }


    }

}
