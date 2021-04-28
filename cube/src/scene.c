#include "scene.h"
#include "modelobject.h"
#include "utils.h"


#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>
#include <obj/model.h>

void init_scene(Scene* scene)
{
	scene->rotation = 0.0;
    load_model(&(scene->ship.player_ship), "obj/Star Fighter Low-Poly.obj");
	load_model(&(scene->skybox), "obj/compatiblebox.obj");
	load_model(&(scene->cube), "obj/cube.obj");
	init_ship(&(scene->ship));
	scene->texture_id = load_texture("obj/Star Fighter_color.jpg");
	scene->sky_tex = load_texture("obj/bkg/red/bkg1_bottom4.png");
	/*/bkg/red/bkg1_bottom4.png*/

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 0.0;
    scene->material.diffuse.green = 0.0;
    scene->material.diffuse.blue = 0.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 1.0;
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 0.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
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

    set_material(&(scene->material));
    set_lighting();
    draw_origin();
	draw_skybox(scene);
 glPushMatrix(); 
    glBindTexture(GL_TEXTURE_2D,scene->texture_id);
    glRotatef(180,0,0,1);
	draw_ship(&(scene->ship));

	glTranslatef(4.3,0,0);
	glScalef(0.25,0.25,0.25);
    draw_model(&(scene->cube));
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
        //glTranslatef(1.0, 0.0, 0.0);
        //glTranslatef(0.0, 1.0, 0.0);
        glScalef(200, 200, 200);
	    draw_model(&(scene->skybox));
    glPopMatrix();
}
void update_rotation(Scene* scene,double time){

	scene->rotation += 10*time;
}