#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "camera.h"
#include "scene.h"

#include <GL/glut.h>

/*
  Scene
 */
Scene scene;

/*
  Camera
 */
Camera camera;

/*
 Megívódik grafikus tartalom displayelésénél.
 */
void display();

/*
 Window resizeolás után hívódik meg.
 */
void reshape(GLsizei width, GLsizei height);

/*
Felhasználó input menedzselése.
 */
void keyboard(unsigned char key, int x, int y);

/*
 Felhasználó input nullázása key release után.
 */
void keyboard_up(unsigned char key, int x, int y);

/*
 Semmittevés közbeni hívás.
 */
void idle();

#endif // CALLBACKS_H