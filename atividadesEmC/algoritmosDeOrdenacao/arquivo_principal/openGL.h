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
#ifndef HAVE_MATH_H
	#include <math.h>
#endif

#define JANELA_LARG_INI 800
#define JANELA_ALT_INI	600
#define MARGEM_SUPERIOR 10
#define MARGEM_ESQUERDA 40
#define ALT_TEXTO 20

short cria_janela( int *argc , char **argv );
void inicia_animacao( unsigned char key, int x, int y );
void desenha_tela( void );
void limpa_tela( void );
void cria_quadrado( void );
void escreve_na_tela( int x , int y , char *texto );
static int tela_Larg , tela_Alt;
static int janela;
static float xElem;
static float yElem;
static int raio_elemento;
static int N = 10;

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

	xElem = tela_Larg / N;
	yElem = (tela_Alt - MARGEM_SUPERIOR) / N;

	raio_elemento = ( xElem < yElem  ) ? xElem/2 : yElem/2 ;
	if( raio_elemento > 4 )	raio_elemento = floor( raio_elemento * 0.8 );

	printf("%f %f %d\n", xElem , yElem , raio_elemento );

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
	GLfloat elementos[N*2]; int i;

	for( i = 0 ; i < N ; ++i ) elementos[i*2] = i*xElem + raio_elemento , elementos[i*2+1] = i*yElem + raio_elemento , printf( "DEBUG: %d %f %f \n" , i , elementos[i*2] , elementos[i*2+1] );

	glEnableClientState( GL_VERTEX_ARRAY );

	glPointSize( raio_elemento );
	glVertexPointer( 2 , GL_FLOAT , 0 , elementos );

	glDrawArrays( GL_POINTS , 0 , N );
	
	glDisableClientState( GL_VERTEX_ARRAY );

	escreve_na_tela( MARGEM_ESQUERDA , tela_Alt - MARGEM_SUPERIOR , "Ola Mundo" );

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