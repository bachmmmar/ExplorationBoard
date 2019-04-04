#pragma once

#include "input_interface.h"

class UsbConnection : public InputInterface {

public:

    ~UsbConnection() override = default;

    explicit UsbConnection(const UsbConnectionConfig & config);

    bool is_connected();

private:
    void setup();

    const UsbConnectionConfig & config_;
};
