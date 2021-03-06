#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
} Camera;


/**
 * Is the help menu visible?
 */
int is_guide_visible;

/**
 * Is the game over screen visible?
 */
int is_lose_visible;

/**
 * Is the win screen visible?
 */
int is_win_visible;

/**
 * Is the texture preview visible?
 */
int is_preview_visible;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera* camera);

/**
 * Update the position of the camera.
 */
void update_camera(Camera* camera, double time);

/**
 * Reset the position of the camera.
 */
void reset_camera(Camera* camera);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera* camera);

/**
 * Set the horizontal and vertical rotation of the view angle.
 */
void rotate_camera(Camera* camera, double horizontal, double vertical);

/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera* camera, double speed);

/**
 * Set the speed of left and right side steps.
 */
void set_camera_side_speed(Camera* camera, double speed);

/**
 * Set the speed of lifting up and down motion.
 */
void set_camera_vertical_speed(Camera* camera, double speed);

/**
 * Shows the guide.
 */
void show_guide();

/**
 * Shows the game over screen.
 */
void show_lose();

/**
 * Shows the win screen.
 */
void show_win();



#endif /* CAMERA_H */
