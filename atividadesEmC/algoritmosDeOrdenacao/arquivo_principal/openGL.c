#include <stdio.h>
#include <stdlib.h>
#include "openGL.h"
#include "populadores.h"
#include "../__sorts/bubble_sort/modelo_vetor/bubble_sort.h"

int inicio = 0;

short cria_janela( int *argc , char **argv ){
	
	glutInit( argc , argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize( JANELA_LARG_INI , JANELA_ALT_INI );
	janela = glutCreateWindow( "Algoritmos de Ordenacao" );

	glutDisplayFunc( &desenha_tela );
	glutKeyboardFunc( &inicia_animacao );
	glutIdleFunc( &atualiza_tela );

	glutFullScreen();

	tela_Larg = glutGet(GLUT_SCREEN_WIDTH);
	tela_Alt = glutGet(GLUT_SCREEN_HEIGHT);

	xElem = (float) tela_Larg / N;
	raio_elemento = xElem/2;
	if( raio_elemento < 1 ) raio_elemento = 1;
	yElem = (float) (tela_Alt - MARGEM_SUPERIOR - ALT_TEXTO - raio_elemento) / N;
	
	glViewport( 0.0f , 0.0f , tela_Larg , tela_Alt );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	glOrtho( 0 , tela_Larg , 0 , tela_Alt , 0 , 1 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

	glewInit();

	cria_quadrado(1);

	glutMainLoop();
	return 1;
}

void inicia_animacao( unsigned char key, int x, int y ){
	if( key == 'a' ) limpa_tela();
	else if( key == '1' ) cria_quadrado( 1 ); /* Inicio da animação */
	else if( key == '2' ) cria_quadrado( 2 );
	else if( key == '3' ) cria_quadrado( 3 );
	else if( key == '4' ) cria_quadrado( 4 );
	else if( key == 32 ) bubble_sort();
	else if( key == 27 ) glutDestroyWindow( janela ); /* Mata a animação */
}

void desenha_tela( void ){
	limpa_tela();
	if( inicio ) atualiza_tela();
	else inicio = 1;
}

void limpa_tela( void ){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void cria_quadrado( int opcao ){
	int i;
	populador( opcao );

	pares_elementos = malloc( N * 2 * sizeof( GLfloat ) );
	for( i = 0 ; i < N ; ++i ){
		pares_elementos[i*2] = i * xElem + raio_elemento;
		pares_elementos[i*2+1] = elementos[i] * yElem;
	}
	glutPostRedisplay();
}

void atualiza_tela( void ){
	reposiciona_vertices();

	glEnableClientState( GL_VERTEX_ARRAY );

	glPointSize( raio_elemento );
	glVertexPointer( 2 , GL_FLOAT , 0 , pares_elementos );

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

void populador( int opcao ){
	elementos = malloc( N * sizeof( int ) );
	if( !elementos ){ printf("ERRO! Ponteiro elementos não mallocado!\n"); exit(1);}
	switch( opcao ){
		case 1:
			popula_aleatorio( N , elementos );
			break;
		case 2:
			popula_crescente( N , elementos );
			break;
		case 3:
			popula_descrescente( N , elementos );
			break;
		case 4:
			popula_50_porcento_iguais( N , elementos );
			break;
	}

}

void reposiciona_vertices( void ){
	int i;
	for( i = 0 ; i < N ; ++i ) pares_elementos[i*2+1] = elementos[i] * yElem;
}