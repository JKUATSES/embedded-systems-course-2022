//
// Created by USER on 5/20/2022.
//

#ifndef USART_H
#define USART_H

#ifndef BAUD       /*If not defined in makefile*/
#define BAUD 9600  /*set a default baud rate*/
#endif

#define USART_HAS_DATA bit_is_set(UCSR0A, RX0)
#define USART_READY bit_is_set(UCSR0A, UDRE0)

// takes the defined BAUD and F_CPU, calculates the bit-clock multiplier
// and configures the hardware USART
void initUSART();

// these are blocking functions at the moment
// th program hangs until data comes through
void transmitByte(int data);
int receiveByte();

// utility function to transmit an entire string from RAM
void printString(const char myString[]);


#endif // USART_H
