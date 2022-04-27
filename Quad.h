#ifndef ROBORTOISE_QUAD_H
#define ROBORTOISE_QUAD_H

#include <Arduino.h>
#include <Servo.h>

#include "Leg.h"

enum LEG_INDEX {
    FL = 0,
    FR = 1,
    BL = 2,
    BR = 3,
};

class Quad {
    private:
        Leg leg_FL;
        Leg leg_FR;
        Leg leg_BL;
        Leg leg_BR;

    public:
    Quad();
    void init(struct Leg_pins pins[], struct Leg_seg_lims lims[][NUM_SEGS]);
};

#endif // ROBORTOISE_QUAD_H