#include "init.h"

#include <GL/glut.h>

void init_OpenGL(){
 
	glShadeModel(GL_SMOOTH);

	glEnable(GL_NORMALIZE);
	glEanble(GL_AUTO_NORMAL);

	glClearColor(0.1,0.1,0.1,1.0);	
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);




}