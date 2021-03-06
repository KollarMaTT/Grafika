#include "scene.h"
#include "utils.h"
#include "spike.h"
#include "ball.h"
#include "cup.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    scene->guide_id = load_texture("textures/gui.png");
    scene->lose_id = load_texture("textures/lose.png");
    scene->win_id = load_texture("textures/win.png");

    lighting_changer = 0.41f;

    init_skybox(&(scene->skybox));
    init_map(&(scene->map));
    init_field_element(&(scene->field_element1), 4.5, 0.1);
    init_field_element(&(scene->field_element2), 6.5, 0.1);
    init_field_element(&(scene->field_element3), 7.5, 0.1);
    init_cup(&(scene->cup));
    init_spike(&(scene->spike1), 2, -0.299);
    init_spike(&(scene->spike2), 5.5, -0.299);
    init_spike(&(scene->spike3), 7.5, 0.7);
    init_ball(&(scene->ball));

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
    glBindTexture(GL_TEXTURE_2D, 0);
    //draw_origin();

    draw_cup(&(scene->cup));

    draw_spike(&(scene->spike1));
    draw_spike(&(scene->spike2));
    draw_spike(&(scene->spike3));

    draw_map(&(scene->map));

    draw_field_element(&(scene->field_element1));
    draw_field_element(&(scene->field_element2));
    draw_field_element(&(scene->field_element3));
    
    draw_ball(&(scene->ball));

    draw_skybox(&(scene->skybox));

    update_ball(&(scene->ball), &(scene->map), &(scene->field_element1), &(scene->spike1), &(scene->cup));
    update_ball(&(scene->ball), &(scene->map), &(scene->field_element2), &(scene->spike2), &(scene->cup));
    update_ball(&(scene->ball), &(scene->map), &(scene->field_element3), &(scene->spike3), &(scene->cup));

}

void reset_lights()
{
    lighting_changer = 0.41f;
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