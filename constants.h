#include "Quad.h"
#include "Leg.h"

enum LEG_PINS {
    HIP_FL = 27,
    KNEE_FL = 25,
    FOOT_FL = 23,
    
    HIP_FR = 30,
    KNEE_FR = 26,
    FOOT_FR = 28,

    HIP_BL = 52,
    KNEE_BL = 50,
    FOOT_BL = 48,

    HIP_BR = 49,
    KNEE_BR = 51,
    FOOT_BR = 53,
};

enum LIMS {
    FL_HIP_BKD = 150,
    FL_HIP_FWD = 90,
    FL_KNEE_LO = 120,
    FL_KNEE_HI = 40,
    FL_FOOT_LO = 120,
    FL_FOOT_HI = 45,

    FR_HIP_BKD = 140,
    FR_HIP_FWD = 180,
    FR_KNEE_LO = 70,
    FR_KNEE_HI = 160,
    FR_FOOT_LO = 30,
    FR_FOOT_HI = 140,

    BL_HIP_BKD = 90,
    BL_HIP_FWD = 30,
    BL_KNEE_LO = 40,
    BL_KNEE_HI = 150,
    BL_FOOT_LO = 30,
    BL_FOOT_HI = 130,

    BR_HIP_BKD = 90,
    BR_HIP_FWD = 155,
    BR_KNEE_LO = 130,
    BR_KNEE_HI = 30,
    BR_FOOT_LO = 130,
    BR_FOOT_HI = 35,
};

struct Leg_pins pins[] = {
    { // Leg_FL
        .hip_pin = HIP_FL,
        .knee_pin = KNEE_FL,
        .foot_pin = FOOT_FL,
    },
    { // Leg_FR
        .hip_pin = HIP_FR,
        .knee_pin = KNEE_FR,
        .foot_pin = FOOT_FR,
    },
    { // Leg_BL
        .hip_pin = HIP_BL,
        .knee_pin = KNEE_BL,
        .foot_pin = FOOT_BL,
    },
    { // Leg_BR
        .hip_pin = HIP_BR,
        .knee_pin = KNEE_BR,
        .foot_pin = FOOT_BR,
    }
};

struct Leg_seg_lims lims[][NUM_SEGS] = {
    {   // Leg_FL
        { .lo = FL_HIP_BKD, .hi = FL_HIP_FWD },    // hip
        { .lo = FL_KNEE_LO, .hi = FL_KNEE_HI },    // knee
        { .lo = FL_FOOT_LO, .hi = FL_FOOT_HI },    // foot
    },
    {   // Leg_FR
        { .lo = FR_HIP_BKD, .hi = FR_HIP_FWD },    // hip
        { .lo = FR_KNEE_LO, .hi = FR_KNEE_HI },    // knee
        { .lo = FR_FOOT_LO, .hi = FR_FOOT_HI },    // foot
    },
    {   // Leg_BL
        { .lo = BL_HIP_BKD, .hi = BL_HIP_FWD },    // hip
        { .lo = BL_KNEE_LO, .hi = BL_KNEE_HI },    // knee
        { .lo = BL_FOOT_LO, .hi = BL_FOOT_HI },    // foot
    },
    {   // Leg_BR
        { .lo = BR_HIP_BKD, .hi = BR_HIP_FWD },    // hip
        { .lo = BR_KNEE_LO, .hi = BR_KNEE_HI },    // knee
        { .lo = BR_FOOT_LO, .hi = BR_FOOT_HI },    // foot
    },
};
