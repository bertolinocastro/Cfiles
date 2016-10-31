#include "insertion_sort.h"
#include "../../../arquivo_principal/openGL.h"
#include "../../../arquivo_principal/delay.h"

void insertion_sort( void ){
	int i, j, aux;
	comparacoes++;passos++;
	for( i = 1 ; i < N ; ++i ){
		aux = elementos[i];
		passos++;
		passos++; comparacoes++;
		for( j = i - 1 ; j >= 0 && aux < elementos[j] ; --j ){
			iElem = j + 1;
			jElem = j;
			elementos[j+1] = elementos[j];
			trocas++;passos++;
			#ifdef COM_DELAY
				delay_ms( );
			#endif
			trocou = 1;
			desenha_tela_populador();
			comparacoes++;
		}
		elementos[j+1] = aux;
		passos++;
		trocou = 1;
		desenha_tela_populador();
		comparacoes++;
	}
	termina_animacao();
}
