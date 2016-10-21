/*
 *	Arquivo-cabeçalho das funções de persistência de dados
 *	em arquivos para a mini-maratona da Prof.ª Fran.
 *
 *	Equipe: Ícaro, Thiago, Bertolino
 *
 */

afazeres * buscaDados( char *endereco ){
	FILE *arquivo; size_t índices_lidos;

	arquivo = fopen( endereco , "rb" );

	if( !arquivo ){ fprintf(stderr, "\n%s  \n", KRED ); return NULL; }

	do{

	}while(  );



}