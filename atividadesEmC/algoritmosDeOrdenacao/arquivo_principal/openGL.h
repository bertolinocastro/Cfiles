/*
 *	Arquivo-cabeçalho de criação
 *	das funções em OpenGL/GLUT
 *	para o funcionamento da geração
 *	de gráficos dinâmicos.
 *
 */
#include <GL/glew.h>
#include <GL/glut.h>

#define JANELA_LARG_INI 800
#define JANELA_ALT_INI	600

int janela;

short cria_janela( int *argc , char **argv );
void inicia_animacao( unsigned char key, int x, int y );
void draw( void );

short cria_janela( int *argc , char **argv ){
	
	glutInit( argc , argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( JANELA_LARG_INI , JANELA_ALT_INI );
	janela = glutCreateWindow( "Algoritmos de Ordenacao" );

	glutDisplayFunc( &draw );
	glutKeyboardFunc( &inicia_animacao );

	glewInit();

	glutMainLoop();
	return 1;
}

void inicia_animacao( unsigned char key, int x, int y ){

	if( key == 32 ); /* Inicio da animação */
	else if( key == 27 ) glutDestroyWindow( janela ); /* Mata a animação */
}

void draw( void ){
	glClear( GL_COLOR_BUFFER_BIT );
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutFullScreen();
	glutSwapBuffers();
}