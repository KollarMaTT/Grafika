#include "scene.h"
#include "utils.h"
#include "spike.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_spike(Spike* spike, float y, float z)
{
    load_model(&(spike->model), "objects/spike.obj");
    
    spike->position.x=0.0;
    spike->position.y=-y;
    spike->position.z=z;
    //spike->position.z=-0.299;

    spike->spike_material.ambient.red = 0.2745f;
    spike->spike_material.ambient.green = 0.01175f;
    spike->spike_material.ambient.blue = 0.01175f;

    spike->spike_material.diffuse.red = 0.71424f;
    spike->spike_material.diffuse.green = 0.04136f;
    spike->spike_material.diffuse.blue = 0.04136f;

    spike->spike_material.specular.red = 0.827811f;
    spike->spike_material.specular.green = 0.626959f;
    spike->spike_material.specular.blue = 0.626959f;

    spike->spike_material.shininess = 76.8f;
}

void draw_spike(Spike* spike)
{
    glPushMatrix();
    set_material(&(spike->spike_material));
    glTranslatef(spike->position.x, spike->position.y, spike->position.z);
    draw_model(&(spike->model));
    glPopMatrix();

}
