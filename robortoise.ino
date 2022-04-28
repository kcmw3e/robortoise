#include "utils.h"
#include "Seg.h"
#include "Leg.h"
#include "Quad.h"
#include "constants.h"

#define GOPIN 53

bool go = false;

Quad robortoise;

void setup() {
    Serial.begin(115200);
    robortoise.init(pins, lims);
    robortoise.belly();
    pinMode(GOPIN, INPUT);
}

void loop() {
    int goread = digitalRead(GOPIN);
    if (goread == 0) go = true;
    
    if (go) {
        robortoise.stand();
        delay(2000);
        robortoise.stand();
        robortoise.lean(FL);
        delay(2000);
        robortoise.stand();
        robortoise.lean(FR);
        delay(2000);
        robortoise.stand();
        robortoise.lean(BL);
        delay(2000);
        robortoise.stand();
        robortoise.lean(BR);
        delay(2000);
    }
}
