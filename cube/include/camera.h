#ifndef CAMERA_H
#define CAMERA_H


#include "utils.h"
#include "modelobject.h"

/**
 * Camera, as a moving point with direction
 */

typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;

} Camera;

Ship ship;

/* Is the help panel visible */
int is_help_visible;

/* Sets the staring position/rotation/speed of the camera */
void init_camera(Camera* camera);

/* Update the position of the camera.*/
void update_camera(Camera* camera, double time);

/*
View transformations.
 */
void set_view(const Camera* camera);

/* Set the horizontal and vertical rotation of the view angle.*/
void rotate_camera(Camera* camera, double horizontal, double vertical);

/* Set the speed of forward and backward motion.*/
void set_camera_speed(Camera* camera, double speed);

/* Set the speed of left and right side steps.*/
void set_camera_side_speed(Camera* camera, double speed);

#endif /* CAMERA_H */
