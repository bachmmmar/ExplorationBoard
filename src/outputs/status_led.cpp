#include <Arduino.h>
#include "status_led.h"

#include "../timer/Timer.h"

#define NO_TIMER -1

StatusLed::StatusLed(const LedConfig & config, Timer * timer) : config_(config),
                                                                timer_(timer),
                                                                current_led_state_(false),
                                                                current_timer_id_(NO_TIMER),
                                                                led_mode(led_off){
    setup();
}

void StatusLed::play_intro() {
    stop_timer();
    set_led(true);
    current_timer_id_ = timer_->after(1200, toggle_callback, this);
}

void StatusLed::setup() {
    pinMode(config_.led_pin, OUTPUT);
    set_led(current_led_state_);
}

void StatusLed::blink_slow() {
    if (led_mode == led_blink_slow) {
        return;
    }
    led_mode = led_blink_slow;
    stop_timer();
    toggle();
    current_timer_id_ = timer_->every(config_.slow_blinking_in_ms, toggle_callback, this);
}


void StatusLed::blink_fast() {
    if (led_mode == led_blink_fast) {
        return;
    }
    led_mode = led_blink_fast;
    stop_timer();
    toggle();
    current_timer_id_ = timer_->every(config_.fast_blinking_in_ms, toggle_callback, this);
}

void StatusLed::off() {
    if (led_mode == led_off) {
        return;
    }
    led_mode = led_off;
    stop_timer();
    set_led(false);
}

void StatusLed::on() {
    if (led_mode == led_on) {
        return;
    }
    led_mode = led_on;
    stop_timer();
    set_led(true);
}

void StatusLed::toggle() {
    set_led(!current_led_state_);
}

void StatusLed::set_led(bool state) {
    current_led_state_ = state;
    digitalWrite(config_.led_pin, static_cast<uint8_t>(state));
}

void StatusLed::stop_timer() {
    if (current_timer_id_ != NO_TIMER) {
        timer_->stop(current_timer_id_);
        current_timer_id_ = NO_TIMER;
    }
}

void StatusLed::toggle_callback(void * ptr) {
    static_cast<StatusLed*>(ptr)->toggle();
}
