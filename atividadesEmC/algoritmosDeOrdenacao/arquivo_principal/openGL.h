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

#include "menu.populador.openGL.h"
#include "menu.sorts.openGL.h"

#ifndef HAVE_OWN_OPENGL_LIB_H
	#define HAVE_OWN_OPEN_GL_LIB_H
#endif

#define COMPONENTE_PROPORCAO_TEMPO 4000.0f/CLOCKS_PER_SEC

#define JANELA_LARG_INI 800
#define JANELA_ALT_INI	600
#define MARGEM_SUPERIOR 10.0f
#define MARGEM_ESQUERDA 40.0f
#define ALT_TEXTO 20.0f

#define COMP_MAX_STR_OPCOES 30

void cria_janela( int *argc , char **argv );
void limpa_tela( void );

int tela_Larg , tela_Alt;
int janela;

int N;
