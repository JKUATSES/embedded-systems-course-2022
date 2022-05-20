#ifndef AT2560_H
#define AT2560_H

// port B
#define PORTB (*(volatile unsigned char *) 0x25)
#define DDRB (*(volatile unsigned char *) 0x24)
#define PINB (*(volatile unsigned char *) 0x23)

// port C
#define PORTC (*(volatile unsigned char *) 0x28)
#define DDRC (*(volatile unsigned char *) 0x27)
#define PINC (*(volatile unsigned char *) 0x26)

// port D
#define PORTD (*(volatile unsigned char *) 0x2B)
#define DDRD (*(volatile unsigned char *) 0x2A)
#define PIND (*(volatile unsigned char *) 0x29)

// port H
#define PORTH (*(volatile unsigned char *) 0x102)
#define DDRH (*(volatile unsigned char *) 0x101)
#define PINH (*(volatile unsigned char *) 0x100)



#endif