#pragma once

#include "output_interface.h"
#include "../data_type.h"

class Servo;

class ServoLeaver : public OutputInterface {

public:
    ~ServoLeaver() override = default;

    explicit ServoLeaver(const ServoConfig & config);

    void play_intro() override;

    void set_position(ServoPosition value);

private:
    void setup();
    const ServoConfig & config_;
    Servo * servo_;

};

