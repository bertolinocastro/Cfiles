#include "bubble_sort.h"
#include "../../../arquivo_principal/openGL.h"
#include <stdio.h>
#include <time.h>

void bubble_sort( void ){
	int i , j , aux; clock_t start , end;
	printf("Elementos: ");
	for( i = 0 ; i < N ; ++i ) printf(" %d", elementos[i] );
		printf("\n");

	for( i = 0 ; i < N - 1 ; ++i ){
		for( j = i + 1 ; j < N ; ++j ){
			if( elementos[i] > elementos[j] ){
				aux = elementos[i];
				elementos[i] = elementos[j];
				elementos[j] = aux;
				start = clock();
				do{
					end = clock();
				}while( start + 2*CLOCKS_PER_SEC/100 >= end );
				desenha_tela();
			}
			printf("DEBUG: ele i:%d = %d j:%d = %d\n", i , elementos[i] , j , elementos[j] );
		}

	}
	printf("Elementos: ");
	for( i = 0 ; i < N ; ++i ) printf(" %d", elementos[i] );
		printf("\n");

}