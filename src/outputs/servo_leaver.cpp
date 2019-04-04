#include <Arduino.h>
#include "servo_leaver.h"

#include <Servo.h>

ServoLeaver::ServoLeaver(const ServoConfig & config) :config_(config) {
    servo_ = new Servo();
    setup();
}

void ServoLeaver::play_intro() {
    set_position(left);
    delay(500);
    set_position(right);
    delay(800);
    set_position(center);
    delay(400);
}

void ServoLeaver::setup() {
    servo_->attach(config_.control_pin);
}

void ServoLeaver::set_position(ServoPosition value) {
    /*
    int pos;
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
    }
     */
    servo_->write(static_cast<int>(value));
}