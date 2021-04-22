#include "scene.h"
#include "utils.h"
#include "spike.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_spike(Spike* spike)
{
    load_model(&(spike->spike), "objects/spike.obj");
    spike->position.x=0.0;
    spike->position.y=-2.0;
    spike->position.z=-0.39999;
    //spike->spike_x=0.0;
    //spike->spike_y=-2.0;
    //spike->spike_z=-0.399999;
}

void draw_spike(Spike* spike)
{
    glPushMatrix();
    //set_material(&(scene->spike_material));
    glTranslatef(spike->position.x, spike->position.y, spike->position.z);
    draw_model(&(spike->spike));
    glPopMatrix();

}
