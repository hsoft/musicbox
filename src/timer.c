#include "timer.h"
#include <avr/io.h>

// "ticks" is the number of clock cycles we want our timer to last
// Returns whether we could find a suitable Target (whether "ticks" fits in the timer)
bool set_timer0_target(unsigned long ticks)
{
    unsigned char prescaler_shifts[5] = {0, 3, 6, 8, 10};
    unsigned char prescaler_bits[5] = {0b001, 0b010, 0b011, 0b100, 0b101};
    unsigned char prescaler_index;

    if (ticks == 0) {
        // Stop the timer.
        TCCR0B &= 0b11111000;
        OCR0A = 0;
        return true;
    }

    for (prescaler_index=0; prescaler_index<=5; prescaler_index++) {
        if (ticks >> prescaler_shifts[prescaler_index] <= 0xff) {
            break;
        }
    }
    if (prescaler_index > 5) {
        return false;
    }
    // Set CS10, CS11 and CS12 according to our selected prescaler bits
    TCCR0B &= 0b11111000;
    TCCR0B |= prescaler_bits[prescaler_index];
    OCR0A = ticks >> prescaler_shifts[prescaler_index];
    return true;
}
