#pragma once

#include "output_interface.h"

class Timer;

class StatusLed : public OutputInterface {

public:
    ~StatusLed() override = default;

    explicit StatusLed(const LedConfig & config, Timer * timer);

    void play_intro() override;

    void blink_slow();
    void blink_fast();
    void off();
    void on();

private:
    typedef enum LedMode : uint8_t {led_off, led_on , led_blink_fast, led_blink_slow};
    void setup();
    void toggle();
    void set_led(bool state);

    void stop_timer();
    static void toggle_callback(void *);

    const LedConfig & config_;
    Timer * timer_;
    bool current_led_state_;
    int8_t current_timer_id_;
    LedMode led_mode;

};

