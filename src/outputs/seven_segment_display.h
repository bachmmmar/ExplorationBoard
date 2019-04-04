#pragma once

#include "output_interface.h"

class SevenSegmentDisplay : public OutputInterface {

public:

    ~SevenSegmentDisplay() override = default;

    explicit SevenSegmentDisplay(const SevenSegmentConfig & config);

    void play_intro() override;

    void set_value(uint8_t value);

private:
    void setup();

    const SevenSegmentConfig & config_;

    static const uint8_t NUMBER_TO_SEGMENTS[10];
};