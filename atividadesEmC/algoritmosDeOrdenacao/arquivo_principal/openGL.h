/*
 *	Arquivo-cabeçalho de criação
 *	das funções em OpenGL/GLUT
 *	para o funcionamento da geração
 *	de gráficos dinâmicos.
 *
 */
#include <GL/glew.h>
#include <GL/glut.h>
#ifndef HAVE_STRING_H
	#include <string.h>
#endif

#define JANELA_LARG_INI 800
#define JANELA_ALT_INI	600

int janela;

short cria_janela( int *argc , char **argv );
void inicia_animacao( unsigned char key, int x, int y );
void desenha_tela( void );
void limpa_tela( void );
void cria_quadrado( void );
void escreve_na_tela( int x , int y , char *texto );
static int tela_Larg , tela_Alt;


short cria_janela( int *argc , char **argv ){
	
	glutInit( argc , argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( JANELA_LARG_INI , JANELA_ALT_INI );
	janela = glutCreateWindow( "Algoritmos de Ordenacao" );

	glutDisplayFunc( &desenha_tela );
	glutKeyboardFunc( &inicia_animacao );

	glutFullScreen();

	tela_Larg = glutGet(GLUT_SCREEN_WIDTH);
	tela_Alt = glutGet(GLUT_SCREEN_HEIGHT);

	glViewport( 0.0f , 0.0f , tela_Larg , tela_Alt );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	glOrtho( 0 , tela_Larg , 0 , tela_Alt , 0 , 1 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

	glewInit();

	glutMainLoop();
	return 1;
}

void inicia_animacao( unsigned char key, int x, int y ){
	if( key == 'a' ) limpa_tela();
	if( key == 32 ) cria_quadrado(); /* Inicio da animação */
	else if( key == 27 ) glutDestroyWindow( janela ); /* Mata a animação */
}

void desenha_tela( void ){
	limpa_tela();
	
}

void limpa_tela( void ){
	glClear( GL_COLOR_BUFFER_BIT );
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutSwapBuffers();
}

void cria_quadrado( void ){
	
	GLfloat triangle_vertices[] = {
		0.0f , 0.0f,
		0.0f, 10.0f,
		10.0f, 10.0f,
		10.0f, 0.0f,
	};

	glEnableClientState( GL_VERTEX_ARRAY );

	glPointSize( 5 );
	glVertexPointer( 2 , GL_FLOAT , 0 , triangle_vertices );

	glDrawArrays( GL_POINTS , 0 , 4 );
	
	glDisableClientState( GL_VERTEX_ARRAY );

	escreve_na_tela( 40 , 40 , "Ola Mundo" );

	glutSwapBuffers();
	
}

void escreve_na_tela( int x , int y , char *texto ){
	int i;
	
	glPushMatrix();
	glRasterPos2f( x , y );

	for( i = 0 ; texto[i] != '\0' ; ++i ){
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12 , texto[i] );
	}

	glRasterPos2f( -x , -y );
	glPopMatrix();

}