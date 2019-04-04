#include <Arduino.h>
#include "on_off_switch.h"


OnOffSwitch::OnOffSwitch(const OnOffSwitchConfig & config) : config_(config) {
    setup();
}

void OnOffSwitch::setup() {
    pinMode(config_.on_off_pin, INPUT_PULLUP);
};

bool OnOffSwitch::is_on() {
    return !static_cast<bool>(digitalRead(config_.on_off_pin));
}

