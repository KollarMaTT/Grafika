#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "spike.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Model ball;
    //Model spike;
    Material map_material;
    Material ball_material;
    Material spike_material;
    GLuint map_texture_id;
    GLuint ball_texture_id;
    GLuint guide_id;
} Scene;

/**
 * Measure of light changing.
 */
float lighting_changer;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Change the lighting of the scene.
 */
void set_lighting(float light);

/**
 * Set the lighting of the scene.
 */
void set_lighting_changer(float light);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene, Spike* spike);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();


#endif /* SCENE_H */
