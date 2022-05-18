# Introduction

### Description
---
We are going to be using the ATMEGA328 Atmel MCU for this training. The sections below are short introductions to some core concepts.
<p>&nbsp;</p>

### Environment Setup
---
#### Software
1. Download and install [VS Code](https://code.visualstudio.com/)
2. Download and install [PlatformIO IDE](https://platformio.org/) for VS code

#### Hardware
1. Any Arduino Uno board but recommended is the Arduino Uno. Plus if you get the ATMEGA328P microcontroller itself also would be good.


### ATMEGA328 Architecture Overview
---
ATMEGA328 is a modified [Harvard architecture](https://www.geeksforgeeks.org/harvard-architecture/) 8-bit RISC Processor. The Atmel ATMEGA328 is equipped with 32 general purpose 8-bit registers that are tightly coupled to the processors ALU and CPU for faster instruction execution.
<p>&nbsp;</p>

The atmega328p has external connections for power supplies(VCC and GND), external time base inputs to drvie its clocks(XTAL1 and XTAL2), processor reset (active low RESET) and 4 8-bit ports (PA0-PA7, PB0-PB7, PC0-PC7, PD0-PD7), which arre used to interact with the external world.  
These ports may be used as GPIO or for alternate functions.   
The Atmeg328 also contains a timer subsystem, an ADC, an anlog caomparator, an interrupt system, a timing-subsytem, memory compnents, and extensive serial communication features. 



### C-Operator Sizing
---
When programming microcontrollers, it is important to know the number of bits used to store the variable and where the variable will be assigned. 
The following table shows type-sizing:
|Type| Size (bytes)|
|----|----|
|Unsigned char| 1|
|Signed char|1|
|Unsigned int|2|
|Signed int| 2|
|Float|4|
|Double|4|

For instance you cannot assign a 16-bit type to a 8-bit output port. The results will be unpredictable

### Bit Twiddling
Bit twiddling is basically manipulation of individual bits on a given port without affecting other bits. 
|Syntax| Description|Example|
|----|----|---|
|a\|b| bitwise OR | PORTA \|=0x80; // cturn on bit 7
|a&b| bitwise AND | PORTA &=0x81; // check bit 7 and bit 0
|a^b| bitwise Exclusive OR | PORTA^=0x80; // flip bit 7
|~a| bitwise Complement | PORTA &=~0x80; // turn off bit 7

You can read more [here](https://www.codementor.io/@erikeidt/bit-twiddling-understanding-bit-operations-iqj68ynb7).


# The PORT System
As stated above, the Atmega328 has 4 b-bit general purpose ports designated:  
1. PORTA
2. PORTB
3. PORTC
4. PORTD

In this section, we concetrate on the basic I/O port features. <br>
Each port has 3 registers associated with it:
1. Data Register PORTx -> Used to write data to the port
2. Data Direction Register(DDRx) -> Used to set a specific port pin to either output(1) or input(0)
3. Input Pin Address PINx -> Uses to read input data from the port. <br>

![Port System](../resources/port-system/port-system.jpg)

Note: Pins are usually configured at the start of a program. The DDRx is first used to set the pins pins as either input or output, then the data register (PORTx) is used to set the initial value of the output pins.

