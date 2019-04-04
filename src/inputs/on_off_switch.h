#pragma once

#include "input_interface.h"

class OnOffSwitch : public InputInterface {

public:

    ~OnOffSwitch() override = default;

    explicit OnOffSwitch(const OnOffSwitchConfig & config);


    bool is_on();

private:
    void setup();

    const OnOffSwitchConfig & config_;
};
