/*
 *	Arquivo-cabeçalho das funções de persistência de dados
 *	em arquivos para a mini-maratona da Prof.ª Fran.
 *
 *	Equipe: Ícaro, Thiago, Bertolino
 *
 */

#include "tratamento.erros.h"
#define printaErro( _erno ) ()

afazeres * buscaDados( char *endereco );

char ** buscaDadosNomes( char *endereco );

short escreveDados( afazeres *vetor , size_t tamVet , char *endereco );

short escreveDadosNomes( afazeres *vetor , size_t tamVet , char *endereco );

char * completaNome( char *endereco , char *extensao );

size_t tamString( char *string );

afazeres * buscaDados( char *endereco ){
	FILE *arquivo; size_t indices_lidos; unsigned int loop = 0;
	afazeres *dadosDoArquivo = NULL , dadosTmp; char *enderecoCompleto , **nomesBuscados;

	if( !(enderecoCompleto = completaNome( endereco , ".bin" )) ){ fprintf(stderr, "\n\n%sNão foi possível concatenar o endereco %s com a extensão .bin.%s\n", KRED , endereco , KWHT ); sleep( 4 ); return NULL; }

	arquivo = fopen( enderecoCompleto , "rb" );

	if( !arquivo ){ fprintf(stderr, "\n\n%sNÂO FOI POSSÌVEL ABRIR O ARQUIVO : %s.\n%sArquivo possivelmente inexistente.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return NULL; }

	nomesBuscados = buscaDadosNomes( endereco );

	do{

		dadosDoArquivo = (afazeres *) realloc( dadosDoArquivo , ( loop + 1 ) * sizeof( afazeres ) );

		indices_lidos = fread( &dadosTmp , sizeof( afazeres ) , 1 , arquivo );

		dadosTmp.nomeAtv = nomesBuscados[loop];

		dadosDoArquivo[loop++] = dadosTmp;

		printf( "DEBUG: %u dadosTmp.nomeAtv %s\n" , loop , dadosTmp.nomeAtv );

	}while( indices_lidos == 1 && !feof( arquivo ) && !ferror( arquivo ) && !dadosTmp.final );

	if( ferror( arquivo ) ){ fprintf(stderr, "\n\n%sERRO COM O ARQUIVO: %s!%s\n", KRED , endereco , KWHT ); fclose( arquivo ); sleep( 3 ); return NULL; }
	fclose( arquivo );

	if( !dadosDoArquivo ){ fprintf(stderr, "\n\n%sERRO COM O PONTEIRO!%s\n", KRED , KWHT ); free( dadosDoArquivo ); sleep( 3 ); return NULL; }

	return dadosDoArquivo;

}

char ** buscaDadosNomes( char *endereco ){
	FILE *arquivo = NULL; char *enderecoCompleto = NULL, **nomeLido = NULL , letra; unsigned int loop = 0 , loopLetra;

	if( !(enderecoCompleto = completaNome( endereco , ".nomes" )) ){ fprintf(stderr, "\n\n%sNão foi possível concatenar o endereco %s com a extensão .nomes.%s\n", KRED , enderecoCompleto , KWHT ); sleep( 4 ); return NULL; }

	if( !(arquivo = fopen( enderecoCompleto , "r" )) ){ fprintf(stderr, "\n\n%sNão foi possível abrir/ler arquivo de atividades no endereco: %s.%s\n", KRED , enderecoCompleto , KWHT ); sleep( 3 ); return NULL; }

	do{

		nomeLido = (char **) realloc( nomeLido , ( loop + 1 ) * sizeof( char * ) );

		printf( "DEBUG: posição do ponteiro %ld\n" , ftell( arquivo ) );
		
		loopLetra = 0;
		while( ( letra = fgetc( arquivo ) ) != '\n' && letra != EOF ){
			printf( "DEBUG LETRA %c \n" , letra );
			nomeLido[loop] = (char *) realloc( nomeLido[loop] , ( loopLetra + 2 ) * sizeof( char ) );
			nomeLido[loop][loopLetra] = letra; loopLetra++;
		}
		if( letra != EOF ) nomeLido[loop][loopLetra] = '\0';
		
		printf("Atingiu o feof? %u\n", feof( arquivo ) );

		printf("DEBUG nomelido: %s\n", nomeLido[loop] );

		++loop;

	}while( !ferror( arquivo ) && !feof( arquivo ) && letra != EOF );

	if( ferror( arquivo ) ){ fprintf(stderr, "\n\n%sERRO COM O ARQUIVO: %s!%s\n", KRED , enderecoCompleto , KWHT ); fclose( arquivo ); sleep( 3 ); return NULL; }

	fclose( arquivo );

	return nomeLido;
}


short escreveDados( afazeres *vetor , size_t tamVet , char *endereco ){
	FILE *arquivo; char *enderecoCompleto;

	if( !(enderecoCompleto = completaNome( endereco , ".bin" )) ){ fprintf(stderr, "\n\n%sNão foi possível concatenar o endereco %s com a extensão .bin.%s\n", KRED , endereco , KWHT ); sleep( 4 ); return 0; }

	if( !vetor ){ fprintf(stderr, "\n\n%sVETOR PARA SALVAMENTO INEXISTENTE!%s", KRED , KWHT ); return 0; }

	if( !(arquivo = fopen( enderecoCompleto , "wb" )) ){ fprintf(stderr, "\n\n%sNÂO FOI POSSÌVEL ABRIR/CRIAR O ARQUIVO PARA SALVAR: %s.\n%sPossível falta de permissão.%s\n", KRED , enderecoCompleto , KYEL , KWHT ); sleep( 4 ); return 0; }

	if( fwrite( vetor , sizeof( afazeres ) , tamVet , arquivo ) < tamVet ){ fprintf(stderr, "\n\n%sNÂO FOI POSSÌVEL ESCREVER NO ARQUIVO: %s.\n%sPossível falta de permissão.%s\n", KRED , enderecoCompleto , KYEL , KWHT ); sleep( 4 ); return 0; }

	if( ferror( arquivo ) ){ fprintf(stderr, "\n\n%sERRO COM O ARQUIVO: %s!%s\n", KRED , enderecoCompleto , KWHT ); fclose( arquivo ); sleep( 3 ); return 0; }
	fclose( arquivo );

	if( !escreveDadosNomes( vetor , tamVet , endereco )){ fprintf(stderr, "\n\n%sFalha ao salvar os nomes das atividades no endereco: %s.nomes.%s\n", KRED , endereco , KWHT ); sleep( 3 ); return 0; }

	return 1;

}

short escreveDadosNomes( afazeres *vetor , size_t tamVet , char *endereco ){
	FILE *arquivo; char *enderecoCompleto; size_t passoNome = 0;

	if( !(enderecoCompleto = completaNome( endereco , ".nomes" )) ){ fprintf(stderr, "\n\n%sNão foi possível concatenar o endereco %s com a extensão .nomes.%s\n", KRED , enderecoCompleto , KWHT ); sleep( 4 ); return 0; }

	if( !vetor ){ fprintf(stderr, "\n\n%sVETOR PARA SALVAMENTO INEXISTENTE!%s", KRED , KWHT ); return 0; }

	if( !(arquivo = fopen( enderecoCompleto , "w" )) ){ fprintf(stderr, "\n\n%sNão foi possível abrir/criar arquivo de atividades no endereco: %s.%s\n", KRED , enderecoCompleto , KWHT ); sleep( 3 ); return 0; }

	while( !vetor[passoNome].final ) fputs( vetor[passoNome++].nomeAtv , arquivo ) , fputc( '\n' , arquivo );

	if( ferror( arquivo ) ){ fprintf(stderr, "\n\n%sERRO COM O ARQUIVO: %s!%s\n", KRED , enderecoCompleto , KWHT ); fclose( arquivo ); sleep( 3 ); return 0; }
	fclose( arquivo );

	return 1;

}

char * completaNome( char *endereco , char *extensao ){
	size_t tamEnd , tamExt , ind_P_Esc = 0; char *endTmp = NULL;

	if( !endereco ){ fprintf(stderr, "\n\n%sNão foi possível identificar o endereco: %s.\n%sPossível erro na passagem por parâmetro.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return 0; }
	if( !extensao ){ fprintf(stderr, "\n\n%sNão foi possível identificar a extensao: %s.\n%sPossível erro na passagem por parâmetro.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return 0; }

	if( !(tamEnd = tamString( endereco )) ){ fprintf(stderr, "\n\n%sProblema com o nome do arquivo: %s.\n%sNome do arquivo possivelmente com tamanho nulo.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return 0; }
	if( !(tamExt = tamString( extensao )) ){ fprintf(stderr, "\n\n%sProblema com o nome da extensão: %s.\n%sNome da extensão possivelmente com tamanho nulo.%s\n", KRED , extensao , KYEL , KWHT ); sleep( 4 ); return 0; }

	if( !(endTmp = (char *) realloc( endTmp , tamEnd + tamExt + 1 )) ){ fprintf(stderr, "\n\n%sNão foi possível alterar o tamanho do endereço: %s.\n%sFalha na realocação.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return 0; };

	while( ind_P_Esc < tamEnd )	endTmp[ind_P_Esc] = *endereco++ , ++ind_P_Esc;
	while( ind_P_Esc < tamEnd + tamExt ) endTmp[ind_P_Esc] = *extensao++ , ++ind_P_Esc;
	*(endTmp+ind_P_Esc) = '\0';

	if( !(endereco) ){ fprintf(stderr, "\n\n%sNão foi possível copiar a extensão: %s.\n%s\n", KRED , extensao , KWHT ); sleep( 4 ); return 0; }
	return endTmp;
}

size_t tamString( char *string ){
	size_t tamStr = 0;
	if( !string ){ fprintf(stderr, "\n\n%sNão foi possível medir a string: %s.\n%sString vazia.%s\n", KRED , string , KYEL , KWHT ); sleep( 4 ); return 0; }
	while( *string++ != '\0' ) ++tamStr;
	return tamStr;
}