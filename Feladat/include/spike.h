#ifndef SPIKE_H
#define SPIKE_H

#include "utils.h"

/**
 * Spike
 */
typedef struct Spike
{
    Model spike;
    //Material spike_material;
    float spike_x;
    float spike_y;
    float spike_z;
} Spike;

void init_spike(Spike* spike);

void draw_spike(Spike* spike);

#endif /* SPIKE_H */