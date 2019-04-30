#include "buzzer.h"

#include <Arduino.h>
#include "../TimerFreeTone/TimerFreeTone.h"

#include "../timer/Timer.h"

Buzzer::Buzzer(const BuzzerConfig &config, Timer *timer) : config_(config), timer_(timer),
        tempo_(57), //113
        melody0_({Tone('c',1), Tone('d',1), Tone('e',1), Tone('f',1), Tone('g',1), Tone('a',1), Tone('b',1), Tone('C',6)}),
        melody1_({Tone('c',1), Tone('d',1), Tone('f',1), Tone('d',1), Tone('a',1), Tone(' ',1),
                  Tone('a',4), Tone('g',4), Tone(' ',2),
                  Tone('c',1), Tone('d',1), Tone('f',1), Tone('d',1), Tone('g',1), Tone(' ',1),
                  Tone('g',4), Tone('f',4), Tone(' ',2)
                 }),
        melody2_({Tone('C',2), Tone('b',2), Tone('g',2), Tone('C',1), Tone('b',1), Tone('e',2), Tone(' ', 4),
                  Tone('C',2), Tone('c',2), Tone('g',2), Tone('a',1), Tone('C',1)
                }),
        melody3_({Tone('d',2), Tone('a',2), Tone('f',1), Tone('c',2), Tone('d',2), Tone('a',2), Tone('d', 2),
                  Tone('c',2), Tone('f',2), Tone('d',2), Tone('a',2), Tone('c',2), Tone('d',2), Tone('a', 2),
                  Tone('f',1), Tone('c',2), Tone('d',2), Tone('a',2), Tone('a',2), Tone('g',2)})

                 {
    melody0_len_ = sizeof(melody0_)/sizeof(*melody0_);
    melody1_len_ = sizeof(melody1_)/sizeof(*melody1_);
    melody2_len_ = sizeof(melody2_)/sizeof(*melody2_);
    melody3_len_ = sizeof(melody3_)/sizeof(*melody3_);
    setup();

}


void Buzzer::play_intro() {
    play_melody(melody0_, melody0_len_);
}

void Buzzer::play_melody(const Tone * melody, int length) {
    for (int i = 0; i < length; i++) {
        unsigned int duration = static_cast<unsigned int>(melody[i].beat) * static_cast<unsigned int>(tempo_);  // length of note/rest in ms
        if (melody[i].note == ' ') {         // is this a rest?
            delay(duration);            // then pause for a moment
        }
        else {                         // otherwise, play the note
            unsigned int f = frequency(melody[i].note);
            //tone(config_.pin, f, duration); // tone is not available for arduino due
            TimerFreeTone(config_.pin, f, duration);
            delay(duration);            // wait for tone to finish
        }
        delay(static_cast<unsigned long>(tempo_>>3));              // brief pause between notes
    }
}

void Buzzer::setup() {
    pinMode(config_.pin, OUTPUT);
}

void Buzzer::play_melody1() {
    play_melody(melody1_, melody1_len_);
}

void Buzzer::play_melody2() {
    play_melody(melody2_, melody2_len_);
}

void Buzzer::play_melody3() {
    play_melody(melody3_, melody3_len_);
}

void Buzzer::beep(uint8_t n, int tempo) {

    for (uint8_t i=0; i<n; i++) {
        TimerFreeTone(config_.pin, 440, static_cast<unsigned int>(tempo));
        delay(static_cast<unsigned int>(tempo*1.5));
    }
}

unsigned int Buzzer::frequency(char note) {
    // This function takes a note character (a-g), and returns the
    // corresponding frequency in Hz for the tone() function.
    int i;
    const int numNotes = 8;  // number of notes we're storing
    // The following arrays hold the note characters and their
    // corresponding frequencies. The last "C" note is uppercase
    // to separate it from the first lowercase "c". If you want to
    // add more notes, you'll need to use unique characters.
    // For the "char" (character) type, we put single characters
    // in single quotes.
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
    // Now we'll search through the letters in the array, and if
    // we find it, we'll return the frequency for that note.
    for (i = 0; i < numNotes; i++)  // Step through the notes
    {
        if (names[i] == note)         // Is this the one?
        {
            return(frequencies[i]);     // Yes! Return the frequency
        }
    }
    return(0);  // We looked through everything and didn't find it,
    // but we still need to return a value, so return 0.
}





