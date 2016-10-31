#include "bertolino_sort.h"
#include "../../../arquivo_principal/openGL.h"
#include "../../../arquivo_principal/delay.h"

void bertolino_sort( void ){
	int i , j , aux; espacador = 0;
	for( i = 0 ; i < N - 1 ; ++i ){
		iElem = i;
		for( j = i + 1 ; j < N ; ++j ){
			jElem = j;
			comparacoes++;
			if( elementos[i] > elementos[j] ){
				trocas++;
				aux = elementos[i];
				elementos[i] = elementos[j];
				elementos[j] = aux;
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