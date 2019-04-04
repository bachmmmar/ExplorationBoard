#pragma once

#include "output_interface.h"

class Timer;

class HddSpinner : public OutputInterface {

public:
    ~HddSpinner() override = default;

    explicit HddSpinner(const HddSpinnerConfig & config, Timer * timer);

    void play_intro() override;

    void start_spinning();

private:
    void setup();

    static void stop_spinning_callback(void *);
    void stop_spinning();

    const HddSpinnerConfig & config_;
    Timer * timer_;
    bool is_spinning_;

};

