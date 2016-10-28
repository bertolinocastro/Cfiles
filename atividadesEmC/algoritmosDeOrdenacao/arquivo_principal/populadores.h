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