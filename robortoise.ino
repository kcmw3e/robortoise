#include "Leg.h"

// Leg 1: FWD_LEFT
// Leg 2: FWD_RIGHT
// Leg 3: BKD_RIGHT
// Leg 4: BKD_LEFT
enum LEG_PINS {
    HIP1 = 27,
    KNEE1 = 25,
    FOOT1 = 23,
    
    HIP2 = 30,
    KNEE2 = 26,
    FOOT2 = 28,

    HIP3 = 52,
    KNEE3 = 50,
    FOOT3 = 48,

    HIP4 = 49,
    KNEE4 = 51,
    FOOT4 = 53,
};

Leg leg1;
Leg leg2;
Leg leg3;
Leg leg4;
//                        hip      knee     foot
//                        -------------------------
//                        fw  bw   li  lo   li  lo
const int Leg1_calib[] = {90, 150, 40, 120, 45, 120};
const int Leg2_calib[] = {180, 140, 160, 70, 140, 30};
const int Leg3_calib[] = {30, 90, 150, 40, 130, 30};
const int Leg4_calib[] = {155, 90, 30, 130, 35, 130};

void setup() {
    leg1.init(HIP1, KNEE1, FOOT1, Leg1_calib);
    leg2.init(HIP2, KNEE2, FOOT2, Leg2_calib);
    leg3.init(HIP3, KNEE3, FOOT3, Leg3_calib);
    leg4.init(HIP4, KNEE4, FOOT4, Leg4_calib);

    leg3.hip_fwd();
    leg4.hip_fwd();

    leg1.knee_lower();
    leg2.knee_lower();
    leg3.knee_lower();
    leg4.knee_lower();
    
    leg1.foot_lower();
    leg2.foot_lower();
    leg3.foot_lower();
    leg4.foot_lower();

    Serial.begin(9600);
}

void loop() {
    leg1.knee_lift();
    leg1.foot_lift();
    delay(500);
    leg1.hip_fwd();
    delay(1000);
    leg1.knee_lower();
    leg1.foot_lower();
    delay(5000);
    
    leg1.knee_lift();
    leg1.foot_lift();
    delay(500);
    leg1.hip_bkd();
    delay(1000);
    leg1.knee_lower();
    leg1.foot_lower();
    delay(5000);
}
