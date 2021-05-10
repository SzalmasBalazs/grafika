#include "modelobject.h"
#include "callbacks.h"
#include "scene.h"


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
	
	
	ship->position.x = 0.0;
	ship->position.y = 0.0;
	ship->position.z = 0.0;
	
	ship->speed.x = 0.0;
	ship->speed.y = 0.0;
	ship->speed.z = 0.0;
	
	ship->rotation.x = 0.0;
	ship->rotation.y = 0.0;
	ship->rotation.z = 0.0;
	
	ship->rot_speed.x = 0.0;
	ship->rot_speed.y = 0.0;
	ship->rot_speed.z = 0.0;
	
	ship->model_scale = 0.050;
}


void update_ship(Ship* ship,double time){
	
	double angle;
    double side_angle;
	
	ship->rotation.z += ship->rot_speed.z * time;
	
    angle = degree_to_radian(ship->rotation.z);
    side_angle = degree_to_radian(ship->rotation.z + 90.0);

	ship->position.x +=cos(angle) * ship->speed.y * time;
    ship->position.y += sin(side_angle) * ship->speed.x * time;
	ship->position.z += sin(angle) * ship->speed.z * time;
	ship->position.z += sin(side_angle) * ship->speed.z * time;
	
	
}
void set_ship_speed(Ship* ship,double speed){
	
		ship->speed.y = speed;

}
void set_ship_side_speed(Ship* ship,double speed){
	
	ship->speed.z = speed;
}
void set_ship_vertical_speed(Ship* ship,double speed){
	
	ship->speed.x = speed;
}
void set_ship_rotation_speed(Ship* ship,double speed){
	
	ship->rot_speed.z = speed;
}
