/*
 *	Transcrição da resolução da prova de
 * 	Programação de Aplicativos - CAI TEC
 *	Informática - Desenvolvimento de Soft
 *	ware - turma 51487.
 * 
 *	Docente: Francisleide Almeida
 *	Discente: José Gabriel Bertolino de Castro
 *
 *	Questão: 3
 *
 */

#include <stdio.h>

/*
 *	Código transcrito
 */

int soma_par_vet( int *ptr, int n ){
	static int sum = 0, i = 0; // Erro! sum deveria ser iniciado com prt[0].
	if( i + 2 > n ) return 0;  // Erro! Deveria ter retornado sum;
	sum += ptr[i]; i += 2;     // Erro! sum deveria ser incrementado com ptr[i+=2].
	return soma_par_vet( int *ptr, int n ); // Erro! Não é preciso comentar...
}

/*
 *	Função principal de testes de valores
 *	*Não consta na prova!
 */

int main( void ){

	int const tam = 11;
	int vet[tam] = {2,2,2,2,2,2,2,2,2,3,3};

	printf( " %d \n", soma_par_vet( vet, tam ) );

	return 0;
}