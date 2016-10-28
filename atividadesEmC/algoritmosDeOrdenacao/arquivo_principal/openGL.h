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
#define MARGEM_SUPERIOR 10.0f
#define MARGEM_ESQUERDA 40.0f
#define ALT_TEXTO 20.0f

short cria_janela( int *argc , char **argv );
void inicia_animacao( unsigned char key, int x, int y );
void desenha_tela( void );
void limpa_tela( void );
void cria_quadrado( int opcao );
void escreve_na_tela( int x , int y , char *texto );
void populador( int opcao );
void atualiza_tela( void );
void reposiciona_vertices( void );
int tela_Larg , tela_Alt;
int janela;
float xElem;
float yElem;
int raio_elemento;
int N;
int *elementos;
GLfloat *pares_elementos;