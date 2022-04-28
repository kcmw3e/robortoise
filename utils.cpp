#include "utils.h"

uint16_t frange(float f, uint16_t lo, uint16_t hi) {
    float range = (float)hi - (float)lo;

    if (f >= 1.0f) return hi;
    if (f <= 0.0f) return lo;
    
    float prop = f*range;
    return (uint16_t)(lo + prop);
}
