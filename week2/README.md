## Serial Communication
---
### Working
---
For a very basic definition, for computers or ICs to communicate with each other, one device sends a signal by outputting HIGH and LOW voltage pulses on a wire that connects it to the other device. The rules for encoding data into voltage pulses and decoing voltage pulses back to data is called the ***Serial protocol***


### Protocols
---
We’ll limit ourselves to the most common serial mode—universal asynchronous receive and transmit (UART) serial
<br>
Consider the case where i need to send the digit 23 to a device. First I convert the decimal to binary   
```c
bin(23) = 0001 0111
```
If we decide to send the LSB first, the device will receive the following sequence:
```c
00001 01110
```

Note the additional 0 bit to indicate start and stop bit. There is also an additional parity bit commonly used on serial communication to detect errors. E.g checking if the number of 1's is odd or even, depending on your needs.

The following factors are very important in serial communication:
1. Baud rate
2. Start bit
3. Stop bit

The image below shows a typical waveform when transmitting serial data:
![Serial Graph](./imgs/serial-oscope.png)


### Registers used for serial communication
---
USART Communication uses 5 registers to enable serial communication functionality.The registers are:

1. UDRn - USART Data Register
2. UCSRnA - USART Control and Status Register A
3. UCSRnB - USART Control and Status Register B
4. UCSRnC - USART Control and Status Register C
5. UBRRnL and UBRRnH - USART Baud Rate Registers

The following snapshots show the stated registers.

1. UDRn - USART Data 
![UDRn](./imgs/UDRn.png)
2. UCSRnA - USART Control and Status Register A
![ucsra](./imgs/ucsra.png)
3. UCSRnB - USART Control and Status Register B
![ucsrb](./imgs/ucsrb.png)
4. UCSRnC - USART Control and Status Register C
![ucsrc](./imgs/ucsrc.png)
5. UBRRnL and UBRRnH - USART Baud Rate Registers
![ubrrl/ubrrh](./imgs/ubbr.png)

For more details on the register, please refer to the datasheet in the resources folder.


### Register Configuration
In this section we will show how you can configure the registers to start transmitting with your Atmel AVR microcontroller.



### Transmitting

### Receiving