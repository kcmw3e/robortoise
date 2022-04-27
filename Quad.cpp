#include "Quad.h"

Quad::Quad() {

}

void Quad::init(struct Leg_pins pins[], struct Leg_seg_lims lims[][NUM_SEGS]) {
    leg_FL.init(pins[FL], lims[FL]);
    leg_FR.init(pins[FR], lims[FR]);
    leg_BL.init(pins[BL], lims[BL]);
    leg_BR.init(pins[BR], lims[BR]);
}
