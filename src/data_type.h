#pragma once

typedef enum OnOff: boolean {off=false, on=true};
typedef enum ServoPosition: uint8_t {left=0, center=90, right=180};

typedef enum ConnectedWire: uint8_t {None=0, One=1, Both=2};
typedef enum Switch: uint8_t {OFF, LEFT=1, RIGHT=2};
