/*
 *	Arquivo-cabeçalho de criação
 *	das funções em OpenGL/GLUT
 *	para o funcionamento da geração
 *	de gráficos dinâmicos.
 *
 */

#include <GL/glew.h>
#include <GL/glut.h>

#include "menu.populador.openGL.h"
#include "menu.sorts.openGL.h"

#define COMPONENTE_PROPORCAO_TEMPO 4000.0f/CLOCKS_PER_SEC

#define JANELA_LARG_INI 800
#define JANELA_ALT_INI	600
#define MARGEM_SUPERIOR 10.0f
#define MARGEM_ESQUERDA 40.0f
#define ALT_TEXTO 20.0f

#define COMP_MAX_STR_OPCOES 40

void cria_janela( int *argc , char **argv );
void limpa_tela( void );

int tela_Larg , tela_Alt;
int janela;

int N;
