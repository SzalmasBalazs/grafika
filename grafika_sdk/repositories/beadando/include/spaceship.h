#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "utils.h"
#include <GL/glut.h>
#include <obj/model.h>

typedef struct Spaceship
{
	double model_scale;
	double x;
	double y;
	double z;
    const double velocity;
	//the current velocity of the ship, does not change ,thus is constant// 
}Spaceship;

//setup operations
void init_ship(Spaceship* ship);
void draw_ship(Spaceship* ship);
//


void destroy_ship(Spaceship* deer);



#endif /* SPACESHIP_H */