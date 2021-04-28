#ifndef BALL_H
#define BALL_H

#include <utils.h>
#include <camera.h>
#include <stdbool.h>
#include <spike.h>
#include <flag.h>

#include <obj/model.h>

/**
 * Ball
 */
typedef struct Ball
{
    Model ball;
    GLuint ball_texture_id;
    float radius;
    vec3 position;
    vec3 rotation;
    float moving_speed;
    float rotation_speed;
    
    float gravity;
    float upward_speed;
    bool is_in_air;
    
    Material ball_material;
} Ball;

/**
 * Initialize the ball object.
 */
void init_ball(Ball* ball);

/**
 * Draw the ball object.
 */
void draw_ball(Ball* ball);

/**
 * Reset the position of the ball.
 */
void reset_ball(Ball* ball);

/**
 * Update the position of the ball.
 */
void update_ball(Ball* ball, Spike* spike, Flag* flag);

/**
 * Move the ball object.
 */
void set_ball_moving_speed(Ball* ball, float speed);

/**
 * Rotate the ball object.
 */
void set_ball_rotation(Ball* ball, float angle);

/**
 * Make the ball jump.
 */
void set_upward_speed(Ball* ball, float jump_power);



#endif /* BALL_H */