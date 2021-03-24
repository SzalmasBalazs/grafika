#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    // NOTE: Place for model structures and texture ids.
} Scene;

/*
Scene inicialázás
 */
void init_scene(Scene* scene);

/*
Scene objectum kirajzolás.
 */
void draw_scene(const Scene* scene);

/*
 Koordinátarendszer kirajzolás.
 */
void draw_origin();
#endif /* SCENE_H */