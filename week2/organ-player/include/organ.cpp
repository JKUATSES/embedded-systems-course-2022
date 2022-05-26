#include "organ.h"
#include "pins.h"
#include <avr/io.h>
#include <util/delay.h>

void playNote(uint16_t period, uint16_t duration){
    uint16_t elapsed;
    uint16_t i;

    for (int elapsed = 0; elapsed < duration; elapsed += duration) {
        for (int i = 0; i < period; i++) {
            _delay_us(1);
        }

        SPEAKER_PORT ^= (1 << SPEAKER);
    }
}

void rest(uint16_t duration){
    do {
        _delay_us(1);

    }while (--duration);
}