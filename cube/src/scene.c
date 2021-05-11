#include "scene.h"
#include "modelobject.h"
#include "utils.h"
#include "pcg_basic.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>
#include <obj/model.h>

/*Neccesary global variables for the random number generator and
  for the vector containing the asteroids*/
  
#define MAX_ASTEROID_ON_SCREEN 70
pcg32_random_t rng;
static Asteroid* asteroids[MAX_ASTEROID_ON_SCREEN];

void init_scene(Scene* scene)
{
	scene->light_strength = 1.0;
	pcg32_srandom_r(&rng, time(NULL) ^ (intptr_t)&printf, (intptr_t)&(scene->asteroid));
	int i = 0;
	int x,y,z;
	
    load_model(&(scene->ship.player_ship), "obj/Star Fighter Low-Poly.obj");
	load_model(&(scene->skybox), "obj/compatiblebox.obj");
	load_model(&(scene->cube), "obj/rock_by_dommk.obj");

	init_ship(&(scene->ship));
	
	for (i = 0; i < MAX_ASTEROID_ON_SCREEN;i++){
		/*Have to do a partial init. here. Couldn't get it to work otherwise*/
		x = -pcg32_boundedrand_r(&rng, 1500) + 40;
		y = -pcg32_boundedrand_r(&rng, 1500) + 40;
		z = -pcg32_boundedrand_r(&rng, 1500) + 40;
		/*actual init call for the asteroids*/
		init_asteroid(&(scene->asteroid[i]),x,y,z);
		load_model(&(scene->asteroid[i].asteroid_model),"obj/rock_by_dommk.obj");
	}
	
	scene->texture_id = load_texture("obj/Star Fighter_color.jpg");
	scene->texture_id2 = load_texture("obj/rock_Height.png");
	scene->sky_tex = load_texture("obj/bkg/red/bkg1_bottom4.png");

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 2.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 2.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 2.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 1.0;
}

void set_lighting(double light_strength)
{
	int i;
    float ambient_light[] = { 0.5f,  0.5f,  0.5f, 1.0f };
    float diffuse_light[] = {  0.5f,  0.5f,  0.5f, 1.0f };
    float specular_light[] = { 1.0f,  1.0f, 1.0f,  1.0f };
    float position[] = { 40.0f, 40.0f, 40.0f, 40.0f };
	
	
	  for(i = 0; i < 3; i++){
       ambient_light[i]*=light_strength;
       diffuse_light[i]*=light_strength;
       specular_light[i]*=light_strength;
    }

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}
void set_light_strength(Scene* scene,double light_val){
	
	scene->light_strength +=light_val;
	printf("%2.lf",scene->light_strength);

}
void set_material(const Material* material)
{
	
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
	
}

void draw_scene(const Scene* scene){

	int i;
	
    set_material(&(scene->material));
	set_lighting(scene->light_strength);
	
    draw_origin();
	draw_skybox(scene);
	
	glPushMatrix(); 
		glBindTexture(GL_TEXTURE_2D,scene->texture_id);
		glRotatef(0,0,0,1);
		glRotatef((scene->ship.rotation.z),0,0,1 );
		draw_ship(&(scene->ship));
	glPopMatrix();

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, scene->texture_id2);
		draw_asteroid_array(&(scene->asteroid));
	glPopMatrix();

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
void draw_skybox(Scene* scene){
	
	   glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->sky_tex);
        glScalef(2000, 2000, 2000);
	    draw_model(&(scene->skybox));
    glPopMatrix();
	
}