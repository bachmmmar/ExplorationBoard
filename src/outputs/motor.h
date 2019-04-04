#pragma once

#include "output_interface.h"

class Motor : public OutputInterface {

public:
    ~Motor() override = default;

    explicit Motor(const MotorConfig & config);

    void play_intro() override;

    void turn(OnOff value);

private:
    void setup();
    const MotorConfig & config_;
};

