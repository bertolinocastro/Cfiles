#include "quick_sort.h"
#include "../../../arquivo_principal/openGL.h"
#include "../../../arquivo_principal/delay.h"

void quick_sort_starter( int *vet, int left, int right );
int quick_sort_divisor( int *vet, int left, int right );

void quick_sort( void ){
	quick_sort_starter( elementos, 0, N-1 );
	desenha_tela_populador();
	termina_animacao();
}

void quick_sort_starter( int *vet, int left, int right ){
	int r;
	comparacoes++;
	if( right > left ){
		passos++;
		r = quick_sort_divisor( vet, left, right );
		desenha_tela_populador();
		quick_sort_starter( vet, left, r-1 );
		desenha_tela_populador();
		passos++;
		quick_sort_starter( vet, r+1, right );
		desenha_tela_populador();
	}
	desenha_tela_populador();
}

int quick_sort_divisor( int *vet, int left, int right ){
	int i, j, aux;
	int pivot = elementos[right];
	iElem = i = left-1;
	for( j = left+1; j <= right-1; ++j ){
		jElem = j;
		passos++;
		comparacoes++;
		if( elementos[j] <= pivot ){
			++i;
			aux = elementos[i];
			elementos[i] = elementos[j];
			elementos[j] = aux;
			trocas++;
			desenha_tela_populador();
		}
		aux = elementos[i+1];
		elementos[i+1] = elementos[right];
		elementos[right] = aux;
		#ifdef COM_DELAY
			delay_ms( );
		#endif
		iElem = i;
		trocas++;
		trocou = 1;
		desenha_tela_populador();
	}
	return i+1;
}
