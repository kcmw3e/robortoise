#include "Leg.h"

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

    hip_bkd();
    knee_lift();
    foot_lift();
}

void Leg::set_hip(int angle) {
    _hip.write(angle);
}

void Leg::set_knee(int angle) {
    _knee.write(angle);
}

void Leg::set_foot(int angle) {
    _foot.write(angle);
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
    _hip.write(abs(_hip_bkd - _hip_fwd)/2);
}

void Leg::knee_relax() {
    _knee.write(abs(_knee_lift - _knee_lower)/2);
}

void Leg::foot_relax() {
    _foot.write(abs(_foot_lift - _foot_lower)/2);
}

void Leg::relax() {
    hip_relax();
    knee_relax();
    foot_relax();
}