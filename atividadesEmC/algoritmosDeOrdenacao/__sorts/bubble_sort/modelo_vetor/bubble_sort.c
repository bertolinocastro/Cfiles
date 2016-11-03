#include "bubble_sort.h"
#include "../../../arquivo_principal/openGL.h"
#include "../../../arquivo_principal/delay.h"

void bubble_sort( void ){
	int j, aux, tam, m; espacador = 0;
	tam = N-1;
	do{
		passos++;
		m = 0;
		passos++;
		for( j = 0 ; j < tam ; ++j ){
			passos++;
			comparacoes++;
			if( elementos[j] > elementos[j+1] ){
				aux = elementos[j];
				elementos[j] = elementos[j+1];
				elementos[j+1] = aux;
				m = j;
				trocas++;
				trocou = 1;
			}
			iElem = j;
			jElem = j+1;
			#ifdef COM_DELAY
				delay_ms( );
			#endif
			desenha_tela_populador();
		}
		tam = m;
		passos++;
	}while( tam >= 1 );
	termina_animacao();
}
