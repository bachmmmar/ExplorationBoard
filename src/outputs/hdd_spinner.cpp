
#include <Arduino.h>
#include "hdd_spinner.h"

#include "../timer/Timer.h"

HddSpinner::HddSpinner(const HddSpinnerConfig & config, Timer * timer) :config_(config), timer_(timer),
    is_spinning_(false) {
    setup();
}


void HddSpinner::play_intro() {
    // ToDo implement intro
}

void HddSpinner::setup() {
    pinMode(config_.on_off_pin, OUTPUT);
}

void HddSpinner::start_spinning() {
    if (!is_spinning_) {
        is_spinning_ = true;
        timer_->after(config_.spinning_time_in_ms, stop_spinning_callback, this);
        digitalWrite(config_.on_off_pin, HIGH);
    }
}

void HddSpinner::stop_spinning_callback(void *ptr) {
    static_cast<HddSpinner*>(ptr)->stop_spinning();
}

void HddSpinner::stop_spinning() {
    is_spinning_ = false;
    digitalWrite(config_.on_off_pin, LOW);
}