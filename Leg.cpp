#include "Leg.h"

Leg::Leg(int hip_pin, int knee_pin, int foot_pin) {
    _hip = Servo();
    _knee = Servo();
    _foot = Servo();

    _hip.attach(hip_pin);
    _knee.attach(knee_pin);
    _foot.attach(foot_pin);
}

void Leg::set_foot(int angle) {
    _foot.write(angle);
}

void Leg::set_knee(int angle) {
    _knee.write(angle);
}

void Leg::set_foot(int angle) {
    _foot.write(angle);
}