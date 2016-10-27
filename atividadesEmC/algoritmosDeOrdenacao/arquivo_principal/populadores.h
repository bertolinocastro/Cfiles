/*
 *	Arquivo-cabeçalho de populadores
 *	de vetores.
 *	
 *	
 *
 *
 */

#include <time.h>
#ifndef HAVE_STDLIB_H
	#include <stdlib.h>
#endif

int randomiza_com_limites( int min , int max );

void popula_aleatorio( int N , int *lista );
void popula_crescente( int N , int *lista );
void popula_descrescente( int N , int *lista );
void popula_50_porcento_iguais( int N , int *lista );

void semeia_rand(void);

void semeia_rand(void){
	/*srand( (unsigned) time(NULL) );*/
}

int randomiza_com_limites( int min , int max ){
	return ((rand()%(max-min+1)+min));
}

void popula_aleatorio( int N , int *lista ){
	int max = N , i;
	for( i = 0 ; i < N ; ++i ) lista[i] = randomiza_com_limites( 0 , max );
}

void popula_crescente( int N , int *lista ){
	int i = 0;
	while( i < N ) (lista[i] = i + 1),++i;
}

void popula_descrescente( int N , int *lista ){
	int i;
	for( i = 0 ; i < N ; ++i  ) lista[i] = N-i;
}

void popula_50_porcento_iguais( int N , int *lista ){
	int i = 0 , *listaTmp;
	int lim = (unsigned int)((N+1)/2);
	listaTmp = (int *) malloc( lim * sizeof( int ) );
	if( !listaTmp ) exit(1);
	while( i < lim ) listaTmp[i] = randomiza_com_limites( 0 , N ) , ++i;
	i = 0;
	while( i < lim ) lista[i] = lista[N-i-1] = listaTmp[i] , ++i;
	free(listaTmp);
}