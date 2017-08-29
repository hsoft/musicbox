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
 * This is why I went with this interrupt approach. It's much faster and results in the proper tone
 * being output.
 *
 * An even cooler approach could be to put the timer into "pin toggling" mode, but I should have
 * thought of this before I soldered my whole board, because it turns out that the output pin for
 * timer0 is... PB0, an unsoldered pin. I could use timer1 instead of timer0, but it turns out
 * that it works differently from timer0 and I don't have the energy right now to learn about this
 * timer. Maybe later.
 */

static Pin piezo_pin;
static volatile unsigned long current_toggle_count = 0;

/* frequency: hertz
 * duration: millis
 */
void tone(Pin pin, unsigned int frequency, unsigned int duration)
{
    unsigned long target_counter_reset;

    piezo_pin = pin;

    // We divide by 2 because our frequency represent a whole cycle (on, then off)
    target_counter_reset = F_CPU / frequency / 2;

    set_timer0_target(target_counter_reset);
    // Enable CTC mode
    sbi(TCCR0A, WGM01);
    current_toggle_count = 2 * (long)frequency * (long)duration / 1000;

    // Enable interrupt on compare match on OCR0A.
    sbi(TIMSK, OCIE0A);
    TCNT0 = 0;

    pinlow(pin);
}

void stop_tone()
{
    cbi(TCCR0A, WGM01);
    cbi(TIMSK, OCIE0A);
    set_timer0_target(0);
    current_toggle_count = 0;
    pinlow(piezo_pin);
}

ISR(TIMER0_COMPA_vect)
{
    pintoggle(piezo_pin);
    current_toggle_count--;
    if (current_toggle_count == 0) {
        stop_tone();
    }
}

bool is_playing()
{
    return current_toggle_count;
}
