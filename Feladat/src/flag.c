#include "scene.h"
#include "utils.h"
#include "flag.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_flag(Flag* flag)
{
    load_model(&(flag->model), "objects/flag.obj");
    
    flag->position.x=0.0;
    flag->position.y=-8.0;
    flag->position.z=0.35;

    flag->flag_material.ambient.red = 0.329412f;
    flag->flag_material.ambient.green = 0.223529f;
    flag->flag_material.ambient.blue = 0.027451f;

    flag->flag_material.diffuse.red = 0.780392f;
    flag->flag_material.diffuse.green = 0.568627f;
    flag->flag_material.diffuse.blue = 0.113725f;

    flag->flag_material.specular.red = 0.992157f;
    flag->flag_material.specular.green = 0.941176f;
    flag->flag_material.specular.blue = 0.807843f;

    flag->flag_material.shininess = 27.8974f;
}

void draw_flag(Flag* flag)
{
    glPushMatrix();
    set_material(&(flag->flag_material));
    glTranslatef(flag->position.x, flag->position.y, flag->position.z);
    draw_model(&(flag->model));
    glPopMatrix();

}
