# Electronic Music Box with AVR ATtiny45 controller

This repo will soon contain the schematics, assembly instructions, photos and source code for an
electronic version of a music box. The music is made with a Piezo and rotational movement detection
is made with a reed switch. It runs on two AAA batteries (rechargeable or not). It has a 4
positions selector to choose among 3 tunes to play.

## Parts

* ATtiny45-10PU (the `10` part is important so that we stay below the 2.5V requirement)
* 8 positions DIP IC socket
* Reed switch
* Piezo
* 3 positions rotary switch
* 2-cells AAA batteries holder
* SPST switch
* 10K resistor
* Perforated board. Mine is a 9x9 tiny perf board. Does the job
* Wires and connectors to your liking
* Something to wave magnets around
* A box to put all of this in

You will also need a Sparkfun AVR tiny programmer to use with `make send`. Otherwise, you'll need
to figure out how to write the program onto the chip yourself.

## How it works

The MPU contains some hardcoded tunes, that is, a list of notes (frequencies to play on the piezo)
and pauses. It continually polls pin B1 for state change, which happens when a magnet comes near
the reed switch or when it goes away. When the state changes, we play the next note on the tune
by starting to turn B2 low/high at the proper frequency: For example, if we want to play a A440,
we turn B1 low then high 440 times per second.

## Status

This is my first real electronics project and I've finally got to the point where I'm happy about
the cleanliness of my prototype, so I'm immortalizing it in this repo. For now, it lacks assembly
instructions/photos and I haven't actually implemented the rotary switch part yet, but it's coming.

## Build

To build, you need a proper `avr-libc` setup, that is, `avr-gcc` and `avrdude`. You can run `make`
to build the code and `make send` to write it onto the chip through the AVR tiny programmer.

## Copyrights

Copyright 2017 Virgil Dupras
Licensed under the GPL, available in the `LICENSE` file of this repo.
