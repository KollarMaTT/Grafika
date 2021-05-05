#ifndef FIELD_ELEMENT_H
#define FIELD_ELEMENT_H

#include <utils.h>
#include <camera.h>

#include <obj/model.h>

/**
 * Field_element
 */
typedef struct Field_element
{
    Model model;
    GLuint field_element_texture_id;
    vec3 position;
    Material field_element_material;
} Field_element;

/**
 * Initialize the field_element object.
 */
void init_field_element(Field_element* field_element, float y, float z);

/**
 * Draw the field_element object.
 */
void draw_field_element(Field_element* field_element);

#endif /* FIELD_ELEMENT_H */