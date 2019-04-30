#pragma once

#include "output_interface.h"

class Timer;

class Buzzer  : public OutputInterface {

public:
    ~Buzzer() override = default;

    struct Tone {
        char note;

        // A "1" represents a quarter-note, 2 a half-note, etc.
        uint8_t beat;
        explicit Tone(char n, uint8_t b) :note(n), beat(b) {}
    };


    explicit Buzzer(const BuzzerConfig & config, Timer * timer);

    void play_intro() override;

    void play_melody1();

    void play_melody2();

    void play_melody3();

    void beep(uint8_t n, int tempo = 20);

private:
    void setup();

    void play_melody(const Tone * melody, int length);
    unsigned int frequency(char note);

    const BuzzerConfig & config_;
    Timer * timer_;

    int tempo_;

    int melody0_len_;
    const Tone melody0_[8];

    int melody1_len_;
    const Tone melody1_[18];

    int melody2_len_;
    const Tone melody2_[12];

    int melody3_len_;
    const Tone melody3_[20];

};

