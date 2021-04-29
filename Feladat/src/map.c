#include "scene.h"
#include "utils.h"
#include "map.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_map(Map* map)
{
    load_model(&(map->model), "objects/cube.obj");
    map->map_texture_id = load_texture("textures/grass.png");
    
    map->position.x=0.0;
    map->position.y=0.0;
    map->position.z=-0.9;

    map->map_material.ambient.red = 1.0f;
    map->map_material.ambient.green = 1.0f;
    map->map_material.ambient.blue = 1.0f;

    map->map_material.diffuse.red = 1.0f;
    map->map_material.diffuse.green = 1.0f;
    map->map_material.diffuse.blue = 1.0f;

    map->map_material.specular.red = 1.0f;
    map->map_material.specular.green = 1.0f;
    map->map_material.specular.blue = 1.0f;

    map->map_material.shininess = 0;
}

void draw_map(Map* map, float y)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, map->map_texture_id);
    set_material(&(map->map_material));
    glTranslatef(map->position.x, map->position.y-y, map->position.z);
    draw_model(&(map->model));
    glPopMatrix();
}
