#include <Arduino.h>
#include "coded_rotary_switch.h"


CodedRotarySwitch::CodedRotarySwitch(const CodedRotarySwitchConfig & config) : config_(config) {
    setup();
}

void CodedRotarySwitch::setup() {
    // Configure all required pins as input
    for (const uint8_t &pin : config_.bit0_3_pins) {
        pinMode(pin, INPUT_PULLUP);
    }
}


uint8_t CodedRotarySwitch::get_debounced_value() {
    uint8_t val;

    do {
        val = get_value();
        delay(config_.debounce_ms);
    } while(val != get_value());

    return val;
}

uint8_t CodedRotarySwitch::get_value() {
    uint8_t v = 0;
    for (uint8_t i=0; i<4; i++) {
        v += digitalRead(config_.bit0_3_pins[i]) << i;
    }

    const uint8_t mask = 0x0F;
    v = (~v) & mask;
    return v;
}

