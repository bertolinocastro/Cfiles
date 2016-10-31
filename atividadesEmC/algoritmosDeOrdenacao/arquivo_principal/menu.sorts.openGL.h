#define BERTOLINO_SORT "Bertolino Sort."
#define BUBBLE_SORT "Bubble Sort."
#define INSERTION_SORT "Insertion Sort."
#define SHELL_SORT "Shell Sort."
#define QUICK_SORT "Quick Sort. ( Nao funcional :-( )"

#define QTD_PAL_MENU_SORT 5

void ativa_sorts( void );

void menu_sorts( unsigned char key, int x, int y );
void desenha_tela_sorts( void );
void escreve_na_tela_sorts( void );


int calcula_largura_texto_menu_sort( void );
int calcula_altura_texto_menu_sort( void );