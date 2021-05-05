#include "scene.h"
#include "utils.h"
#include "ball.h"
#include "texture.h"
#include "callbacks.h"

#include <stdbool.h>

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_ball(Ball* ball)
{
    load_model(&(ball->model), "objects/ball.obj");
    ball->ball_texture_id = load_texture("textures/sb.jpg");
    
    ball->radius = 0.4;
    ball->position.x = 0.0;
    ball->position.y = 0.0;
    ball->position.z = 0.0;
    ball->rotation.x = 0.0;
    ball->moving_speed = 0.0;
    ball->rotation_speed = 0.0;
    
    ball->gravity = -30.0;
    ball->upward_speed = 0.0;
    ball->is_in_air = FALSE;
    ball->bouncing = 0;

    ball->ball_material.ambient.red = 1.0f;
    ball->ball_material.ambient.green = 1.0f;
    ball->ball_material.ambient.blue = 1.0f;

    ball->ball_material.diffuse.red = 1.0f;
    ball->ball_material.diffuse.green = 1.0f;
    ball->ball_material.diffuse.blue = 1.0f;

    ball->ball_material.specular.red = 1.0f;
    ball->ball_material.specular.green = 1.0f;
    ball->ball_material.specular.blue = 1.0f;

    ball->ball_material.shininess = 100.0f;
}

void draw_ball(Ball* ball)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, ball->ball_texture_id);
    set_material(&(ball->ball_material));
    glTranslatef(ball->position.x, ball->position.y, ball->position.z);
    glRotatef(ball->rotation.x, 1, 0, 0);
    draw_model(&(ball->model));
    glPopMatrix();
}

void reset_ball(Ball* ball)
{
    ball->bouncing = 0;
    ball->position.x = 0.0;
    ball->position.y = 0.0;
    ball->position.z = 0.0;
    ball->moving_speed = 0.0;
    ball->rotation.z = 0.0;
    ball->rotation_speed = 0.0;
    ball->upward_speed = 0.0;
}

void update_ball(Ball* ball, Map* map, Field_element* field_element, Spike* spike, Cup* cup)
{
    float angle;
    float side_angle;

    angle = degree_to_radian(ball->rotation.z);
    side_angle = degree_to_radian(ball->rotation.z + 90.0);

    static int last_frame_time = 0;
    int current_time;
    float elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (float)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    //Left and right movement.

    ball->position.y += sin(side_angle) * ball->moving_speed * elapsed_time;
    ball->rotation.x += cos(angle) * ball->rotation_speed * elapsed_time;

    if(ball->position.y > 0.0){
        ball->position.y = 0.0;
        ball->rotation.x -= cos(angle) * ball->rotation_speed * elapsed_time;
        set_camera_speed(&camera, 0.0);
        set_camera_side_speed(&camera, 0.0);
    }

    if(ball->position.y < -11.0){
        ball->position.y = -11.0;
        ball->rotation.x -= cos(angle) * ball->rotation_speed * elapsed_time;
        set_camera_speed(&camera, 0.0);
        set_camera_side_speed(&camera, 0.0);
    }
    

    //Jump movement.

    ball->upward_speed += ball->gravity * elapsed_time;
    ball->position.z += ball->upward_speed * elapsed_time;

    float map_h = map->position.z + 0.9;

    
    if(ball->position.z < map_h){
        ball->upward_speed = 0.0;
        ball->position.z = map_h;
        ball->is_in_air = FALSE;
    }
    

    //Bounding box.

    float ball_r = ball->position.y - ball->radius;
    float ball_l = ball->position.y + ball->radius;
    float ball_b = ball->position.z - ball->radius;

    //Bounding box. (field_element)

    float field_element_l = field_element->position.y+0.5;
    float field_element_r = field_element->position.y-0.5;
    float field_element_h = field_element->position.z + 0.9;


    if(ball_r <= field_element_l && ball_l >= field_element_r && ball->position.z < field_element_h)
    {
        if(ball_r <= field_element_l && ball_r >= field_element_l-0.1){
            ball->position.y += 0.05;
            set_camera_speed(&camera, 0.0);
            set_camera_side_speed(&camera, 0.0);
        }
        
        if(ball->position.z <= field_element_h && ball_r <= field_element_l - 0.1 && ball_l >= field_element_r + 0.1){
            ball->upward_speed = 0.0;
            ball->position.z = field_element_h;
            ball->is_in_air = FALSE;
        }
        
        if(ball_l >= field_element_r && ball_l <= field_element_r + 0.1){
            ball->position.y -= 0.05;
            set_camera_speed(&camera, 0.0);
            set_camera_side_speed(&camera, 0.0);
        }
        
    }

    //Bounding box. (spike)

    float spike_l = spike->position.y+0.4;
    float spike_r = spike->position.y-0.4;
    float spike_h = spike->position.z;

    if(ball_r <= spike_l && ball_l >= spike_r && ball_b <= spike_h)
    {
        is_lose_visible = TRUE;
    }

    //Bounding box. (cup)

    float cup_l = cup->position.y + 0.12;
    float cup_h = cup->position.z + 0.2;

    if(ball_r <= cup_l && ball_b <= cup_h)
    {
        is_win_visible = TRUE;
    }

    //Bouncing

    if(!ball->is_in_air && ball->bouncing == 4)
    {
        ball->upward_speed = 8;
        ball->is_in_air = TRUE;
        ball->bouncing = 3;
    }

    if(!ball->is_in_air && ball->bouncing == 3)
    {
        ball->upward_speed = 5;
        ball->is_in_air = TRUE;
        ball->bouncing = 2;
    }

    if(!ball->is_in_air && ball->bouncing == 2)
    {
        ball->upward_speed = 3;
        ball->is_in_air = TRUE;
        ball->bouncing = 1;
    }

    if(!ball->is_in_air && ball->bouncing == 1)
    {
        ball->upward_speed = 1;
        ball->is_in_air = TRUE;
        ball->bouncing = 0;
    }
    
}

void set_ball_moving_speed(Ball* ball, float speed)
{
    ball->moving_speed = speed;
}

void set_ball_rotation(Ball* ball, float speed)
{
    ball->rotation_speed = speed;
}


void set_upward_speed(Ball* ball, float jump_power)
{
    if(!ball->is_in_air)
    {
        ball->upward_speed = jump_power;
        ball->is_in_air = TRUE;
        ball->bouncing = 4;
    }
}
