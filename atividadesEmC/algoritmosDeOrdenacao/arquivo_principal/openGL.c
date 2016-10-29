#include <stdio.h>
#include <stdlib.h>
#ifndef HAVE_OWN_OPENGL_LIB_H
	#include "openGL.h"
#endif
#include "populadores.h"
#include "../__sorts/bubble_sort/modelo_vetor/bubble_sort.h"
#include "int_p_string.h"


int inicio = 0;

short cria_janela( int *argc , char **argv ){

	glutInit( argc , argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize( JANELA_LARG_INI , JANELA_ALT_INI );
	janela = glutCreateWindow( "Algoritmos de Ordenacao" );

	glutDisplayFunc( &desenha_tela );
	glutKeyboardFunc( &inicia_animacao );

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

	cria_quadrado( 0 );

	glutMainLoop();
	return 1;
}

void inicia_animacao( unsigned char key, int x, int y ){
	static short pode_iniciar = 0;
	if( key == 'a' ) limpa_tela();
	else if( key == '0' ) pode_iniciar = 0, cria_quadrado( 0 );
	else if( key == '1' ) pode_iniciar = 1, cria_quadrado( 1 ); /* Inicio da animação */
	else if( key == '2' ) pode_iniciar = 1, cria_quadrado( 2 );
	else if( key == '3' ) pode_iniciar = 1, cria_quadrado( 3 );
	else if( key == '4' ) pode_iniciar = 1, cria_quadrado( 4 );
	else if( key == 32 ){ if( pode_iniciar ) pode_iniciar = 0, iniciou_animacao = 1, bubble_sort(); }
	else if( key == 27 ) glutDestroyWindow( janela ); /* Mata a animação */
}

void desenha_tela( void ){
	limpa_tela();
	atualiza_tela();
}

void limpa_tela( void ){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void cria_quadrado( int opcao ){
	int i; iniciou_animacao = 0;
	tempoDeInicioDaAnim = trocas = comparacoes = passos = tempoTotal = 0;
	populador( opcao );

	pares_elementos = malloc( N * 2 * sizeof( GLfloat ) );
	for( i = 0 ; i < N ; ++i ){
		pares_elementos[i*2] = i * xElem + raio_elemento;
		pares_elementos[i*2+1] = elementos[i] * yElem;
	}
	glutPostRedisplay();
}

void atualiza_tela( void ){

	if( trocou ){ reposiciona_vertices(); trocou = 0; }

	glEnableClientState( GL_VERTEX_ARRAY );

	glPointSize( raio_elemento );
	glVertexPointer( 2 , GL_FLOAT , 0 , pares_elementos );

	glDrawArrays( GL_POINTS , 0 , N );
	
	glDisableClientState( GL_VERTEX_ARRAY );

	escreve_na_tela( MARGEM_ESQUERDA , tela_Alt - ALT_TEXTO );

	glutSwapBuffers();
}

void escreve_na_tela( int x , int y ){
	int i , tamValor; char *valor = NULL;
	#define printa_tab (glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , 9 ),glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , 9 ))
	
	const char texto[][30] = {
		{N_TEXT},
		{TEMPO_TEXT},
		{PASSOS_TEXT},
		{COMP_TEXT},
		{TROCAS_TEXT}
	};

	if( iniciou_animacao ) tempoTotal = (clock()-tempoDeInicioDaAnim)*COMPONENTE_PROPORCAO_TEMPO;
	else tempoTotal = 0 , tempoDeInicioDaAnim=clock();

	glPushMatrix();
	glRasterPos2f( x , y );

		/* Printa o N e seu valor */
		for( i = 0 ; texto[0][i] != '\0' ; ++i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , texto[0][i] );
		tamValor = int_p_string( N , &valor );
		for( i = tamValor - 1 ; i >= 0 ; --i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , valor[i] );
		printa_tab;

		/* Printa o Tempo total e seu valor */
		for( i = 0 ; texto[1][i] != '\0' ; ++i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , texto[1][i] );
		tamValor = int_p_string( tempoTotal , &valor );
		for( i = tamValor - 1 ; i >= 0 ; --i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , valor[i] );
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , 'm' );glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , 's' );
		printa_tab;

		/* Printa os passos e seu valor */
		for( i = 0 ; texto[2][i] != '\0' ; ++i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , texto[2][i] );
		tamValor = int_p_string( passos , &valor );
		for( i = tamValor - 1 ; i >= 0 ; --i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , valor[i] );
		printa_tab;

		/* Printa as comparacoes e seu valor */
		for( i = 0 ; texto[3][i] != '\0' ; ++i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , texto[3][i] );
		tamValor = int_p_string( comparacoes , &valor );
		for( i = tamValor - 1 ; i >= 0 ; --i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , valor[i] );
		printa_tab;

		/* Printa as trocas e seu valor */
		for( i = 0 ; texto[4][i] != '\0' ; ++i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , texto[4][i] );
		tamValor = int_p_string( trocas , &valor );
		for( i = tamValor - 1 ; i >= 0 ; --i ) glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , valor[i] );

	glRasterPos2f( -x , -y );
	glPopMatrix();

	#undef printa_tab
}

void populador( int opcao ){
	elementos = malloc( N * sizeof( int ) );
	if( !elementos ){ printf("ERRO! Ponteiro elementos não mallocado!\n"); exit(1);}
	switch( opcao ){
		case 0:
			popula_zero( N , elementos );
			break;
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

void termina_animacao( void ){
	iniciou_animacao = 0;
}