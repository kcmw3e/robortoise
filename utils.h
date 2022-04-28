#ifndef ROBORTOISE_UTILS_H
#define ROBORTOISE_UTILS_H

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

uint16_t frange(float f, uint16_t lo, uint16_t hi);

typedef Adafruit_PWMServoDriver ADA_pwm_t;

#endif // ROBORTOISE_UTILS_H
