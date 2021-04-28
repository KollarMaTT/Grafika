#ifndef MAP_H
#define MAP_H

#include <utils.h>
#include <camera.h>

#include <obj/model.h>

/**
 * Map 
 */
typedef struct Map
{
    Model map;
    GLuint map_texture_id;
    vec3 position;
    Material map_material;
} Map;

/**
 * Initialize the map.
 */
void init_map(Map* map);

/**
 * Draw the map.
 */
void draw_map(Map* map, float y);

#endif /* MAP_H */