

#include <avr/io.h>
#include "buttons.h"

int main(){
    // LED status. set PH5 as output
    DDRH |= (1 << PH5);
//    PORTH &= ~(1 << PH5);
    PORTH = 0X00;

    // using PORTJ for push button
    DDRJ = 0x00; // configure pins as input
    PORTJ = 0xff; // write all pins in PORTJ LOW

    DDRJ &= ~(1 << PJ0); // double-checking
    PORTJ |= (1 < PJ0); // enable the pull-up resistor

    while(true){
        if(PINJ & (1 << PJ0)){
            PORTH &= ~(1 << PH5); // turn on the LED
            lightLED();
        }
    }


}