/*
 *
 *	Arquivo de medição da atricuição a
 * 	variável inteira.
 * 
 *	Arquivo visa medir tempo gasto para
 * 	a atribuição a uma variável do tipo
 * 	inteiro.
 *
 *
 */

#define NOME_BENCH "Atribuição p/ inteiro"
#define NOME_ARQUIVO "atribuicao_int"

#include "../benchmarking.h"

CLOCK_RETURN attr_int();

int main( void ){

	benchmarking( &attr_int );

	return 0;
}

CLOCK_RETURN attr_int(){
	CLOCK_RETURN retorno; clock_t n0,n1; int x;

	n0 = clock();
	x = 5;
	n1 = clock();

	retorno.n0 = n0;
	retorno.n1 = n1;
	return retorno;
}
