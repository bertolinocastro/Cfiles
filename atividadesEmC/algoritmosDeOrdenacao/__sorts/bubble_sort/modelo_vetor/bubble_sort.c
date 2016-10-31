#include "bubble_sort.h"
#include "../../../arquivo_principal/openGL.h"
#include "../../../arquivo_principal/delay.h"

void bubble_sort( void ){
	int i , j , aux; espacador = 0;
	for( i = 0 ; i < N - 1 ; ++i ){
		for( j = N - 1 ; j >= i + 1 ; --j ){
			iElem = j-1;
			jElem = j;
			comparacoes++;
			if( elementos[j] < elementos[j-1] ){
				trocas++;
				aux = elementos[j];
				elementos[j] = elementos[j-1];
				elementos[j-1] = aux;
				#ifdef COM_DELAY
					delay_ms( );
				#endif
				trocou = 1;
			}
			passos++;
			desenha_tela_populador();
		}
	}
	termina_animacao();
}