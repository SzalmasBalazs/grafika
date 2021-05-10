#ifndef SCENE_H
#define SCENE_H


#include "texture.h"
#include "modelobject.h"
#include "camera.h"
#include "asteroid.h"

#include <obj/model.h>

#define MAX_ASTEROID_ON_SCREEN 50

typedef struct Scene
{
    Model cube;
	Ship ship;
	Model skybox;
	Asteroid asteroid[MAX_ASTEROID_ON_SCREEN];
    Material material;
    GLuint texture_id;
	GLuint texture_id2;
	GLuint texture_id3;
	GLuint texture_id4;
	GLuint sky_tex;
	
} Scene;

Camera camera;
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

/* Draw the scene objects.*/
void draw_scene(const Scene* scene);

/*Draw the origin of the world coordinate system.*/
void draw_origin();

/*Function responsible for drawing the skybox*/
void draw_skybox(Scene* scene);

#endif /* SCENE_H */
