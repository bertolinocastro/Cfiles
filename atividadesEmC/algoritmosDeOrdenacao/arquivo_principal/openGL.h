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

#ifndef HAVE_OWN_OPENGL_LIB_H
	#define HAVE_OWN_OPEN_GL_LIB_H
#endif

#define COMPONENTE_PROPORCAO_TEMPO 4000.0f/CLOCKS_PER_SEC

#define JANELA_LARG_INI 800
#define JANELA_ALT_INI	600
#define MARGEM_SUPERIOR 10.0f
#define MARGEM_ESQUERDA 40.0f
#define ALT_TEXTO 20.0f

#define COMP_TEXT "Comparacoes: "
#define TROCAS_TEXT "Trocas: "
#define TEMPO_TEXT "Tempo: "
#define PASSOS_TEXT "Passos: "
#define N_TEXT "No de chaves: "

short cria_janela( int *argc , char **argv );
void inicia_animacao( unsigned char key, int x, int y );
void desenha_tela( void );
void limpa_tela( void );
void cria_quadrado( int opcao );
void escreve_na_tela( int x , int y );
void populador( int opcao );
void atualiza_tela( void );
void reposiciona_vertices( void );
void termina_animacao( void );
int tela_Larg , tela_Alt;
int janela;
float xElem;
float yElem;
int raio_elemento;
int N;
int passos;
time_t tempoTotal;
time_t tempoDeInicioDaAnim;
int comparacoes;
int trocas;
short trocou;
short iniciou_animacao;
int *elementos;
GLfloat *pares_elementos;