/*
 *	Transcrição da resolução da prova de
 * 	Programação de Aplicativos - CAI TEC
 *	Informática - Desenvolvimento de Soft
 *	ware - turma 51487.
 * 
 *	Docente: Francisleide Almeida
 *	Discente: José Gabriel Bertolino de Castro
 *
 *	Questão: 6
 *
 */

#include <stdio.h>

/*
 *	Código transcrito
 */

unsigned long pot( unsigned long k, unsigned long n ){
	if( !n ) return 1;
	return k * pot( k, n - 1 );
}

int main( void ){
	unsigned long x, y;
	scanf( " %lu %lu", &x, &y );
	printf( " %lu \n", pot( x, y ) );
	return 0;
}