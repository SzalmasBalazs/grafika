#include <Gl/glut.h>

#include <stdio.h>

/* GLUT Callbackek beállítása*/
void set_callbacks(){
	
	glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutIdleFunc(idle);
	
}

/*main függvény*/
int main(int argc, char* argv[])
{
  glutInit(&argc,argv);

  glutInitWindowSize(1280,720);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

  int window = glutCreateWindow("Space Invaders v.0.1");
  glutSetWindow(window);
	
	init_OpenGL();
	
	init_camera(&camera);
	init_scene(&scene);
	set_callbacks();
	
	
	return 0;
	
}