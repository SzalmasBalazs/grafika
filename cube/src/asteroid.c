#include "callbacks.h"
#include "scene.h"
#include "asteroid.h"
#include "pcg_basic.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>


#include <time.h>
#include <math.h>
#include <time.h>
#include <stdint.h>



#define MAX_ASTEROID_ON_SCREEN 70

void init_asteroid(Asteroid* asteroid, double x,double y, double z){
	

	asteroid->position.x = x;	
	asteroid->position.y = y;	
	asteroid->position.z = z;	
	
	asteroid->rotation.x = 0.0;
	asteroid->rotation.y = 0.0;
	asteroid->rotation.z = 0.0;
	
	asteroid->rot_speed = 0.05;
	
	asteroid->model_scale = 0.01;
}

void draw_asteroid(Asteroid* asteroid){

	glRotatef(asteroid->rotation.z,0,0,1);
	glPushMatrix();
	glScalef(asteroid->model_scale,asteroid->model_scale,asteroid->model_scale);
		glTranslatef(asteroid->position.x,asteroid->position.y,asteroid->position.z);
		draw_model(&(asteroid->asteroid_model));
	glPopMatrix();
	
	
}
void draw_asteroid_array(Asteroid* asteroid){
	int i = 0;
	//printf("draw asteroid array");
		for (i = 0;i<MAX_ASTEROID_ON_SCREEN;i++){
			//printf("%d",i);
			draw_asteroid(&asteroid[i]);
	
	}
	
}
void update_asteroid(Asteroid* asteroid, double time){
	int i = 0;
	for (i = 0;i<MAX_ASTEROID_ON_SCREEN;i++){
		
		asteroid[i].rotation.z += asteroid[i].rot_speed * time;
	
	}

}