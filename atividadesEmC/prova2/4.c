/*
 *	Transcrição da resolução da prova de
 * 	Programação de Aplicativos - CAI TEC
 *	Informática - Desenvolvimento de Soft
 *	ware - turma 51487.
 * 
 *	Docente: Francisleide Almeida
 *	Discente: José Gabriel Bertolino de Castro
 *
 *	Questão: 4
 *
 */

#include <stdio.h>
#include <math.h>

/*
 *	Código transcrito
 */

typedef struct{
	char nome[100];
	float altura;
	float peso;
	char sexo;
	int cpf;
} pessoa;

int main( void ){
	pessoa *pessoas; int n, cpftmp, achou = 0, i;
	scanf( " %d", &n );

	pessoas = malloc( n * sizeof( *pessoas ) );

	for( i = 0; i < n; ++i )
		scanf( " %s %f %f %c %d", &pessoa[i].nome, // Erro! Label do vetor escrito sem o 's' final.
		&pessoa[i].altura, &pessoa[i].peso, 	   // Erro! Mesmo do anterior.
		&pessoa[i].sexo, &pessoa[i].cpf );		   // Erro! Mesmo do anterior.

	scanf( " %d", &cpftmp );

	for( i = 0; i < n && !achou; ++i )
		if( pessoas[i].cpf == cpftmp ) achou = 1;

	if( !achou ) printf( "Não achou!\n" ); return 0;

	printf( " %f\n", (pessoa[i-1].peso / pow( pessoa[i-1].altura, 2 )) );
	// ^ Erro! Label do vetor escrito sem o 's' final.

	return 0;
}