#include "Leg.h"

// Leg 1: FWD_LEFT
// Leg 2: FWD_RIGHT
// Leg 3: BKD_RIGHT
// Leg 4: BKD_LEFT
enum LEG_PINS {
    HIP1 = 4,
    KNEE1 = 5,
    FOOT1 = 6,
    
    HIP2 = 7,
    KNEE2 = 8,
    FOOT2 = 9,

    HIP3 = 10,
    KNEE3 = 11,
    FOOT3 = 12,

    HIP4 = 13,
    KNEE4 = 14,
    FOOT4 = 15,
};

Leg leg1;
Leg leg2;
Leg leg3;
Leg leg4;

const int Leg1_calib[] = {80, 100, 80, 100, 80, 100};
const int Leg2_calib[] = {80, 100, 80, 100, 80, 100};
const int Leg3_calib[] = {80, 100, 80, 100, 80, 100};
const int Leg4_calib[] = {80, 100, 80, 100, 80, 100};

void setup() {
    leg1.init(HIP1, KNEE1, FOOT1, Leg1_calib);
    leg2.init(HIP2, KNEE2, FOOT2, Leg2_calib);
    leg3.init(HIP3, KNEE3, FOOT3, Leg3_calib);
    leg4.init(HIP4, KNEE4, FOOT4, Leg4_calib);
}

void loop() {
    leg1.knee_lift();
    delay(1000);
    leg1.hip_fwd();
    delay(1000);
    leg1.knee_relax();
    delay(2000);
    leg1.knee_lift();
    delay(1000);
    leg1.hip_relax();
    delay(1000);
    leg1.knee_relax();
    delay(1000);
}