#include "openGL.h"
#include "menu.sorts.openGL.h"
#include <stdio.h>
#include <time.h>

float margemHorMenu;
float margemVerMenu;
float espacamentoOpcoesMenu;

const char texto[][COMP_MAX_STR_OPCOES] = {
	{BERTOLINO_SORT},
	{BUBBLE_SORT},
	{INSERTION_SORT},
	{SHELL_SORT},
	{QUICK_SORT}
};

void ativa_sorts( void ){

	margemHorMenu = (tela_Larg - calcula_largura_texto_menu_sort( )) / 2.0f;
	margemVerMenu = (tela_Alt  - calcula_altura_texto_menu_sort( ))/ 2.0f;
	espacamentoOpcoesMenu = glutBitmapWidth( GLUT_BITMAP_HELVETICA_18 , 'M' );

	glutDisplayFunc( &desenha_tela_sorts );
	glutKeyboardFunc( &menu_sorts );
	glutPostRedisplay();

}

void menu_sorts( unsigned char key, int x, int y ){
	
	if( key == '1' ) ativa_populador( 1 );
	else if( key == '2' ) ativa_populador( 2 );
	else if( key == '3' ) ativa_populador( 3 );
	else if( key == '4' ) ativa_populador( 4 );
	else if( key == '5' ) ativa_populador( 5 );
	else if( key == 27 ) glutDestroyWindow( janela ); /* Mata a animação */
}

void desenha_tela_sorts( void ){
	limpa_tela();
	escreve_na_tela_sorts();
	glutSwapBuffers();
}

void escreve_na_tela_sorts( void ){
	int i , j ;

	glPushMatrix();
	glRasterPos2f( margemHorMenu , tela_Alt - margemVerMenu );

		for( j = 0 ; j < QTD_PAL_MENU_SORT ; ++j ){
			glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , (j+1) + '0' ); glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , '.' );
			for( i = 0 ; i < COMP_MAX_STR_OPCOES ; ++i ){
				glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , texto[j][i] );
			} 
			glRasterPos2f( margemHorMenu , tela_Alt - margemVerMenu - espacamentoOpcoesMenu*(j+1)*2 );
		}

	glPopMatrix();
}


int calcula_largura_texto_menu_sort( void ){
	int i = 0 , j = 0 , tamTotTmp = 0 , tamTot = 0 , nPal = QTD_PAL_MENU_SORT;
	for( j = 0 ; j < nPal ; ++j ){
		for( i = 0 , tamTotTmp = 0 ; *(*(texto+j)+i) ; ++i ) tamTotTmp += glutBitmapWidth( GLUT_BITMAP_HELVETICA_18 , *(*(texto+j)+i) );
		if( tamTot < tamTotTmp ) tamTot = tamTotTmp;
	}
	return tamTot;
}

int calcula_altura_texto_menu_sort( void ){
	return ( QTD_PAL_MENU_SORT * 2 * glutBitmapWidth( GLUT_BITMAP_HELVETICA_18 , 'M' ) );
}
