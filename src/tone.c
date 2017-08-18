#include "tone.h"
#include <avr/io.h>
#include <stdbool.h>

static volatile bool tone_was_interrupted = false;

/* frequency: hertz
 * duration: millis, 0 == forever, until with stop_tone() through an interrupt
 */
void tone(Pin pin, unsigned int frequency, unsigned int duration)
{
    unsigned long target_counter_reset;
    unsigned char prescaler_shifts[5] = {0, 3, 6, 8, 10};
    unsigned char prescaler_bits[5] = {0b001, 0b010, 0b011, 0b100, 0b101};
    unsigned char prescaler_index;
    unsigned int prescaled_counter_reset;
    unsigned long toggle_count;
    bool piezo_is_on = false;

    tone_was_interrupted = false;

    // We divide by 2 because our frequency represent a whole cycle (on, then off)
    target_counter_reset = F_CPU / frequency / 2;
    for (prescaler_index=0; prescaler_index<=5; prescaler_index++) {
        if (target_counter_reset >> prescaler_shifts[prescaler_index] <= 0xff) {
            break;
        }
    }
    prescaled_counter_reset = target_counter_reset >> prescaler_shifts[prescaler_index];
    toggle_count = 2 * (long)frequency * (long)duration / 1000;

    // Set CS10, CS11 and CS12 according to our selected prescaler bits
    TCCR0B &= 0b11111000;
    TCCR0B |= prescaler_bits[prescaler_index];

    while (1) {
        if (TCNT0 >= prescaled_counter_reset) {
            piezo_is_on = !piezo_is_on;
            pinset(pin, piezo_is_on);
            TCNT0 = 0;
            if (duration > 0) {
                toggle_count--;
                if (toggle_count == 0) {
                    break;
                }
            }
            else if (tone_was_interrupted) {
                tone_was_interrupted = false;
                break;
            }
        }
    }
    pinlow(pin);
}

void stop_tone()
{
    tone_was_interrupted = true;
}

