#ifndef ASTEROID_H
#define ASTEROID_H

#include <obj/model.h>
#include "utils.h"
#include "texture.h"

typedef struct Asteroid{
	
		Model asteroid_model;
		Material material;
		float model_scale;
		vec3 position;
		vec3 rotation;
		float rot_speed;
}Asteroid;

/* Draws the asteroids onto the scene*/
void draw_asteroid(Asteroid* asteroid);

/*Gives the randomly generated coordinates and the rotation value
 to every asteroid in the vector */
void init_asteroid(Asteroid* asteroid,double x,double y, double z);

/*A function that calls draw_asteroid onto individual members of
  the asteroid vector*/
void draw_asteroid_array(Asteroid* asteroid);

#endif /*ASTEROID_H */