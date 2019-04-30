#pragma once

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-array-member-paren-init"

#include <pins_arduino.h>


struct ConnectWireConfig {
    uint8_t analog_input_pin;
    uint8_t adc_resolution_bits;

    explicit ConnectWireConfig(uint8_t pin) : analog_input_pin(pin),
                                              adc_resolution_bits(10) {}
};

struct ToggleSwitchConfig {
    uint8_t left_pin;
    uint8_t right_pin;

    explicit ToggleSwitchConfig(uint8_t left, uint8_t right) : left_pin(left),
                                                               right_pin(right) {}
};

struct PushButtonConfig {
    uint8_t detection_pin;

    explicit PushButtonConfig(uint8_t pin) : detection_pin(pin) {}
};

struct ServoConfig {
    uint8_t control_pin;

    explicit ServoConfig(uint8_t pin) : control_pin(pin) {}
};

struct HddSpinnerConfig {
    uint8_t on_off_pin;
    unsigned long spinning_time_in_ms;

    explicit HddSpinnerConfig(uint8_t pin) : on_off_pin(pin), spinning_time_in_ms(6000) {}
};


struct OnOffSwitchConfig {
    uint8_t on_off_pin;

    explicit OnOffSwitchConfig(uint8_t pin) : on_off_pin(pin) {}
};

struct LedConfig {
    uint8_t led_pin;
    unsigned long fast_blinking_in_ms;
    unsigned long slow_blinking_in_ms;

    explicit LedConfig(uint8_t pin) : led_pin(pin),
                                      fast_blinking_in_ms(330),
                                      slow_blinking_in_ms(800) {}
};

struct MotorConfig {
    uint8_t motor_switch_pin;

    explicit MotorConfig(uint8_t pin) : motor_switch_pin(pin) {}
};

struct UsbConnectionConfig {
    uint8_t detection_pin;

    explicit UsbConnectionConfig(uint8_t pin) : detection_pin(pin) {}
};

struct CodedRotarySwitchConfig {
    uint8_t bit0_3_pins[4];
    unsigned long debounce_ms;

    explicit CodedRotarySwitchConfig(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3) :
        bit0_3_pins({pin0, pin1, pin2, pin3}),
        debounce_ms(30) {}
};

struct SevenSegmentConfig {
    uint8_t pins[8];

    explicit SevenSegmentConfig(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3,
                                uint8_t pin4, uint8_t pin5, uint8_t pin6, uint8_t pin7) :
            pins({pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7}) {}
};


struct BuzzerConfig {
    uint8_t pin;

    explicit BuzzerConfig(uint8_t buzzer_pin) : pin(buzzer_pin) {}
};

struct Configuration {
    PushButtonConfig push_button;
    CodedRotarySwitchConfig coded_rotary_switch;
    ToggleSwitchConfig toggle_switch;
    OnOffSwitchConfig on_off_switch;
    UsbConnectionConfig usb_connection;
    ConnectWireConfig connect_wire_red;
    ConnectWireConfig connect_wire_black;

    ServoConfig servo_pwm;
    HddSpinnerConfig hdd_spinner;
    SevenSegmentConfig seven_segment;
    MotorConfig motor;
    LedConfig connect_wire_red_led;
    LedConfig connect_wire_black_led;
    BuzzerConfig buzzer;

    Configuration() :
        push_button(48),
        coded_rotary_switch(8, 9, 10, 11),
        toggle_switch(46, 47),
        on_off_switch(52),
        usb_connection(49),
        connect_wire_red(A1),
        connect_wire_black(A0),
        servo_pwm(12),
        hdd_spinner(13),
        // seven_segment(5,4,2,1,0,6,7,3), // uno
        seven_segment(32, 30, 26, 24, 22, 34, 36, 28), // due
        motor(6),
        connect_wire_red_led(51),
        connect_wire_black_led(50),
        buzzer(7) {}
};


