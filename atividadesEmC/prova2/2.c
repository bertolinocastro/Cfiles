/*
 *	Transcrição da resolução da prova de
 * 	Programação de Aplicativos - CAI TEC
 *	Informática - Desenvolvimento de Soft
 *	ware - turma 51487.
 * 
 *	Docente: Francisleide Almeida
 *	Discente: José Gabriel Bertolino de Castro
 *
 *	Questão: 2
 *
 */


#include <stdio.h>

/*
 *	Código transcrito
 */

int mdc( int m, int n ){
	int r;
	if( !(r = m % n) ) return m; // <--- Erro! Deveria ter retornado n.
	return mdc( n, r );			 // Levei em consideração o m = n, porém
								 // me esqueci no retorno anterior.
}

/*
 *	Código da questão (para testes e comparações)
 */

// int mdc( int m, int n ){
// 	int r;
// 	do{
// 		r = m % n;
// 		m = n;
// 		n = r;
// 	}while( r != 0 );
// 	return m;
// }

/*
 *	Função principal de testes de valores
 *	*Não consta na prova!
 */

int main( void ){

	printf( " %d \n", mdc( 10, 15 ) );
	printf( " %d \n", mdc( 15, 10 ) );
	printf( " %d \n", mdc( 12, 16 ) );
	printf( " %d \n", mdc( 3, 6 ) );
	printf( " %d \n", mdc( 100, 171 ) );

	return 0;
}

