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
        delay(300);

        robortoise.set(FL, KNEE, 1.0f);
        robortoise.set(BR, KNEE, 1.0f);
        delay(150);
        robortoise.set(FL, HIP, 0.8f);
        robortoise.set(BR, HIP, 0.8f);
        delay(150);
        robortoise.set(FL, KNEE, 0.0f);
        robortoise.set(BR, KNEE, 0.0f);
        delay(300);
        robortoise.set(FR, KNEE, 0.2f);
        robortoise.set(BL, KNEE, 0.2f);
        delay(300);
        robortoise.stand();
        delay(200);
        
        robortoise.set(FR, KNEE, 1.0f);
        robortoise.set(BL, KNEE, 1.0f);
        delay(150);
        robortoise.set(FR, HIP, 0.8f);
        robortoise.set(BL, HIP, 0.8f);
        delay(150);
        robortoise.set(FR, KNEE, 0.0f);
        robortoise.set(BL, KNEE, 0.0f);
        delay(300);
        robortoise.set(FL, KNEE, 0.2f);
        robortoise.set(BR, KNEE, 0.2f);
        delay(300);
        robortoise.stand();
        delay(200);

        // robortoise.step(FL, 0.5f);
        // delay(500);
        // robortoise.step(BL, 0.5f);
        // delay(500);
        // robortoise.step(BR, 1.0f);
        // delay(500);
        // robortoise.step(FR, 0.0f);
        // delay(500);

        // robortoise.step(FR, 1.0f);
        // delay(1000);

        // robortoise.move(FL, 0.0f);
        // robortoise.move(FR, 0.5f);
        // robortoise.move(BL, 0.0f);
        // robortoise.move(BR, 0.5f);
        // robortoise.up();
        // delay(5000);
    }
}
