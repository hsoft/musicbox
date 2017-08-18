#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "pin.h"
#include "util.h"
#include "tone.h"
#include "tune.h"

#define PinPiezo PinB2
#define PinMagnet PinB1

// TuneName is defined in Makefile
extern Tune TuneName;

int main()
{
    bool magnet_is_on = false;
    unsigned char tune_index = 0;

    pinoutputmode(PinPiezo);

    TCCR0B = 0;

    while (1) {
        if (pinishigh(PinMagnet)) {
            if (!magnet_is_on) {
                play_note(PinPiezo, TuneName[tune_index]);
                tune_index++;
                if (TuneName[tune_index] == 0) {
                    tune_index = 0;
                }
                magnet_is_on = true;
            }
        } else {
            magnet_is_on = false;
        }
    }
}
