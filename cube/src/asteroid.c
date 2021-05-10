#include "callbacks.h"
#include "scene.h"
#include "asteroid.h"


#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

#define MAX_ASTEROID_ON_SCREEN 50

void init_asteroid(Asteroid* asteroid, int val){
	
	float U = 0.10;
	float L = 0.01;
	
	asteroid->position.x = val;//(rand()%(360-10+1)+10);
	asteroid->position.y = val;//(rand()%(180-10+1)+10);
	asteroid->position.z = val;//(rand()%(180-10+1)+10);
	
	asteroid->rotation.x = 0.0;
	asteroid->rotation.y = 0.0;
	asteroid->rotation.z = 0.0;
	
	
	asteroid->model_scale = 0.01;//(rand()/(float)(U-L+1)+L);
}

void draw_asteroid(Asteroid* asteroid){
	
	int rotation = 1.0;
	
	glPushMatrix(); 
		glRotatef(rotation,0,0,0);
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


