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


#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	clock_t n0 , n1 , des; unsigned int i=0;
	FILE *arquivo;

	arquivo = fopen( "saidas/funcao_clock_saida.txt" , "w" );
	if( !arquivo ) printf( "Falha ao abrir arquivo\n" ) , exit(1);

	fprintf( arquivo , "\n%s\n" , "Arquivo de resultados funcao_clock_saida" );
	fprintf( arquivo , "\n%-15s | %-15s | %-15s\n\n" , "n0" , "n1" , "n1-n0" );

	while( i++ < 10000 ){
		n0 = clock();
		des = clock();
		n1 = clock();

		fprintf( arquivo , "%15llu | %15llu | %15llu\n" , (unsigned long long int) n0 , (unsigned long long int) n1 , (unsigned long long int) ( n1 - n0 ) );
	}

	fclose( arquivo );

	return 0;
}