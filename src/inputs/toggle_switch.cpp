#include <Arduino.h>
#include "toggle_switch.h"


ToggleSwitch::ToggleSwitch(const ToggleSwitchConfig & config) : config_(config) {
    setup();
}

void ToggleSwitch::setup() {
    pinMode(config_.right_pin, INPUT_PULLUP);
    pinMode(config_.left_pin, INPUT_PULLUP);
};

Switch ToggleSwitch::get_position() {
    Switch v;

    if(!static_cast<bool>(digitalRead(config_.left_pin))) {
        v = LEFT;
    } else if(!static_cast<bool>(digitalRead(config_.right_pin))) {
        v = RIGHT;
    } else {
        v = OFF;
    }

    return v;
}

