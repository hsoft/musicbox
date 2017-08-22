#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "pin.h"
#include "util.h"
#include "tone.h"
#include "tune.h"

#define PinPiezo PinB1
#define PinMagnet PinB2
#define PinSel1 PinB3
#define PinSel2 PinB4

// TuneNameX are defined in Makefile
// Note that all tunes must be in PROGMEM otherwise we'll smash our stack!
extern const Tune TuneName1;
extern const Tune TuneName2;
extern const Tune TuneName3;

static bool magnet_is_on = false;
static unsigned char note_index = 0;
static unsigned char tune_index = 0;

const Tune* select_tune()
{
    unsigned char new_tune_index;

    if (pinishigh(PinSel1)) {
        new_tune_index = 1;
    } else if (pinishigh(PinSel2)) {
        new_tune_index = 2;
    } else {
        new_tune_index = 0;
    }
    if (new_tune_index != tune_index) {
        note_index = 0;
        tune_index = new_tune_index;
    }
    switch (tune_index) {
        case 1: return &TuneName2;
        case 2: return &TuneName3;
        default: return &TuneName1;
    }
}

// Returns whether we should play a note
bool detect_reed_switch_change()
{
    if (pinishigh(PinMagnet)) {
        if (!magnet_is_on) {
            magnet_is_on = true;
            return true;
        }
    } else {
        magnet_is_on = false;
    }
    return false;
}

// Returns whether there's still a note to play after the one being played
unsigned int play_next_note()
{
    const Tune *tune;
    unsigned int note;

    tune = select_tune();
    note = pgm_read_word(&((*tune)[note_index]));
    tone(note, 200);
    note_index++;
    note = pgm_read_word(&((*tune)[note_index]));
    return note;
}

int main()
{

    sei();
    pinoutputmode(PinPiezo);

// The PLAY_ONCE mode is useful to debug new tunes
#ifdef PLAY_ONCE
    while (play_next_note()) {
        while (is_playing());
        _delay_ms(100);
    }
    note_index = 0;
#endif

    while (1) {
        if (detect_reed_switch_change()) {
            if (!play_next_note()) {
                note_index = 0;
            }
        }
    }
}
