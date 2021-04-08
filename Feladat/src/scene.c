#include "scene.h"
#include "utils.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "cube.obj");
    scene->map_texture_id = load_texture("fu.png");
    load_model(&(scene->ball), "ball.obj");
    load_model(&(scene->cactus), "cactus.obj");

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


    scene->ball_material.ambient.red = 0.329412f;
    scene->ball_material.ambient.green = 0.223529f;
    scene->ball_material.ambient.blue = 0.027451f;

    scene->ball_material.diffuse.red = 0.780392f;
    scene->ball_material.diffuse.green = 0.568627f;
    scene->ball_material.diffuse.blue = 0.113725f;

    scene->ball_material.specular.red = 0.992157f;
    scene->ball_material.specular.green = 0.941176f;
    scene->ball_material.specular.blue = 0.807843f;

    scene->ball_material.shininess = 27.8974f;
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
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
    
    set_lighting();
    //draw_origin();

    glPushMatrix();
    set_material(&(scene->ball_material));
    glScalef(0.5, 0.5, 0.5);
    //glTranslatef(vec3.x, vec3.y, vec3.z);
    draw_model(&(scene->ball));
    glPopMatrix();

    set_material(&(scene->map_material));

/*
    glPushMatrix();
    glTranslatef(0, 0, -1);
    draw_model(&(scene->cactus));
    glPopMatrix();
*/
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    glTranslatef(0, 0, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    glTranslatef(0, -1, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    glTranslatef(0, -2, -1);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    glTranslatef(0, -3, 0);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    glTranslatef(0, -4, 0);
    draw_model(&(scene->cube));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->map_texture_id);
    glTranslatef(0, -6, 0);
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
