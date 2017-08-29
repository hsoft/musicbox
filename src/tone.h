#pragma once

#include <stdbool.h>
#include "../common/pin.h"

void tone(Pin pin, unsigned int frequency, unsigned int duration);
void stop_tone();
void process_tone();
bool is_playing();
