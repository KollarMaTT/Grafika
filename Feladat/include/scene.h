#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "map.h"
#include "field_element.h"
#include "spike.h"
#include "ball.h"
#include "cup.h"
#include "skybox.h"

#include <obj/model.h>

typedef struct Scene
{
    Map map;
    Field_element field_element1;
    Field_element field_element2;
    Field_element field_element3;
    Cup cup;
    Spike spike1;
    Spike spike2;
    Spike spike3;
    Ball ball;
    Skybox skybox;

    GLuint guide_id;
    GLuint lose_id;
    GLuint win_id;
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
void draw_scene(const Scene* scene);

/**
 * Reset the brightness of the scene.
 */
void reset_lights();

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();


#endif /* SCENE_H */
