#pragma once

#include "../configuration.h"

class OutputInterface {

    public:

        virtual ~OutputInterface() = default;

        virtual void play_intro() = 0;

};
