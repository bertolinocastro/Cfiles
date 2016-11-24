/*
 *	Transcrição da resolução da prova de
 * 	Programação de Aplicativos - CAI TEC
 *	Informática - Desenvolvimento de Soft
 *	ware - turma 51487.
 * 
 *	Docente: Francisleide Almeida
 *	Discente: José Gabriel Bertolino de Castro
 *
 *	Questão: 5
 *
 *	*Obs: Código precisa ser compilado a partir do padrão C99.
 */

#include <stdio.h>

/*
 *	Código transcrito
 */

long fib( long n ){
	if( !n ) return 0;
	if( n == 1 ) return 1;
	return fib( n - 2 ) + fib( n - 1 );
}

int main( void ){
	int n;
	scanf( " %d", &n );
	for( int i = 0; i < n; ++i )
		printf( " %ld\n", fib( i ) );

	return 0;
}