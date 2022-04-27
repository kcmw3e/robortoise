#include "Leg.h"

int frange(float f, int lo, int hi);

Leg::Leg() {
    _hip = Servo();
    _knee = Servo();
    _foot = Servo();
}

void Leg::init(struct Leg_pins pins, struct Leg_seg_lims lims[NUM_SEGS]) {
    _hip.attach(pins.hip_pin);
    _knee.attach(pins.knee_pin);
    _foot.attach(pins.foot_pin);

    _hip_bkd = lims[HIP].lo;
    _hip_fwd = lims[HIP].hi;
    _knee_lower = lims[KNEE].lo;
    _knee_lift = lims[KNEE].hi;
    _foot_lower = lims[FOOT].lo;
    _foot_lift = lims[FOOT].hi;
}

void Leg::set(int seg, float set) {
    switch (seg) {
        case HIP: {
            _hip.write(frange(set, _hip_bkd, _hip_fwd));
            break;
        }
        case KNEE: {
            _knee.write(frange(set, _knee_lower, _knee_lift));
            break;
        }
        case FOOT: {
            _foot.write(frange(set, _foot_lower, _foot_lift));
            break;
        }
    }
}

void Leg::hip_fwd() {
    _hip.write(_hip_fwd);
}

void Leg::hip_bkd() {
    _hip.write(_hip_bkd);
}

void Leg::knee_lift() {
    _knee.write(_knee_lift);
}

void Leg::knee_lower() {
    _knee.write(_knee_lower);
}

void Leg::foot_lift() {
    _foot.write(_foot_lift);
}

void Leg::foot_lower() {
    _foot.write(_foot_lower);
}

void Leg::hip_relax() {
    set(HIP, 0.5);
}

void Leg::knee_relax() {
    set(KNEE, 0.5);
}

void Leg::foot_relax() {
    set(FOOT, 0.5);
}

void Leg::relax() {
    hip_relax();
    knee_relax();
    foot_relax();
}


int frange(float f, int lo, int hi) {
    float range = (float)hi - (float)lo;

    if (f >= 1.0f) return hi;
    if (f <= 0.0f) return lo;
    
    float prop = f*range;
    return (int)(lo + prop);
    
}