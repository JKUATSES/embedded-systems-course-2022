#include "usart.h"
#include <avr/io.h>
#include <util/setbaud.h>

void initUSART(){ /* requires baud. defined in setbaud.h*/
    UBRR0H = UBRRH_VALUE;
    UBRRH0L = UBRRL_VALUE;

    if(USE_2X){
        UCSR0A |= (1 << U2X0); // set the baud-rate double bit

    }else{
        UCSR0A &= ~(1 << U2X0); // toggle the baud-rate double bit
    }

    UCSR0B = (1 << TXEN0) | (RXEN0); // enable TX and RX

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // define data length. 8 data bits, 1 stop bit

}

void transmitByte(int data){
    loop_until_bit_is_set(UCSR0A, UDRE0); // wait for empty transmit buffer
    UDR0 = data;
}

int receiveByte(){
    loop_until_bit_is_set(UCSR0A, RXC0); // wait for incoming data
    return UDR0; // return register value
}

void printString(const char myString[]){
    int i = 0;
    while(myString[i]){
        transmitByte(myString[i]);
        i++;
    }

}


