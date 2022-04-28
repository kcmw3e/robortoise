#include <Arduino.h>

#include "Seg.h"
#include "Leg.h"
#include "Quad.h"

enum LEG_PINS {
    FL_HIP_PIN = 0,
    FL_KNEE_PIN = 1,
    FL_FOOT_PIN = 2,
    
    FR_HIP_PIN = 3,
    FR_KNEE_PIN = 4,
    FR_FOOT_PIN = 5,
    
    BL_HIP_PIN = 6,
    BL_KNEE_PIN = 7,
    BL_FOOT_PIN = 8,
    
    BR_HIP_PIN = 9,
    BR_KNEE_PIN = 10,
    BR_FOOT_PIN = 11,
};

leg_pins_t FL_pins = {
    .hip_pin = FL_HIP_PIN,
    .knee_pin = FL_KNEE_PIN,
    .foot_pin = FL_FOOT_PIN,
};

leg_pins_t FR_pins = {
    .hip_pin = FR_HIP_PIN,
    .knee_pin = FR_KNEE_PIN,
    .foot_pin = FR_FOOT_PIN,
};

leg_pins_t BL_pins = {
    .hip_pin = BL_HIP_PIN,
    .knee_pin = BL_KNEE_PIN,
    .foot_pin = BL_FOOT_PIN,
};

leg_pins_t BR_pins = {
    .hip_pin = BR_HIP_PIN,
    .knee_pin = BR_KNEE_PIN,
    .foot_pin = BR_FOOT_PIN,
};

enum LIMS {
    FL_HIP_LO = 450,
    FL_HIP_HI = 300,
    FL_KNEE_LO = 370,
    FL_KNEE_HI = 170,
    FL_FOOT_LO = 210,
    FL_FOOT_HI = 380,

    FR_HIP_LO = 405,
    FR_HIP_HI = 500,
    FR_KNEE_LO = 265,
    FR_KNEE_HI = 450,
    FR_FOOT_LO = 400,
    FR_FOOT_HI = 230,

    BL_HIP_LO = 350,
    BL_HIP_HI = 170,
    BL_KNEE_LO = 260,
    BL_KNEE_HI = 440,
    BL_FOOT_LO = 390,
    BL_FOOT_HI = 250,

    BR_HIP_LO = 300,
    BR_HIP_HI = 445,
    BR_KNEE_LO = 380,
    BR_KNEE_HI = 210,
    BR_FOOT_LO = 190,
    BR_FOOT_HI = 370,
};

leg_lims_t FL_lims = {
    .hip_lims = {
        .lo = FL_HIP_LO,
        .hi = FL_HIP_HI,
    },
    .knee_lims = {
        .lo = FL_KNEE_LO,
        .hi = FL_KNEE_HI,
    },
    .foot_lims = {
        .lo = FL_FOOT_LO,
        .hi = FL_FOOT_HI,
    },
};
leg_lims_t FR_lims = {
    .hip_lims = {
        .lo = FR_HIP_LO,
        .hi = FR_HIP_HI,
    },
    .knee_lims = {
        .lo = FR_KNEE_LO,
        .hi = FR_KNEE_HI,
    },
    .foot_lims = {
        .lo = FR_FOOT_LO,
        .hi = FR_FOOT_HI,
    },
};

leg_lims_t BL_lims = {
    .hip_lims = {
        .lo = BL_HIP_LO,
        .hi = BL_HIP_HI,
    },
    .knee_lims = {
        .lo = BL_KNEE_LO,
        .hi = BL_KNEE_HI,
    },
    .foot_lims = {
        .lo = BL_FOOT_LO,
        .hi = BL_FOOT_HI,
    },
};

leg_lims_t BR_lims = {
    .hip_lims = {
        .lo = BR_HIP_LO,
        .hi = BR_HIP_HI,
    },
    .knee_lims = {
        .lo = BR_KNEE_LO,
        .hi = BR_KNEE_HI,
    },
    .foot_lims = {
        .lo = BR_FOOT_LO,
        .hi = BR_FOOT_HI,
    },
};

quad_pins_t pins = {
    .FL_pins = FL_pins,
    .FR_pins = FR_pins,
    .BL_pins = BL_pins,
    .BR_pins = BR_pins,
};

quad_lims_t lims = {
    .FL_lims = FL_lims,
    .FR_lims = FR_lims,
    .BL_lims = BL_lims,
    .BR_lims = BR_lims,
};
