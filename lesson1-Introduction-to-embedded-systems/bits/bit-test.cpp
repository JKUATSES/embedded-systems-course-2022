
#include <avr/io.h>
#include <util/delay.h>

int main(){
    DDRB = 0xff; // set bit 4-7 as output

    while(1){
        // set pin 4 HIGH - OR
         PORTB = PORTB | (1<<7);

        // invert bit 5
        //PORTB = PORTB ^ (1<<5);

        // clear all bits
        // PORTB = PORTB & ~(0x00);

        // testing bits
        // test whether bit 4 is HIGH or LOW
        // create bit 4 mask
//        unsigned char bit_mask = (1<<4);
//
//        if((PORTB & bit_mask) == 0){
//            // you can do anything...
//            // switch on bit 7
//            PORTB |= (1<<7);
//        }

    }
}