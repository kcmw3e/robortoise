#ifndef ROBORTOISE_QUAD_H
#define ROBORTOISE_QUAD_H

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#include "utils.h"
#include "Seg.h"
#include "Leg.h"

#define NUM_LEGS 4

enum leg_index {
    FL = 0,
    FR = 1,
    BL = 2,
    BR = 3,
};
typedef enum leg_index leg_index_t;

struct quad_pins {
    leg_pins_t FL_pins;
    leg_pins_t FR_pins;
    leg_pins_t BL_pins;
    leg_pins_t BR_pins;
};
typedef struct quad_pins quad_pins_t;

struct quad_lims {
    leg_lims_t FL_lims;
    leg_lims_t FR_lims;
    leg_lims_t BL_lims;
    leg_lims_t BR_lims;
};
typedef struct quad_lims quad_lims_t;

class Quad {
    private:
        ADA_pwm_t _pwm_driver;
        Leg _leg_FL;
        Leg _leg_FR;
        Leg _leg_BL;
        Leg _leg_BR;

        Leg& _get_leg(leg_index_t i);

    public:
        Quad();
        void init(quad_pins_t pins, quad_lims_t lims);
        void set(leg_index_t leg_i, seg_index_t seg_i, float set);
        void stand();
        void belly();
        void lean(leg_index_t noload);
};

#endif // ROBORTOISE_QUAD_H
