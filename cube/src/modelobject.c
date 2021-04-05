#include "modelobject.h"
#include "callbacks.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void draw_ship(Ship* ship){
	
	glPushMatrix(); 
		glRotatef(90,1,0,0);
		glScalef(ship->model_scale,ship->model_scale,ship->model_scale);
		glTranslatef(ship->x,ship->y,ship->z);
		draw_model(&(ship->player_ship));
	glPopMatrix();
	
}

void init_ship(Ship* ship){
	ship-> speed = 1.0;
	ship->x = 1.0;
	ship->y = 1.0;
	ship->z = 1.0;
	ship->model_scale = 0.050;
}