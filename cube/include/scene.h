#ifndef SCENE_H
#define SCENE_H


#include "texture.h"
#include "modelobject.h"
#include "camera.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
	Ship ship;
	Model skybox;
    Material material;
    GLuint texture_id;
	GLuint texture_id2;
	GLuint texture_id3;
	GLuint texture_id4;
	GLuint sky_tex;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

void update_scene(Scene* scene, double time);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/*function responsible for moving the ship on its y axis*/
void set_ship_side_speed(Ship* ship,double speed);

/*function responsible for moving the ship on its z axis*/
void set_ship_horizontal_speed(Ship* ship,double speed);

void draw_skybox(Scene* scene);

#endif /* SCENE_H */
