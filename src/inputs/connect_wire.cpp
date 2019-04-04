#include <Arduino.h>

#include "connect_wire.h"


ConnectWire::ConnectWire(const ConnectWireConfig & config) : config_(config) {
    setup();
}

void ConnectWire::setup() {
    // assuming 10k pulldown and 2 pins with 10k to max voltage
    int max_value = 1 << config_.adc_resolution_bits;
    int steps = max_value / (6*2);

    // nothing connected is zero to one third
    nothing_connected_threshold_ = steps *2*2;

    // from one third to 4/6 (7/12)
    one_connected_threshold_ = steps*(4+3);

}

ConnectedWire ConnectWire::get_connected_wires() {
    int analog = analogRead(config_.analog_input_pin);

    ConnectedWire value;

    if (analog < nothing_connected_threshold_) {
        value = None;
    }
    else if (analog < one_connected_threshold_) {
        value = One;
    } else {
        value = Both;
    }

    return value;
}
