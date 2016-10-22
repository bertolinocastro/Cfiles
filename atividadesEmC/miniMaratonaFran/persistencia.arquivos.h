/*
 *	Arquivo-cabeçalho das funções de persistência de dados
 *	em arquivos para a mini-maratona da Prof.ª Fran.
 *
 *	Equipe: Ícaro, Thiago, Bertolino
 *
 */

afazeres * buscaDados( char *endereco );

short escreveDados( afazeres *vetor , size_t tamVet , char *endereco );

afazeres * buscaDados( char *endereco ){
	FILE *arquivo; size_t indices_lidos , indices_do_arquivo; unsigned int loop = 0;
	afazeres *dadosDoArquivo = NULL;

	arquivo = fopen( endereco , "rb" );

	if( !arquivo ){ fprintf(stderr, "\n\n%sNÂO FOI POSSÌVEL ABRIR O ARQUIVO : %s.\n%sArquivo possivelmente inexistente.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return NULL; }


	dadosDoArquivo = (afazeres *) realloc( dadosDoArquivo , sizeof( arquivo ) );

	indices_do_arquivo = sizeof( arquivo ) / sizeof( afazeres );

	if( (indices_lidos = fread( dadosDoArquivo , sizeof( afazeres ) , indices_do_arquivo , arquivo ) ) != indices_do_arquivo ){ fprintf(stderr, "%sProblema na leitura do arquivo!%s\n" , KRED , KWHT ); }

/*
	do{

		dadosDoArquivo = (afazeres *) realloc( dadosDoArquivo , ( loop + 1 ) * sizeof( afazeres ) );

		if( fseek( arquivo , loop * sizeof( afazeres ) , SEEK_SET ) ){ fprintf(stderr, "\n\n%sFALHA AO MOVER PONTEIRO DENTRO DO ARQUIVO: %s!%s\n", KRED , endereco , KWHT ); fclose( arquivo ); sleep( 3 ); return NULL; }

		indices_lidos = fread( (afazeres *) dadosDoArquivo , sizeof( afazeres ) , 1 , arquivo );

		printf( "DEBUG: indices_lidos %u feof %u ferror %u\n" , indices_lidos , feof( arquivo ) , ferror( arquivo ) );
	

		++loop;

	}while( indices_lidos == 1 && !feof( arquivo ) && !ferror( arquivo ) );
*/

	if( ferror( arquivo ) ){ fprintf(stderr, "\n\n%sERRO COM O ARQUIVO: %s!%s\n", KRED , endereco , KWHT ); fclose( arquivo ); sleep( 3 ); return NULL; }
	fclose( arquivo );

	if( !dadosDoArquivo ){ fprintf(stderr, "\n\n%sERRO COM O PONTEIRO!%s\n", KRED , KWHT ); free( dadosDoArquivo ); return NULL; }

	printf( "DEBUG: loop %u\n" , loop );
	printf( "DEBUG: %s %u %u %u\n\n" , dadosDoArquivo[0].nomeAtv , dadosDoArquivo[0].status , dadosDoArquivo[0].horasGast , dadosDoArquivo[0].final );

	sleep( 2 );

	return dadosDoArquivo;

}



short escreveDados( afazeres *vetor , size_t tamVet , char *endereco ){
	FILE *arquivo;

	if( !vetor ){ fprintf(stderr, "\n\n%sVETOR PARA SALVAMENTO INEXISTENTE!%s", KRED , KWHT ); return 0; }

	if( !(arquivo = fopen( endereco , "wb" )) ){ fprintf(stderr, "\n\n%sNÂO FOI POSSÌVEL ABRIR/CRIAR O ARQUIVO PARA SALVAR: %s.\n%sPossível falta de permissão.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return 0; }

	if( fwrite( vetor , sizeof( afazeres ) , tamVet , arquivo ) < tamVet ){ fprintf(stderr, "\n\n%sNÂO FOI POSSÌVEL ESCREVER NO ARQUIVO: %s.\n%sPossível falta de permissão.%s\n", KRED , endereco , KYEL , KWHT ); sleep( 4 ); return 0; }

	if( ferror( arquivo ) ){ fprintf(stderr, "\n\n%sERRO COM O ARQUIVO: %s!%s\n", KRED , endereco , KWHT ); fclose( arquivo ); sleep( 3 ); return 0; }
	fclose( arquivo );

	return 1;

}

