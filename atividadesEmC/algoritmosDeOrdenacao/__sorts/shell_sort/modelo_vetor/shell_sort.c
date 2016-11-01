#include <math.h>
#include "shell_sort.h"
#include "../../../arquivo_principal/openGL.h"
#include "../../../arquivo_principal/delay.h"

void shell_sort( void ){
	int i, j, aux, gap, exp = 0;
	while( pow( 2, exp ) - 1 < N ) ++exp; /* Hibbard */
	gap = pow( 2, exp ) - 1;

	do{
		espacador = gap;
		comparacoes++; passos++;
		for( i = gap, passos++; i < N; comparacoes++, ++i, passos++ ){
			aux = elementos[i]; passos++;
			comparacoes++; iElem = i; jElem = i - gap;
			desenha_tela_populador();
			for( j = i - gap, passos++; j >= 0 && aux < elementos[j]; j -= gap, comparacoes++, trocas++, passos++ ){
				elementos[j+gap] = elementos[j]; passos++;
				trocou = 1; jElem = j;
				#ifdef COM_DELAY
					delay_ms( );
				#endif
				desenha_tela_populador();
			}
			elementos[j+gap] = aux; passos++;
			trocas++; jElem = j + gap;
			trocou = 1;
			#ifdef COM_DELAY
				delay_ms( );
			#endif
			desenha_tela_populador();
		}
	}while( --exp > 0 && (gap = pow( 2, exp ) - 1) >= 1 );
	espacador = gap; desenha_tela_populador();
	termina_animacao();
}