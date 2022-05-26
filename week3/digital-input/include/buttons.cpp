#include "buttons.h"
#include <avr/io.h>

void lightLED(){
    PORTH |= (1 << PH5); // turn on the LED
}
