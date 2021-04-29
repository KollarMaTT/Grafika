#ifndef FLAG_H
#define FLAG_H

#include <utils.h>
#include <camera.h>

#include <obj/model.h>

/**
 * Flag
 */
typedef struct Flag
{
    Model model;
    vec3 position;
    Material flag_material;
} Flag;

/**
 * Initialize the flag object.
 */
void init_flag(Flag* flag);

/**
 * Draw the flag object.
 */
void draw_flag(Flag* flag);

#endif /* FLAG_H */