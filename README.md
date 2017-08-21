# Electronic Music Box with AVR ATtiny45 controller

This repo will contains the schematics, assembly instructions, photos and source code for an
electronic version of a music box. The music is made with a Piezo and rotational movement detection
is made with a reed switch. It runs on two AAA batteries (rechargeable or not). It has a 3
positions selector to choose among 3 tunes to play.

[See it in action!](https://vimeo.com/230308935)

## Features

* Works like a real music box: turn the handle to play notes
* Can select among 3 tunes
* Runs on 2 AAA cells (2.5V)
* Less than 10$ in parts
* Only `avr-libc` is required to build executable

## Assembly

Refer to the [assembly instructions page](assembly/ASSEMBLY.md)

## How it works

The MPU contains some hardcoded tunes, that is, a list of notes (frequencies to play on the piezo)
and pauses. It continually polls pin B1 for state change, which happens when a magnet comes near
the reed switch or when it goes away. When the state changes, we play the next note on the tune
by starting to turn B2 low/high at the proper frequency: For example, if we want to play a A440,
we turn B1 low then high 440 times per second.

## Build the software

To build, you need a proper `avr-libc` setup, that is, `avr-gcc` and `avrdude`. You can run `make`
to build the code and `make send` to write it onto the chip through the AVR tiny programmer.

3 tunes among the ones in `src/tunes` are chosen through the `TuneNameX` makefile defines. You can
override them like this:

    TuneName2=othertune make

There is also a special `PLAY_ONCE` mode that makes the program play the first tune once on
initialization. It makes tune debugging much easier.

    EXTRACFLAGS="-DPLAY_ONCE" make

## Copyrights

Copyright 2017 Virgil Dupras
Licensed under the GPL, available in the `LICENSE` file of this repo.
