/*

button connected to PD2
LEDs connected to PB0...PB7

*/

#include <Arduino.h>
#include <util/delay.h>
#include <avr/io.h>

#define DEBOUNCE_TIME 1000	// varies with the button being used 


// debounce function
uint8_t debounce(void){
	if(bit_is_clear(PIND, PD2)){
	    _delay_us(DEBOUNCE_TIME); // wait for debounce to roll off
	    if(bit_is_clear(PIND, PD2)){
	        return(1);
	    }
	}

	return (0);
}

int main(){

	uint8_t button_was_pressed; // state
	PORTD |= (1<<2); // enable pull up on button Pin

	PORTH = 0x0f; // set port b for output
	DDRH = (1<<2); // set up led pin for output

	// event loop
	while(1){
		if(debounce){
		    if(button_was_pressed == 0){

		        // your code goes here
		        DDRH ^= (1<<2); // toggle LED
		        button_was_pressed = 1; // update the state

		    }
		} else{
			button_was_pressed = 0; // update the state
		}
	}

	return 0; // this line is never reached
}

//  ENABLE EXTERNAL PULL UPS

// ENABLE INTERNAL PULL UPS
// DEBOUNCE TIME - VARIES WITH MANUFACTURER
// CHCEK FOR BIT CHANGE 
