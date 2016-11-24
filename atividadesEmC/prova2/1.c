/*
 *	Transcrição da resolução da prova de
 * 	Programação de Aplicativos - CAI TEC
 *	Informática - Desenvolvimento de Soft
 *	ware - turma 51487.
 * 
 *	Docente: Francisleide Almeida
 *	Discente: José Gabriel Bertolino de Castro
 *
 *	Questão: 1
 *
 *	*Obs: Código precisa ser compilado a partir do padrão C99.
 */

#include <stdio.h>

/*
 *	Código transcrito
 */

typedef struct{
	int dia, mes, ano;
} data;

typedef struct{
	char nome[100];
	float media;
	data dt_nasc;
} aluno;

void imprime( aluno tmp ){
	printf( "%s -> %.2f | %d - %d - %d \n", tmp.nome,
	tmp.media, tmp.dt_nasc.dia, tmp.dt_nasc.mes,
	tmp.dt_nasc.ano );
}

int main( void ){
	aluno alunos[2];

	for( int i = 0; i < 2; ++i )
		scanf( " %s %f %d %d %d", &alunos[i].nome,
		&alunos[i].media, &alunos[i].dt_nasc.dia,
		&alunos[i].dt_nasc.mes, &alunos[i].dt_nasc.ano );

	for( int i = 0; i < 2; ++i )
		imprime( alunos[i] );

	return 0;
}
