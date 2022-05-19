#include "at2560.h"

void setup(){
  *DDRB = 0xf0; // set all pins as output
  *PINB = 0b01010000; // write high to pins

  // set bits

  // clear bits

  // check bits

  // toggle bits


}

void loop(){

  // blink LEDs

}