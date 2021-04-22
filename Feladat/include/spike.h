#ifndef SPIKE_H
#define SPIKE_H

#include <utils.h>
#include <camera.h>

#include <obj/model.h>

/**
 * Spike
 */
typedef struct Spike
{
    Model spike;
    //Material spike_material;
    //float spike_x;
    //float spike_y;
    //float spike_z;
    vec3 position;
} Spike;

void init_spike(Spike* spike);

void draw_spike(Spike* spike);

#endif /* SPIKE_H */