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
    load_model(&(ball->ball), "objects/ball.obj");
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
    draw_model(&(ball->ball));
    glPopMatrix();
}

void reset_ball(Ball* ball)
{
    ball->position.x = 0.0;
    ball->position.y = 0.0;
    ball->position.z = 0.0;
    ball->moving_speed = 0.0;
    ball->rotation.z = 0.0;
    ball->rotation_speed = 0.0;
}

void update_ball(Ball* ball, Spike* spike, Flag* flag)
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

    if(ball->position.y < -8.0){
        ball->position.y = -8.0;
        ball->rotation.x -= cos(angle) * ball->rotation_speed * elapsed_time;
        set_camera_speed(&camera, 0.0);
        set_camera_side_speed(&camera, 0.0);
    }
    

    //Jump movement.

    ball->upward_speed += ball->gravity * elapsed_time;
    ball->position.z += ball->upward_speed * elapsed_time;

    if(ball->position.z < 0.0){
        ball->upward_speed = 0.0;
        ball->position.z = 0.0;
        ball->is_in_air = FALSE;
    }

    //Bounding box. (spike)

    float spike_l = spike->position.y+0.4;
    float spike_r = spike->position.y-0.4;
    float spike_h = spike->position.z;
    float ball_r = ball->position.y - ball->radius;
    float ball_l = ball->position.y + ball->radius;
    float ball_b = ball->position.z - ball->radius;


    if(ball_r <= spike_l && ball_l >= spike_r && ball_b <= spike_h)
    {
        is_lose_visible = TRUE;
    }

    //Bounding box. (flag)

    float flag_l = flag->position.y - 0.1;
    float flag_h = flag->position.z + 0.2;

    if(ball_r <= flag_l && ball_b <= flag_h)
    {
        is_win_visible = TRUE;
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
    }
}
