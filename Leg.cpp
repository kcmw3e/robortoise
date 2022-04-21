#include "Leg.h"

Leg::Leg() {
    _hip = Servo();
    _knee = Servo();
    _foot = Servo();
}

void Leg::init(int hip_pin, int knee_pin, int foot_pin, const int calib[]) {
    _hip.attach(hip_pin);
    _knee.attach(knee_pin);
    _foot.attach(foot_pin);

    _hip_fwd = calib[0];
    _hip_bkd = calib[1];
    _knee_lift = calib[2];
    _knee_lower = calib[3];
    _foot_lower = calib[4];
    _foot_lower = calib[5];

    
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