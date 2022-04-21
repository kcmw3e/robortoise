#ifndef ROBORTOISE_LEG_H
#define ROBORTOISE_LEG_H

#include <Arduino.h>
#include <Servo.h>

class Leg {
    private:
        Servo _hip;
        Servo _knee;
        Servo _foot;

        int _hip_fwd;
        int _hip_bkd;
        int _knee_lift;
        int _knee_lower;
        int _foot_lift;
        int _foot_lower;

    public:
    Leg();
    void init(int hip_pin, int knee_pin, int foot_pin, const int calib[]);

    void set_hip(int angle);
    void set_knee(int angle);
    void set_foot(int angle);

    void hip_fwd();
    void hip_bkd();
    void knee_lift();
    void knee_lower();
    void foot_lift();
    void foot_lower();

    void hip_relax();
    void knee_relax();
    void foot_relax();

    void relax();
};

#endif // ROBORTOISE_LEG_H