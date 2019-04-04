#pragma once

#include "input_interface.h"

class ToggleSwitch : public InputInterface {

public:

    ~ToggleSwitch() override = default;

    explicit ToggleSwitch(const ToggleSwitchConfig & config);

    Switch get_position();

private:
    void setup();

    const ToggleSwitchConfig & config_;
};
