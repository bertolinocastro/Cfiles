#include <stdio.h>
#include <stdlib.h>
#include "openGL.h"
#include "populadores.h"
#include "../__sorts/bubble_sort/modelo_vetor/bubble_sort.h"
#include "int_p_string.h"

GLfloat topoLinhas;

void ativa_populador( int opcao ){

	xElem = (float) tela_Larg / N;
	raio_elemento = xElem/2;
	if( raio_elemento < 1 ) raio_elemento = 1;
	yElem = (float) (tela_Alt - MARGEM_SUPERIOR - ALT_TEXTO - raio_elemento) / N;

	topoLinhas = (float) (tela_Alt - MARGEM_SUPERIOR - ALT_TEXTO);

	cria_quadrado( 0 );

	switch( opcao ){
		case 1:
			chama_ordenador = &bubble_sort;
			break;
		case 2:
			chama_ordenador = &bubble_sort;
			break;
		case 3:
			chama_ordenador = &bubble_sort;
			break;
		case 4:
			chama_ordenador = &bubble_sort;
			break;
	}

	glutDisplayFunc( &desenha_tela_populador );
	glutKeyboardFunc( &menu_populador );
	glutPostRedisplay();

}

void desativa_populador( void ){
	ativa_sorts();
}


void menu_populador( unsigned char key, int x, int y ){
	static short pode_iniciar = 0;
	if( key == '0' ) pode_iniciar = 0, cria_quadrado( 0 );
	else if( key == '1' ) pode_iniciar = 1, cria_quadrado( 1 ); /* Inicio da animação */
	else if( key == '2' ) pode_iniciar = 1, cria_quadrado( 2 );
	else if( key == '3' ) pode_iniciar = 1, cria_quadrado( 3 );
	else if( key == '4' ) pode_iniciar = 1, cria_quadrado( 4 );
	else if( key == 32 ){ if( pode_iniciar ) pode_iniciar = 0, iniciou_animacao = 1, chama_ordenador(); }
	else if( key == 27 ) desativa_populador(); /* Retorna para Menu_sorts */
	
}

void desenha_tela_populador( void ){
	limpa_tela();
	atualiza_tela_populador();
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

void atualiza_tela_populador( void ){

	GLfloat cores[12];

	GLfloat coords_linhas[] = {
		iElem*xElem + raio_elemento, 0.0f, 0.1f, /* esquerda 1 */
		iElem*xElem + raio_elemento, topoLinhas, 0.1f, /* esquerda 2 */
		jElem*xElem + raio_elemento, 0.0f, 0.1f, /* direita 1 */
		jElem*xElem + raio_elemento, topoLinhas, 0.1f /* direita 2 */
	};

	if( trocou ){
		/* Injeta a cor Vermelha em todos os vértices */
		memcpy( cores , (GLfloat [12]){
			255.0f, 0.0f, 0.0f,
			255.0f, 0.0f, 0.0f,
			255.0f, 0.0f, 0.0f,
			255.0f, 0.0f, 0.0f
		} , 12*sizeof( GLfloat ) );

		reposiciona_vertices(); trocou = 0;
	}else{
		/* Injeta a cor Verde em todos os vértices */
		memcpy( cores , (GLfloat [12]){
			0.0f, 255.0f, 0.0f,
			0.0f, 255.0f, 0.0f,
			0.0f, 255.0f, 0.0f,
			0.0f, 255.0f, 0.0f
		} , 12*sizeof( GLfloat ) );
	}

	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_COLOR_ARRAY );

	/* Desenho das linhas verticais */
		glColorPointer( 3 , GL_FLOAT , 0 , cores );
		glLineWidth( raio_elemento );
		glVertexPointer( 3 , GL_FLOAT , 0 , coords_linhas );

		glDrawArrays( GL_LINES , 0 , 4 );

	glDisableClientState( GL_COLOR_ARRAY );
	
	/* Desenho dos pontos */
		glPointSize( raio_elemento );
		glVertexPointer( 2 , GL_FLOAT , 0 , pares_elementos );

		glDrawArrays( GL_POINTS , 0 , N );
	
	glDisableClientState( GL_VERTEX_ARRAY );

	escreve_na_tela_populador( MARGEM_ESQUERDA , tela_Alt - ALT_TEXTO );

	glutSwapBuffers();
}

void escreve_na_tela_populador( int x , int y ){
	int i , tamValor; char *valor = NULL;
	#define printa_tab (glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , 9 ),glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , 9 ))
	
	const char texto[][COMP_MAX_STR_OPCOES] = {
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