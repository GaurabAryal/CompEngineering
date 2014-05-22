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

unsigned char TempSn = 0;
unsigned char i = 0;
unsigned char adConvert(unsigned char chan)
{
	ADON = 1;					// Turn on A-D converter
	ADCON0 = (ADCON0 & 0b11000011);	// Change the conversion channel by wiping
	ADCON0 = (ADCON0 | chan);		// CHS bits and ORing with selected channel
	NOP();
	NOP();
	GO_DONE = 1;				// Start the conversion

	while(GO_DONE);				// Wait for the conversion to finish

	ADON = 0;					// Turn A-D converter off and
	return (ADRESH);			// return result
}
/*==============================================================================
        Main program code
==============================================================================*/
unsigned char counter;

int main(void) {
    // Configure the oscillator
    initOsc();

    // Initialize I/O and peripherals for PORTB output
    initPorts();



    while (1) {
        
        if(adConvert(Trans1)>232){
            while (adConvert(TS)<0){
             for (i = 3; i!=0;i--){
                P1 = 1;
                __delay_us(1000);
                P1 = 0;
                __delay_us(1000);
                }
                __delay_ms(6000);
            }
            while (adConvert(TS)>0 && adConvert(TS)<15){
             for (i = 3; i!=0;i--){
                P1 = 1;
                __delay_us(1000);
                P1 = 0;
                __delay_us(1000);
                }
                __delay_ms(3500);
            }
            while (adConvert(TS)>15){
                 for (i = 3; i!=0;i--){
                    P1 = 1;
                    __delay_us(1000);
                    P1 = 0;
                    __delay_us(1000);
                    }
                    __delay_ms(1500);
                }
        }
      
    }

}
