/*

button connected to PD2
LEDs connected to PB0...PB7

*/

#include <Arduino.h>
#include <util/delay.h>
#include <avr/io.h>


int main(){

	uint8_t button_was_pressed; // state
	PORTD |= (1<<2); // enable pull up on button Pin
	DDRB = (1<<2); // set up led pin for output

	// event loop
	while(1){

		if(bit_is_clear(PIND, PD2)){ // button is now pressed
			if(button_was_pressed == 0){
				// toggle LED (do something)
				PORTB ^= 0b00000010;
				button_was_pressed = 1; // update state
			}
		}else{
			// button is not pressed now
			// update the state
			button_was_pressed = 0;
		}

	}

	return 0;
}

