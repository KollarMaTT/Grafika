#include "scene.h"
#include "utils.h"
#include "field_element.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_field_element(Field_element* field_element, float y, float z)
{
    load_model(&(field_element->model), "objects/cube.obj");
    field_element->field_element_texture_id = load_texture("textures/grass.png");
    
    field_element->position.x=0.0;
    field_element->position.y=-y;
    field_element->position.z=z;

    field_element->field_element_material.ambient.red = 1.0f;
    field_element->field_element_material.ambient.green = 1.0f;
    field_element->field_element_material.ambient.blue = 1.0f;

    field_element->field_element_material.diffuse.red = 1.0f;
    field_element->field_element_material.diffuse.green = 1.0f;
    field_element->field_element_material.diffuse.blue = 1.0f;

    field_element->field_element_material.specular.red = 1.0f;
    field_element->field_element_material.specular.green = 1.0f;
    field_element->field_element_material.specular.blue = 1.0f;

    field_element->field_element_material.shininess = 0.0f;
}

void draw_field_element(Field_element* field_element)
{
    glPushMatrix();
    set_material(&(field_element->field_element_material));
    glTranslatef(field_element->position.x, field_element->position.y, field_element->position.z);
    draw_model(&(field_element->model));
    glPopMatrix();

}
