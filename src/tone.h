#pragma once

#include <stdbool.h>

void tone(unsigned int frequency, unsigned int duration);
void stop_tone();
void process_tone();
bool is_playing();
