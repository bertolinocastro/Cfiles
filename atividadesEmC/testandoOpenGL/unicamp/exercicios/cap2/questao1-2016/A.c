#include <GL/glut.h>
#include <stdlib.h>



void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Gabriel Bertolino");

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}