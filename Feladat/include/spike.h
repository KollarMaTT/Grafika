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
    Model model;
    vec3 position;
    Material spike_material;
} Spike;

/**
 * Initialize the spike object.
 */
void init_spike(Spike* spike, float y, float z);

/**
 * Draw the spike object.
 */
void draw_spike(Spike* spike);

#endif /* SPIKE_H */