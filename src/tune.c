#include "tune.h"
#include <util/delay.h>
#include "tone.h"

void play_note(Pin pin, unsigned int frequency)
{
    if (frequency > NOTE_PAUSE) {
        tone(pin, frequency, 200);
    }
}

