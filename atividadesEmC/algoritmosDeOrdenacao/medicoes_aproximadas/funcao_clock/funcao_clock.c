/*
 *
 *	Arquivo de medição da função clock().
 * 
 *	Arquivo visa medir tempo gasto para
 * 	utilização da função juntamente com
 *	a atribuição a uma variável.
 *
 *
 */

#define NOME_ARQUIVO "funcao_clock_saida"
#define NOME_BENCH "Funcao Clock()"
#include "../benchmarking.h"

CLOCK_RETURN funcao_clock(void);

int main(void){

	benchmarking( &funcao_clock );

	return 0;
}

CLOCK_RETURN funcao_clock( void ){
	CLOCK_RETURN retorno; clock_t n0,n1;

	n0 = clock();
	n1 = clock();

	retorno.n0 = n0;
	retorno.n1 = n1;

	return retorno;
}