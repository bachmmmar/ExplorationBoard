#include <Arduino.h>
#include "usb_connection.h"


UsbConnection::UsbConnection(const UsbConnectionConfig & config) : config_(config) {
    setup();
}

void UsbConnection::setup() {
    pinMode(config_.detection_pin, INPUT_PULLUP);
};

bool UsbConnection::is_connected() {
    return !static_cast<bool>(digitalRead(config_.detection_pin));
}

