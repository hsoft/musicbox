#include "tone.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "../common/pin.h"
#include "../common/util.h"
#include "timer.h"

/* Tone generation unit
 *
 * There are many constraints to consider when determining how we'll generate our tones, the most
 * important one being MCU speed. To maximize energy efficiency, we want to keep our MCU at 1MHz.
 * However, the MCU alone is not fast enough to toggle the piezo pin often enough to have the
 * proper sound.
 *
 * Well, actually it is... but it's complicated. The first version of this unit was very simple. To
 * play a tone, we would monopolize the MCU for the duration of the tone, toggling the piezo pin
 * using TCNT0 to know when to toggle.
 *
 * It worked well, but because it monopolized the MCU, the reed switch couldn't be monitored while
 * a tone played. Thus, it couldn't manage a fast-turning handle situation and missed notes.
 *
 * To fix this, I first tried an "event" approach where the main loop would read the reed switch
 * and then called a "process_tone()" function to continue toggling a tone if needed, but for
 * this approach, the MCU definitely wasn't fast enough. The tone was glitchy.
 *
 * Then there's the interrupt approach. The MCU can generate an interrupt on compare match. It's
 * much faster and results in the proper tone being output.
 *
 * But an even cooler approach is to put the timer into "pin toggling" mode. This way, the hardware
 * does all the work! The downside, however, is that it can only work on pin PB1 and on timer 1:
 * I haven't soldered PB0 and I don't want to mess with the board's soldering. But otherwise, it
 * works fine!
 *
 * This is only for frequency output. We've got to stop the tone at some point. To do so, we use
 * our second timer, time0 and tell it to generate an interrupt after the specified number of
 * millis. In that interrupt, we stop timer1. Easy!
 */

/* frequency: hertz
 * duration: millis
 */
void tone(unsigned int frequency, unsigned int duration)
{
    unsigned long target_counter_reset;

    // We consider frequencies in the 0-10 range "special". We don't output anything, but we still
    // acts as if we did for the specified duration. You can use this for pauses.
    if (frequency > 10) {
        // We divide by 2 because our frequency represent a whole cycle (on, then off)
        target_counter_reset = F_CPU / frequency / 2;

        set_timer1_target(target_counter_reset);
        // Enable pin toggling for pin OC1A (PB1)
        sbi(TCCR1, CTC1);
        sbi(TCCR1, COM1A0);
        TCNT1 = 0;
    }

    set_timer0_target((F_CPU / 1000) * duration);
    // Enable CTC mode
    sbi(TCCR0A, WGM01);
    // Enable interrupt on compare match on OCR0A.
    sbi(TIMSK, OCIE0A);
    pinlow(PinB1);
}

void stop_tone()
{
    cbi(TCCR1, COM1A0);
    set_timer1_target(0);
    pinlow(PinB1);
    set_timer0_target(0);
    cbi(TCCR0A, WGM01);
    cbi(TIMSK, OCIE0A);
}

ISR(TIMER0_COMPA_vect)
{
    stop_tone();
}

bool is_playing()
{
    return isset(TIMSK, OCIE0A);
}
