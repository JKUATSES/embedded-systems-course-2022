#include "atmega2560.h"

void setup(){
    // set PORTB for output
    *DDRB = 0b11110000;

    // write HIGH to the first nibble
    *PORTB = 0b1111000;
}

void loop(){

}