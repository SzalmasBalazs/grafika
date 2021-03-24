#include "scene.h"
#include "callbacks.h"

#include <GL/glut.h>



void init_scene(Scene* scene)
{
}

void draw_scene(const Scene* scene)
{
    draw_origin();
    glEnd();
}
void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(-5, 0, 0);
    glVertex3f(5, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, -5, 0);
    glVertex3f(0, 5, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, -5);
    glVertex3f(0, 0, 5);

    glEnd();
}