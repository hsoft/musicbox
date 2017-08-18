#include "tune.h"
#include <util/delay.h>
#include "tone.h"

static void pause()
{
    _delay_ms(300);
}

void play_note(Pin pin, unsigned int frequency)
{
    if (frequency == 0) {
        return;
    }
    else if (frequency == NOTE_PAUSE) {
        pause();
    } else {
        tone(pin, frequency, 200);
        _delay_ms(100);
    }
}

void play_tune(Pin pin, Tune tune)
{
    unsigned char i;

    for (i=0; ; i++) {
        if (tune[i] == 0) {
            break;
        } else {
            play_note(pin, tune[i]);
        }
    }
}


