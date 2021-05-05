#include "scene.h"
#include "utils.h"
#include "cup.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_cup(Cup* cup)
{
    load_model(&(cup->model), "objects/cup.obj");
    
    cup->position.x=0.0;
    cup->position.y=-11.0;
    cup->position.z=0.22;


    cup->cup_material.ambient.red = 0.529412f;
    cup->cup_material.ambient.green = 0.423529f;
    cup->cup_material.ambient.blue = 0.227451f;

    cup->cup_material.diffuse.red = 0.980392f;
    cup->cup_material.diffuse.green = 0.768627f;
    cup->cup_material.diffuse.blue = 0.313725f;

    cup->cup_material.specular.red = 0.992157f;
    cup->cup_material.specular.green = 0.941176f;
    cup->cup_material.specular.blue = 0.807843f;
    

    cup->cup_material.shininess = 10.0f;
}

void draw_cup(Cup* cup)
{
    glPushMatrix();
    set_material(&(cup->cup_material));
    glTranslatef(cup->position.x, cup->position.y, cup->position.z);
    draw_model(&(cup->model));
    glPopMatrix();

}
