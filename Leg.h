#ifndef ROBORTOISE_LEG_H
#define ROBORTOISE_LEG_H

#include <Arduino.h>

#include "utils.h"
#include "Seg.h"

#define NUM_SEGS 3

enum seg_index {
    HIP = 0,
    KNEE = 1,
    FOOT = 2,
};
typedef enum seg_index seg_index_t;

struct leg_pins {
    uint8_t hip_pin;
    uint8_t knee_pin;
    uint8_t foot_pin;
};
typedef struct leg_pins leg_pins_t;

struct leg_lims {
    seg_lims_t hip_lims;
    seg_lims_t knee_lims;
    seg_lims_t foot_lims;
};
typedef struct leg_lims leg_lims_t;

class Leg {
    private:
        Seg _hip;
        Seg _knee;
        Seg _foot;
        Seg _segs[NUM_SEGS];
        uint16_t test;

        Seg& _get_seg(seg_index_t i);

    public:
        Leg();
        void init(ADA_pwm_t pwm_driver, leg_pins_t pins, leg_lims_t lims);

        void set(seg_index_t seg, float set);
        void setall(float hipset, float kneeset, float footset);

        void Leg::fwd_hip();
        void Leg::bkd_hip();
        void Leg::lift_knee();
        void Leg::lower_knee();
        void Leg::lift_foot();
        void Leg::lower_foot();
};

#endif // ROBORTOISE_LEG_H