#include "callbacks.h"

#define VIEWPORT_RATIO (4.0 / 3.0)
#define VIEWPORT_ASPECT 50.0

struct {
    int x;
    int y;
} mouse_position;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&camera);
    draw_scene(&scene);
    glPopMatrix();

    if (is_guide_visible) {
        show_guide();
    }

    if (is_lose_visible) {
        show_lose();
    }

    if (is_win_visible) {
        show_win();
    }

    if (is_preview_visible) {
        show_texture_preview();
    }

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEWPORT_ASPECT, VIEWPORT_RATIO, 0.01, 10000.0);
}

void mouse(int button, int state, int x, int y)
{
    mouse_position.x = x;
    mouse_position.y = y;
}

void motion(int x, int y)
{
    rotate_camera(&camera, mouse_position.x - x, mouse_position.y - y);
    mouse_position.x = x;
    mouse_position.y = y;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
        set_camera_speed(&camera, 1);
        break;
    case 's':
        set_camera_speed(&camera, -1);
        break;
    case 'a':
        set_camera_side_speed(&camera, 1);
        break;
    case 'd':
        set_camera_side_speed(&camera, -1);
        break;
    case 'q':
        set_camera_vertical_speed(&camera, 1);
        break;
    case 'e':
        set_camera_vertical_speed(&camera, -1);
        break;
    case '-':
        if(lighting_changer > 0)
        set_lighting_changer(-0.2);
        break;
    case '+':
        if(lighting_changer < 1)
        set_lighting_changer(0.2);
        break;
    case 'j':
        set_ball_moving_speed(&(scene.ball), 3);
        set_ball_rotation(&(scene.ball), -240);
        break;
    case 'l':
        set_ball_moving_speed(&(scene.ball), -3);
        set_ball_rotation(&(scene.ball), 240);
        break;
    case 'i':
        set_upward_speed(&(scene.ball), 12);
        break;
     case 'r':
        reset_lights();
        reset_camera(&camera);
        reset_ball(&(scene.ball));
        if(is_lose_visible)
        is_lose_visible = FALSE;
        if(is_win_visible)
        is_win_visible = FALSE;
        break;
    }

    glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
    case 's':
        set_camera_speed(&camera, 0.0);
        break;
    case 'a':
    case 'd':
        set_camera_side_speed(&camera, 0.0);
        break;
    case 'q':
    case 'e':
        set_camera_vertical_speed(&camera, 0.0);
        break;
    case '+':
    case '-':
        set_lighting_changer(0.0);
        break;
    case 'j':
    case 'l':
        set_ball_moving_speed(&(scene.ball), 0.0);
        set_ball_rotation(&(scene.ball), 0.0);
        break;
    }

    glutPostRedisplay();
}

void special_function(unsigned char key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_F1:
            if(is_guide_visible){
                is_guide_visible = FALSE;
            }
            else{
                is_guide_visible = TRUE;
            }
            break;
        case GLUT_KEY_LEFT:
            set_camera_speed(&camera, -0.512);
            set_camera_side_speed(&camera, 2.95);
            set_ball_moving_speed(&(scene.ball), 3);
            set_ball_rotation(&(scene.ball), -240);
            break;
        case GLUT_KEY_RIGHT:
            set_camera_speed(&camera, 0.512);
            set_camera_side_speed(&camera, -2.95);
            set_ball_moving_speed(&(scene.ball), -3);
            set_ball_rotation(&(scene.ball), 240);
            break;
        case GLUT_KEY_UP:
            set_upward_speed(&(scene.ball), 12);
            break;
    }
    glutPostRedisplay();
}

void special_function_up(unsigned char key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:
        set_camera_speed(&camera, 0.0);
        set_camera_side_speed(&camera, 0.0);
        set_ball_moving_speed(&(scene.ball), 0.0);
        set_ball_rotation(&(scene.ball), 0.0);
        break;
    }

    glutPostRedisplay();
}


void idle()
{
    static int last_frame_time = 0;
    int current_time;
    float elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (float)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    update_camera(&camera, elapsed_time);

    glutPostRedisplay();
}
