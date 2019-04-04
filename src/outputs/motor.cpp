#include <Arduino.h>
#include "motor.h"


Motor::Motor(const MotorConfig & config) :config_(config) {
    setup();
}

void Motor::play_intro() {
    turn(on);
    delay(2000);
    turn(off);
}

void Motor::setup() {
    pinMode(config_.motor_switch_pin, OUTPUT);
}

void Motor::turn(OnOff value) {
    digitalWrite(config_.motor_switch_pin, value);
}