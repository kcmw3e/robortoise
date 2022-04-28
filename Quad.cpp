#include "Quad.h"

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define SERVO_OSCILLATORY_FREQ 27000000

Quad::Quad() {
    _pwm_driver = Adafruit_PWMServoDriver();

    _leg_FL = Leg();
    _leg_FR = Leg();
    _leg_BL = Leg();
    _leg_BR = Leg();
}

void Quad::init(quad_pins_t pins, quad_lims_t lims) {
    _pwm_driver.begin();
    _pwm_driver.setOscillatorFrequency(SERVO_OSCILLATORY_FREQ);
    _pwm_driver.setPWMFreq(SERVO_FREQ);

    _leg_FL.init(_pwm_driver, pins.FL_pins, lims.FL_lims);
    _leg_FR.init(_pwm_driver, pins.FR_pins, lims.FR_lims);
    _leg_BL.init(_pwm_driver, pins.BL_pins, lims.BL_lims);
    _leg_BR.init(_pwm_driver, pins.BR_pins, lims.BR_lims);

    _leg_FL.setall(0.0f, 1.0f, 1.0f);
    _leg_FR.setall(0.0f, 1.0f, 1.0f);
    _leg_BL.setall(1.0f, 1.0f, 1.0f);
    _leg_BR.setall(1.0f, 1.0f, 1.0f);
}

Leg& Quad::_get_leg(leg_index_t i) {
    switch (i) {
        case FL: return _leg_FL;
        case FR: return _leg_FR;
        case BL: return _leg_BL;
        case BR: return _leg_BR;
    }
}

void Quad::set(leg_index_t leg_i, seg_index_t seg_i, float set) {
    Leg leg = _get_leg(leg_i);
    leg.set(seg_i, set);
}

void Quad::stand() {
    for (int i = 0; i < NUM_LEGS; i++) {
        Leg leg = _get_leg((leg_index_t)i);
        leg.set(KNEE, 0.0f);
        leg.set(HIP, 0.5f);
        leg.set(FOOT, 0.5f);
    }
}

void Quad::belly() {
    for (int i = 0; i < NUM_LEGS; i++) {
        Leg leg = _get_leg((leg_index_t)i);
        leg.set(KNEE, 1.0f);
        leg.set(HIP, 0.5f);
        leg.set(FOOT, 0.0f);
    }
}

void Quad::lean(leg_index_t noload) {
    Leg* adj;
    Leg* caty;
    switch (noload) {
        case FL: {
            adj = &_leg_FR;
            caty = &_leg_BR;
            break;
        }
        case FR: {
            adj = &_leg_BL;
            caty = &_leg_FL;
            break;
        }
        case BL: {
            adj = &_leg_FR;
            caty = &_leg_BR;
            break;
        }
        case BR: {
            adj = &_leg_BL;
            caty = &_leg_FL;
            break;
        }
    }

    adj->set(FOOT, 1.0f);
    adj->set(KNEE, 0.3f);

    caty->set(FOOT, 1.0f);
    caty->set(KNEE, 0.5f);
}
