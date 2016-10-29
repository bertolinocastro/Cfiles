#include <stdio.h>
#include "bubble_sort.h"
#ifndef HAVE_OWN_OPENGL_LIB_H
	#include "../../../arquivo_principal/openGL.h"
#endif
#include "../../../arquivo_principal/delay.h"

void bubble_sort( void ){
	int i , j , aux;
	for( i = 0 ; i < N - 1 ; ++i ){
		for( j = i + 1 ; j < N ; ++j ){
			comparacoes++;
			if( elementos[i] > elementos[j] ){
				trocas++;
				aux = elementos[i];
				elementos[i] = elementos[j];
				elementos[j] = aux;
				delay_ms( );
				trocou = 1;
			}
			passos++;
			desenha_tela();
		}
	}
	termina_animacao();
}