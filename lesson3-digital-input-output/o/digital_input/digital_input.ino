/*

button connected to PD2
LEDs connected to PB0...PB7

*/

#include <Arduino.h>
#include <util/delay.h>
#include <avr/io.h>


int main(){

	PORTB |= (1<<5); // initialize pull up resistor on input pin
	DDRB = 0xf0;   // set all leds for output

	// event loop
	while(1){

		if(bit_is_clear(PINB, PB5)){ // if(PINB & (1<<PB2))
		    
		    // write the LEDs high
		    PORTB = 0b00000111;
		}else{
			PORTB = 0b00000000;
		}
	}

	return 0;
}

