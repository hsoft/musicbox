MCU ?= attiny45
# attiny85 goes up to 20mhz, but the chips coming out of the factory are apparently clocked at 1mhz
# by default.
F_CPU ?= 1000000UL

CC = avr-gcc
CFLAGS = -Os -Wall -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c
LDFLAGS = -mmcu=$(MCU)
OBJS = $(addprefix src/, main.o pin.o tone.o tune.o)
PROGNAME = musicbox

AVRDUDEMCU ?= t45
AVRDUDEARGS ?= -c usbtiny -P usb 

# Patterns

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Rules

.PHONY: send clean

all: $(PROGNAME).hex
	@echo Done!

send: $(PROGNAME).hex
	avrdude $(AVRDUDEARGS) -p $(AVRDUDEMCU) -U flash:w:$(PROGNAME).hex

clean:
	rm -f $(OBJS) $(PROGNAME).hex $(PROGNAME).bin

$(PROGNAME).bin: $(OBJS)
	$(CC) $(LDFLAGS) $+ -o $@

$(PROGNAME).hex: $(PROGNAME).bin
	avr-objcopy -O ihex -R .eeprom $< $@
