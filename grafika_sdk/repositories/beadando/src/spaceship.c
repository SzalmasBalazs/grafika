#include "spaceship.h"
#include "callbacks.h"
#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>


void draw_ship(Spaceship* ship){
	glPushMatrix();
	 glRotalef(90,1,0,0);
	 glScale(ship->model_scale, ship->model_scale, ship->model_scale);
	 glTransalef(ship->x, ship->z, ship->y);
	 draw_model(&(ship->shipmodel));
	glPopMatrix();
}



void init_ship(Spaceship* ship){
	/*Sets up the "ship" that i'll be testing on*/
	ship -> speed = 1;
	ship -> x = x;
	ship -> y = y;
	ship -> z = 0;
}
