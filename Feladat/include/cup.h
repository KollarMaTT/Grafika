#ifndef CUP_H
#define CUP_H

#include <utils.h>
#include <camera.h>

#include <obj/model.h>

/**
 * Cup
 */
typedef struct Cup
{
    Model model;
    vec3 position;
    Material cup_material;
} Cup;

/**
 * Initialize the cup object.
 */
void init_cup(Cup* cup);

/**
 * Draw the cup object.
 */
void draw_cup(Cup* cup);

#endif /* CUP_H */