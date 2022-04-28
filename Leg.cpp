#include "Leg.h"

Leg::Leg() {
    _hip = Seg();
    _knee = Seg();
    _foot = Seg();
}

void Leg::init(ADA_pwm_t pwm_driver, leg_pins_t pins, leg_lims_t lims) {
    _hip.init(pwm_driver, pins.hip_pin, lims.hip_lims);
    _knee.init(pwm_driver, pins.knee_pin, lims.knee_lims);
    _foot.init(pwm_driver, pins.foot_pin, lims.foot_lims);
    test = 5;
}

Seg& Leg::_get_seg(seg_index_t i) {
    switch (i) {
        case HIP: return _hip;
        case KNEE: return _knee;
        case FOOT: return _foot;
    }
}

void Leg::set(seg_index_t i, float set) {
    Seg seg = _get_seg(i);
    seg.set(set);
}

void Leg::setall(float hipset, float kneeset, float footset) {
    set(HIP, hipset);
    set(KNEE, kneeset);
    set(FOOT, footset);
}
