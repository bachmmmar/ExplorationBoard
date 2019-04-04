#pragma once

#include "input_interface.h"

class CodedRotarySwitch : public InputInterface {

public:
    ~CodedRotarySwitch() override = default;

    explicit CodedRotarySwitch(const CodedRotarySwitchConfig & config);

    uint8_t get_value();

private:
    void setup();

    const CodedRotarySwitchConfig & config_;

};



