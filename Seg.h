#ifndef ROBORTOISE_SEG_H
#define ROBORTOISE_SEG_H

#include <Arduino.h>

#include "utils.h"

struct seg_lims {
    uint16_t lo;
    uint16_t hi;
};
typedef struct seg_lims seg_lims_t;

class Seg {
    private:
        ADA_pwm_t _pwm_driver;
        uint8_t _pin;
        uint16_t _lo;
        uint16_t _hi;
        float _set;
    
    public:
        Seg();
        void init(ADA_pwm_t pwm_driver, uint8_t pin, seg_lims_t lims);
        void set(float set);
        float get();
};

#endif // ROBORTOISE_SEG_H
