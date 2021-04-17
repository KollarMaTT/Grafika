#include "scene.h"
#include "utils.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "objects/cube.obj");
    load_model(&(scene->ball), "objects/ball.obj");
    load_model(&(scene->spike), "objects/spike.obj");
    scene->map_texture_id = load_texture("textures/grass.png");
    scene->ball_texture_id = load_texture("textures/sb.jpg");
    scene->guide_id = load_texture("textures/gui.png");

    lighting_changer = 0.41f;
    
    scene->map_material.ambient.red = 1.0f;
    scene->map_material.ambient.green = 1.0f;
    scene->map_material.ambient.blue = 1.0f;

    scene->map_material.diffuse.red = 1.0f;
    scene->map_material.diffuse.green = 1.0f;
    scene->map_material.diffuse.blue = 1.0f;

    scene->map_material.specular.red = 1.0f;
    scene->map_material.specular.green = 1.0f;
    scene->map_material.specular.blue = 1.0f;

    scene->map_material.shininess = 0;

    scene->ball_material.ambient.red = 1.0f;
    scene->ball_material.ambient.green = 1.0f;
    scene->ball_material.ambient.blue = 1.0f;

    scene->ball_material.diffuse.red = 1.0f;
    scene->ball_material.diffuse.green = 1.0f;
    scene->ball_material.diffuse.blue = 1.0f;

    scene->ball_material.specular.red = 1.0f;
    scene->ball_material.specular.green = 1.0f;
    scene->ball_material.specular.blue = 1.0f;

    scene->ball_material.shininess = 100.0f;

    scene->spike_material.ambient.red = 1.0f;
    scene->spike_material.ambient.green = 0.0f;
    scene->spike_material.ambient.blue = 0.0f;

    scene->spike_material.diffuse.red = 1.0f;
    scene->spike_material.diffuse.green = 0.0f;
    scene->spike_material.diffuse.blue = 0.0f;

    scene->spike_material.specular.red = 1.0f;
    scene->spike_material.specular.green = 0.0f;
    scene->spike_material.specular.blue = 0.0f;

    scene->spike_material.shininess = 76.8f;

}

void set_lighting(float light)
{
    float ambient_light[] = { light, light, light, 1.0f };
    float diffuse_light[] = { light, light, light, 1.0f };
    float specular_light[] = { light, light, light, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_lighting_changer(float light)
{
    lighting_changer += light;
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
    
    set_lighting(lighting_changer);
    //draw_origin();

    glPushMatrix();
    set_material(&(scene->spike_material));
    glTranslatef(0, -2, -0.399999);
    draw_model(&(scene->spike));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->ball_texture_id);
    set_material(&(scene->ball_material));
    glTranslatef(0, 0, -0.1);
    draw_model(&(scene->ball));
    glPopMatrix();

    set_material(&(scene->map_material));

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    glTranslatef(0, 0, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -1, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -2, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3, -1);
    draw_model(&(scene->cube));
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -4, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
