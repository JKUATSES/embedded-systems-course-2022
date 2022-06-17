/*
 * Read a character in serial from the keyboard, and play a note
 * see organ.h for pin defines and other macros
 * see organ.c for playNote() and rest()
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../include/organ.h"
#include "../include/pins.h"
#include "../include/usart.h"

#define NOTE_DURATION   0xf000
#define  G4     1043
#define  Gx4     984
#define  A4      929
#define  Ax4     877
#define  B4      827
#define  C5      781
#define  Cx5     737
#define  D5      696
#define  Dx5     657
#define  E5      620
#define  F5      585
#define  Fx5     552
#define  G5      521
#define  Gx5     492
#define  A5      464
#define  Ax5     438
#define  B5      414
#define  C6      390

int main(){

    // initialization
    SPEAKER_DDR |= (1 << SPEAKER);
    initUSART();
    printString("------Serial Organ-----");

    char fromCompy; // for store serial input
    uint16_t currentNoteLength = NOTE_DURATION;

    const uint8_t keys[] = {
            'a', 'b', 'c', 'd', 'd', 'e', 's',
            'r'
    };

    // set LED high

    const uint16_t notes[] = {
            G4, Gx4, A4,
            Ax4, B4, C5, Cx5,
            D5, Dx5, E5, F5,
            Fx5, G5, Gx5,
            A5, Ax5, B5, C6
    };

    uint8_t isNote;
    uint8_t i;

    // event loop
    while(true){
        fromCompy = receiveByte(); // wait here until there is input
        transmitByte('N'); // alert the computer we are ready for next note

        // play notes
        isNote = 0;
        for ( i = 0; i < sizeof(keys); i++) {
            if (fromCompy == keys[i]){
                // if we found match in lookup table
                playNote(notes[i], currentNoteLength);
                isNote = 1;   // record that we have found a note
                break;  // exit for() loop
            }
        }

        // handle non-note keys: tempo changes and rests

        if (!isNote){
            if (fromCompy == '['){ // code for short note
                currentNoteLength = NOTE_DURATION;
            } else if(fromCompy == ']'){  // code for long note
                currentNoteLength = NOTE_DURATION;
            }else{
                rest(currentNoteLength);
            }
        }

    }

    return 0;

}