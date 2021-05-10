#include "callbacks.h"
#include "scene.h"

#define VIEWPORT_RATIO (16.0 / 9.0)
#define VIEWPORT_ASPECT 60.0

#include <obj/load.h>
#include <obj/draw.h>
#include <obj/model.h>



struct {
    int x;
    int y;
} mouse_position;



void display()
{
	int i = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&camera);
    draw_scene(&scene);

 
    if (is_preview_visible) {
        show_texture_preview();
    }
	
	
	glPopMatrix();
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

	float speed = 20.0;
    switch (key) {
    case 'w':
     set_ship_speed(&scene.ship,-speed);
        break;
    case 's':
      set_ship_speed(&scene.ship,speed);
        break;
    case 'a':
	set_ship_side_speed(&scene.ship,speed);
        break;
    case 'd':
     set_ship_side_speed(&scene.ship,-speed);
        break;
	case 'r':
     set_ship_vertical_speed(&scene.ship,speed);
        break;
	case 'f':
     set_ship_vertical_speed(&scene.ship,-speed);
        break;
	case 'q':
     set_ship_rotation_speed(&scene.ship,speed);
        break;
	case 'e':
     set_ship_rotation_speed(&scene.ship,-speed);
        break;
    case 't':
        if (is_preview_visible) {
            is_preview_visible = FALSE;
        }
        else {
            is_preview_visible = TRUE;
        }
        break;
	case 'i':
	 set_camera_speed(&camera,1);
	    break;
	case 'k':
	  set_camera_speed(&camera,-1);
	    break;
	case 'j':
	  set_camera_side_speed(&camera,1);
        break;
	case 'l':
	set_camera_side_speed(&camera,-1);
	 break;
    }
    glutPostRedisplay();
	
}

void keyboard_up(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
    case 's':
       set_ship_speed(&scene.ship,0.0);
        break;
    case 'a':
    case 'd':
       set_ship_side_speed(&scene.ship,0.0);
        break;
	case 'r':
	case 'f':
     set_ship_vertical_speed(&scene.ship,0.0);
        break;
	case 'q':
	case 'e':
     set_ship_rotation_speed(&scene.ship,0.0);
        break;
	case 'i':
	case 'k':
	 set_camera_speed(&camera,0.0);
	 break;
	case 'j':
	case 'l':
	 set_camera_side_speed(&camera,0.0);
	 break;
    }

    glutPostRedisplay();
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    update_camera(&camera,&scene.ship, elapsed_time);
	update_ship(&scene.ship,elapsed_time);
    glutPostRedisplay();
}
 