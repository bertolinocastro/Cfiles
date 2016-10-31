#include <time.h>

void ativa_populador( int opcao );
void desativa_populador( void );

void menu_populador( unsigned char key, int x, int y );

#define COMP_TEXT "Comparacoes: "
#define TROCAS_TEXT "Trocas: "
#define TEMPO_TEXT "Tempo: "
#define PASSOS_TEXT "Passos: "
#define N_TEXT "No de chaves: "
#define ESPACADOR_TEXT "Espacador(gap): "

void desenha_tela_populador( void );

void cria_quadrado( int opcao );
void escreve_na_tela_populador( int x , int y );
void populador( int opcao );
void atualiza_tela_populador( void );
void reposiciona_vertices( void );
void termina_animacao( void );

void (* chama_ordenador) ( void );

int passos;
time_t tempoTotal;
time_t tempoDeInicioDaAnim;
int comparacoes;
int trocas;
int espacador;
short trocou;
short iniciou_animacao;
int *elementos;
GLfloat *pares_elementos;

float xElem;
float yElem;
int raio_elemento;

int iElem;
int jElem;