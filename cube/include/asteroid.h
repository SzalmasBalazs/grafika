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


void draw_asteroid(Asteroid* asteroid);

void init_asteroid(Asteroid* asteroid,double x,double y, double z);

void draw_asteroid_array(Asteroid* asteroid);

#endif /*ASTEROID_H */