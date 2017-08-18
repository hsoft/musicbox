#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "pin.h"
#include "util.h"
#include "tone.h"
#include "tune.h"

#define PinPiezo PinB2
#define PinMagnet PinB1

static Tune tortoise_notes = {
    NOTE_E4,
    NOTE_F4,
    NOTE_G4,
    NOTE_PAUSE,
    NOTE_E5,
    NOTE_PAUSE,
    NOTE_C5,
    NOTE_PAUSE,

    NOTE_D5,
    NOTE_C5,
    NOTE_C5,
    NOTE_PAUSE,
    NOTE_B4,
    NOTE_PAUSE,
    NOTE_B4,
    NOTE_PAUSE,

    NOTE_D4,
    NOTE_E4,
    NOTE_F4,
    NOTE_PAUSE,
    NOTE_D5,
    NOTE_PAUSE,
    NOTE_B4,
    NOTE_PAUSE,

    NOTE_C5,
    NOTE_B4,
    NOTE_B4,
    NOTE_PAUSE,
    NOTE_A4,
    NOTE_PAUSE,
    NOTE_G4,
    NOTE_PAUSE,

    NOTE_E4,
    NOTE_PAUSE,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_PAUSE,
    NOTE_D5,
    NOTE_C5,
    NOTE_A4,
    NOTE_PAUSE,
    NOTE_D5,
    NOTE_E5,
    NOTE_F5,
    NOTE_PAUSE,
    NOTE_E5,
    NOTE_D5,
    NOTE_G4,
    NOTE_PAUSE,
    NOTE_F5,
    NOTE_PAUSE,
    NOTE_E5,
    NOTE_PAUSE,
    NOTE_D5,
    NOTE_PAUSE,
    NOTE_C5,
    NOTE_PAUSE,

    NOTE_G4,
    NOTE_PAUSE,
    NOTE_E4,
    NOTE_PAUSE,
    NOTE_G4,
    NOTE_PAUSE,
    NOTE_C4,
    0,
};
int main()
{
    bool magnet_is_on = false;
    unsigned char tune_index = 0;

    pinoutputmode(PinPiezo);

    TCCR0B = 0;

    while (1) {
        if (pinishigh(PinMagnet)) {
            if (!magnet_is_on) {
                play_note(PinPiezo, tortoise_notes[tune_index]);
                tune_index++;
                if (tortoise_notes[tune_index] == 0) {
                    tune_index = 0;
                }
                magnet_is_on = true;
            }
        } else {
            magnet_is_on = false;
        }
    }
}
