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
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef NOME_BENCH
	#define NOME_BENCH "Benchmarking_sem_nome"
#endif
#ifndef NOME_ARQUIVO
	#define NOME_ARQUIVO "arquivo_de_saida_benchmarking"
#endif

#define MEDICOES 100000
#define MEDICOES_DB (long double) MEDICOES

typedef struct{
	clock_t n0;
	clock_t n1;
} CLOCK_RETURN;

void benchmarking( CLOCK_RETURN (*func) (void) );

void benchmarking( CLOCK_RETURN (*func) (void) ){
	clock_t n0 , n1 , dif , nMedio = 0 , n0i[MEDICOES] , n1i[MEDICOES] , difi[MEDICOES]; unsigned int i=0; long double nMedioLG = 0 , s2 = 0 , s = 0;
	FILE *arquivo; CLOCK_RETURN retornos;

	while( i < MEDICOES ){

		retornos = func();

		n0 = retornos.n0;
		n1 = retornos.n1;
		dif = ( n1 - n0 );

		n0i[i] = n0;
		n1i[i] = n1;
		nMedio += dif; /* Cálculo do N barra (valor médio de N) */
		difi[i] = dif; /* Armazenamento dos Ni medidos */
		++i;
	}

	nMedioLG = nMedio / MEDICOES_DB;

	for( i = 0 ; i < MEDICOES ; ++i ){
		s2 += (long double) pow( difi[i] - nMedioLG , 2 ); /* Cálculo da variância: média aritmética do quadrado da diferença entre Ni e N médio, OBS: Divisão no passo seguinte. */
	}

	s = (long double) sqrt(s2/MEDICOES_DB); /* Cálculo do desvio padrão: raíz quadrada da variância. OBS: Divisão da variância contida no argumento da função.  */ 

	/* Abertura para inserção dos dados no arquivo */
	arquivo = fopen( "saidas/"NOME_ARQUIVO".txt" , "w" );
	if( !arquivo ) printf( "Falha ao abrir arquivo\n" ) , exit(1);

	fprintf( arquivo , "\nArquivo de benchmarking estatístico da "NOME_BENCH" da biblioteca <time.h>\n" );
	fprintf( arquivo , "\n%s\n%s%i%s\n" , "Arquivo de resultados "NOME_ARQUIVO"." , "Amostragem de ", MEDICOES ," Ni." );
	
	fprintf( arquivo , "\n%20s %40LG" , "N médio:" , nMedioLG );
	fprintf( arquivo , "\n%20s %40LG" , "Desvio padrão:" , s );

	fprintf( arquivo , "\n\n---------------------------------------------------------------------------------------------\n" );
	
	fprintf( arquivo , "\n%-15s | %-15s | %-15s\n\n" , "n0" , "n1" , "n1-n0" );
	for( i = 0 ; i < MEDICOES ; ++i ){
		fprintf( arquivo , "%15llu | %15llu | %15llu\n" , (unsigned long long int) n0i[i] , (unsigned long long int) n1i[i] , (unsigned long long int) difi[i] );
	}
	
	fclose( arquivo );
	/* Fechamento do arquivo */
}
