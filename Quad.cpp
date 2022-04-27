#include "Quad.h"

Quad::Quad() {

}

void Quad::init(struct Leg_pins pins[], struct Leg_seg_lims lims[][NUM_SEGS]) {
    leg_FL.init(pins[FL], lims[FL]);
    leg_FR.init(pins[FR], lims[FR]);
    leg_BL.init(pins[BL], lims[BL]);
    leg_BR.init(pins[BR], lims[BR]);

    legs[FL] = leg_FL;
    legs[FR] = leg_FR;
    legs[BL] = leg_BL;
    legs[BR] = leg_BR;

    leg_FL.hip_bkd();
    leg_FR.hip_bkd();
    leg_BL.hip_fwd();
    leg_BR.hip_fwd();
}

void Quad::set(int leg, int seg, float set) {
    Leg L = legs[leg];
    L.set(seg, set);
}

void Quad::stand() {
    set(FL, HIP, 0.5f);
    set(FL, KNEE, 0.0f);
    set(FL, FOOT, 0.0f);
    delay(500);

    set(BL, HIP, 1.0f);
    set(BL, KNEE, 0.1f);
    set(BL, FOOT, 0.0f);
    delay(500);

    set(BR, HIP, 0.5f);
    set(BL, HIP, 0.0f);
    set(BR, FOOT, 0.0f);
    set(BL, FOOT, 0.0f);
    delay(250);
    set(BR, KNEE, 0.0f);
    set(BL, KNEE, 0.0f);
}

void Quad::belly() {
    for (int i = 0; i < NUM_LEGS; i++) {
        Leg leg = legs[i];
        leg.knee_lift();
    }
}
