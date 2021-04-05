#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <obj/model.h>

typedef struct Ship
{
	Model player_ship;
	float model_scale;
	float x;
	float y;
	float z;
	float speed;
}Ship;

/*draws the player ship.*/
void draw_ship(Ship* ship);

/*setup operations*/
void init_ship(Ship* ship);

#endif /*MODELOBJECT_H */