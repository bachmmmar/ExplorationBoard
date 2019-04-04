#pragma once

#include "input_interface.h"

class ConnectWire : public InputInterface {

public:
    ~ConnectWire() override = default;

    explicit ConnectWire(const ConnectWireConfig & config);

    ConnectedWire get_connected_wires();

private:
    void setup();

    const ConnectWireConfig & config_;

    int nothing_connected_threshold_;
    int one_connected_threshold_;
};
