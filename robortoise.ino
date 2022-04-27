#include "Quad.h"
#include "Leg.h"
#include "constants.h"

Quad robortoise;

void setup() {
    robortoise.init(pins, lims);

    Serial.begin(115200);
}

void loop() {
    robortoise.stand();
    delay(5000);
    robortoise.belly();
    delay(5000);
}
