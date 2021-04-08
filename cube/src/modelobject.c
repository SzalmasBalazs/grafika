#include "modelobject.h"
#include "callbacks.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void draw_ship(Ship* ship){
	
	glPushMatrix(); 
		glRotatef(90,1,0,0);
		glScalef(ship->model_scale,ship->model_scale,ship->model_scale);
		glTranslatef(ship->position.x,ship->position.y,ship->position.z);
		draw_model(&(ship->player_ship));
	glPopMatrix();
	
}

void init_ship(Ship* ship){
	
	ship->position.x = 1.0;
	ship->position.y = 1.0;
	ship->position.z = 1.0;
	
	ship->speed.x = 1.0;
	ship->speed.y = 0.0;
	ship->speed.z = 0.0;
	
	ship->rotation.x = 0.0;
	ship->rotation.y = 0.0;
	ship->rotation.z = 0.0;
	
	ship->model_scale = 0.050;
}


void update_ship(Ship* ship,double time){
	
	double angle;
    double side_angle;

    angle = degree_to_radian(ship->rotation.z);
    side_angle = degree_to_radian(ship->rotation.z + 90.0);

    ship->position.x += cos(angle) * ship->speed.y * time;
    ship->position.y += sin(angle) * ship->speed.y * time;
    ship->position.x += cos(side_angle) * ship->speed.x * time;
    ship->position.y += sin(side_angle) * ship->speed.x * time;
	
	
}

