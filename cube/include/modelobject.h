#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <obj/model.h>
#include "utils.h"
#include "texture.h"

typedef struct Ship
{
	Model player_ship;
	Material material;
	float model_scale;
	vec3 position;
    vec3 speed;
	vec3 rotation;
	vec3 rot_speed; 
}Ship;

/*draws the player ship.*/
void draw_ship(Ship* ship);

/*setup operations*/
void init_ship(Ship* ship);

/*function responsible for moving the ship on its y axis*/
void set_ship_side_speed(Ship* ship,double speed);

/*function responsible for moving the ship on its z axis*/
void set_ship_vertical_speed(Ship* ship,double speed);

/*updates the ships position/rotation*/
void update_ship(Ship* ship,double time);


#endif /*MODELOBJECT_H */