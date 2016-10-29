#include <stdio.h>
#include <stdlib.h>
#include "openGL.h"
#include "populadores.h"
#include "../__sorts/todos_sorts.h"
#include "int_p_string.h"

void cria_janela( int *argc , char **argv ){
	GLenum erro;
	glutInit( argc , argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( JANELA_LARG_INI , JANELA_ALT_INI );
	janela = glutCreateWindow( "Algoritmos de Ordenacao" );

	glutDisplayFunc( &desenha_tela_sorts );
	glutKeyboardFunc( &menu_sorts );

	glutFullScreen();

	tela_Larg = glutGet(GLUT_SCREEN_WIDTH);
	tela_Alt = glutGet(GLUT_SCREEN_HEIGHT);

	/* Modulos dos vetores (G.A.) para as operações do menu_sorts */
	ativa_sorts();

	glViewport( 0.0f , 0.0f , tela_Larg , tela_Alt );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	glOrtho( 0 , tela_Larg , 0 , tela_Alt , -100 , 100 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

	if( (erro = glewInit()) != GLEW_OK ){
		fprintf(stderr, "Erro ao carregar GLEW: %s\n", glewGetErrorString( erro ) );
		exit( 1 );
	}

	glutMainLoop();
}

void limpa_tela( void ){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
