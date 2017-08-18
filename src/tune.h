#pragma once

#include "pin.h"

#define NOTE_PAUSE 1
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_C5S 554
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698

typedef unsigned int Tune[];

void play_note(Pin pin, unsigned int frequency);
void play_tune(Pin pin, Tune tune);
