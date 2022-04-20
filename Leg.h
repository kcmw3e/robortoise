#ifndef ROBORTOISE_LEG_H
#define ROBORTOISE_LEG_H

#include <Arduino.h>
#include <Servo.h>

class Leg {
    private:
        Servo _hip;
        Servo _knee;
        Servo _foot;

    public:
    Leg(int hip_pin, int knee_pin, int foot_pin);
    void set_hip(int angle);
    void set_knee(int angle);
    void set_foot(int angle);
};

#endif // ROBORTOISE_LEG_H