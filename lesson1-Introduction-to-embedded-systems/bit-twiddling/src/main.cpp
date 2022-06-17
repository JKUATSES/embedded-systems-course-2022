
// vs code + platformio
// clion  + platformio
// clion + avr-gcc
// vscode + avr-gcc


#include "at2560.h"
#define  LED_MASK (1<<5)
#define  SENSOR_Y_MASK (0x00)
#define SET_HIGH 0xff
#define CLEAR 0x00

// 0111 1000

int main(){
    DDRH = 0xff; // set a bit as output

    // clear all bits
    PORTH &= CLEAR;

    // event loop
    while(true) {
        // run forever
        // set upper nibble high
        PORTH |= SET_HIGH;
    }

}
