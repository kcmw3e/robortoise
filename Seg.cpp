#include "Seg.h"

Seg::Seg() {

}

void Seg::init(ADA_pwm_t pwm_driver, uint8_t pin, seg_lims_t lims) {
    _pwm_driver = pwm_driver;
    _pin = pin;
    _lo = lims.lo;
    _hi = lims.hi;
    _set = 0.0f;
}

void Seg::set(float set) {
    _set = set;
    uint16_t pulselen = frange(_set, _lo, _hi);
    _pwm_driver.setPWM(_pin, 0, pulselen);
}

float Seg::get() {
    return _set;
}