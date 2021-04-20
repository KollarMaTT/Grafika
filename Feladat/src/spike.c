#include "scene.h"
#include "utils.h"
#include "spike.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_spike(Spike* spike)
{
    load_model(&(spike->spike), "objects/spike.obj");

    spike->spike_x=0.0;
    spike->spike_y=-2.0;
    spike->spike_z=-0.399999;
}

void draw_spike(Spike* spike)
{
    glPushMatrix();
    //set_material(&(scene->spike_material));
    glTranslatef(spike->spike_x, spike->spike_y, spike->spike_z);
    draw_model(&(spike->spike));
    glPopMatrix();

}
