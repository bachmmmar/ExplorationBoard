#include <Arduino.h>

#include "seven_segment_display.h"
#include "output_interface.h"


const uint8_t SevenSegmentDisplay::NUMBER_TO_SEGMENTS[10] = {0X3F, //Hex value to display the number 0
                                           0X06, //Hex value to display the number 1
                                           0X5B, //Hex value to display the number 2
                                           0X4F, //Hex value to display the number 3
                                           0X66, //Hex value to display the number 4
                                           0X6D, //Hex value to display the number 5
                                           0X7C, //Hex value to display the number 6
                                           0X07, //Hex value to display the number 7
                                           0X7F, //Hex value to display the number 8
                                           0X6F  //Hex value to display the number 9
                                           };


SevenSegmentDisplay::SevenSegmentDisplay(const SevenSegmentConfig & config) :config_(config) {
    setup();
}

void SevenSegmentDisplay::play_intro() {
    for (uint8_t i=0; i<8; i++) {
        digitalWrite(config_.pins[i], HIGH);
        delay(500);

        digitalWrite(config_.pins[i], LOW);
    }
}


void SevenSegmentDisplay::setup() {
    // Configure all required pins as output
    for (const uint8_t &pin : config_.pins) {
        pinMode(pin, OUTPUT);
    }
}

void SevenSegmentDisplay::set_value(uint8_t value) {
    if (value > 9) {
        return;
    }

    uint8_t segment_value = NUMBER_TO_SEGMENTS[value];
    for (uint8_t bit = 0; bit < 8; bit++) {
        uint8_t bit_value = (segment_value >> bit) & 0x01;
        digitalWrite(config_.pins[bit], bit_value);
    }

}
