#include <Arduino.h>
#include "push_button.h"


PushButton::PushButton(const PushButtonConfig & config) : config_(config) {
    setup();
}

void PushButton::setup() {
    pinMode(config_.detection_pin, INPUT_PULLUP);
};

bool PushButton::is_pushed() {
    return !static_cast<bool>(digitalRead(config_.detection_pin));
}

