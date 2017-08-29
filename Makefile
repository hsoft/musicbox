MCU ?= attiny45
# attiny85 goes up to 20mhz, but the chips coming out of the factory are apparently clocked at 1mhz
# by default.
F_CPU ?= 1000000UL

AVRDUDEMCU ?= t45
AVRDUDEARGS ?= -c usbtiny -P usb 

TuneName1 ?= douce
TuneName2 ?= tortoise
TuneName3 ?= funkytown

OBJS = $(addprefix src/, main.o tone.o tune.o timer.o)
OBJS += $(addprefix common/, pin.o)
OBJS += $(addprefix src/tunes/, $(TuneName1).o $(TuneName2).o $(TuneName3).o)
PROGNAME = musicbox

CC = avr-gcc
EXTRACFLAGS ?= 
EXTRACFLAGS += -DTuneName1=$(TuneName1) -DTuneName2=$(TuneName2) -DTuneName3=$(TuneName3)
CFLAGS = -O3 -Wall $(EXTRACFLAGS) -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c
LDFLAGS = -mmcu=$(MCU)

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
