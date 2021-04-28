#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <obj/model.h>
#include "utils.h"

typedef struct Ship
{
	Model player_ship;
	float model_scale;
	vec3 position;
    vec3 speed;
	vec3 rotation;
}Ship;

/*draws the player ship.*/
void draw_ship(Ship* ship);

/*setup operations*/
void init_ship(Ship* ship);

void set_ship_side_speed(Ship* ship,double speed);

void set_ship_horizontal_speed(Ship* ship,double speed);

void update_ship(Ship* ship,double time);


#endif /*MODELOBJECT_H */