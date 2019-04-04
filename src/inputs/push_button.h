#pragma once

#include "input_interface.h"

class PushButton : public InputInterface {

public:

    ~PushButton() override = default;

    explicit PushButton(const PushButtonConfig & config);

    bool is_pushed();

private:
    void setup();

    const PushButtonConfig & config_;
};
