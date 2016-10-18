#include "string.variavel.h"

char x;

typedef struct{
	char nomeAtv[1024];
	short status;
	unsigned int horasGast;
} afazeres;

afazeres *atividades;

short cadastrar( unsigned int qtd );
void editar( unsigned int qtd );
void excluir( unsigned int qtd );
void relatorio( unsigned int qtd );

void printaTudo( unsigned int qtd , short estado );

void limpaVet( unsigned int pos , unsigned int qtd );

unsigned int cadastrados = 0;

int main( void ){

	unsigned int opcao;

	do{

		printf( "Menu:\n" );
		printf( "\tOpcao 1 : Cadastrar\n" );
		printf( "\tOpcao 2 : Editar\n" );
		printf( "\tOpcao 3 : Excluir\n" );
		printf( "\tOpcao 4 : Relatorio\n" );
		printf( "--Para sair digite 0: \n" );

		printf( "Escolha a opcao: " );
		scanf( "%d" , &opcao );

	   	while( x != '\n' && x != EOF ) x = getc( stdin ) ;

		switch( opcao ){
			case 1:
				do{
					atividades = realloc( atividades , ++cadastrados );
				}while( cadastrar( cadastrados ) != 0 );
				break;
			case 2:
				editar( cadastrados );
				break;
			case 3:
				excluir( cadastrados );
				break;
			case 4:
				relatorio( cadastrados );
				break;
		}

	}while( opcao != 0 );

	return 0;
}

short cadastrar( unsigned int qtd ){

	char querer = 'a';

	printf( "\n\tDigite o nome da atividade: " );
	scanf( "%s" , atividades[qtd-1].nomeAtv );

   	while( x != '\n' && x != EOF ) x = getc( stdin ) ;

	atividades[qtd-1].status = 0;

	printf( "\n\tDeseja cadastrar outra atividade? (S/N)" );
	while( querer != 's' && querer != 'S' && querer != 'n' && querer != 'N' ) { scanf( "%c" , &querer ); while( x != '\n' && x != EOF ) x = getc( stdin ) ;};

	if( querer == 's' || querer == 'S' ) return 1 ;
	else return 0;

}

void editar( unsigned int qtd ){
	
	unsigned int id = 0;

	printaTudo( qtd , 2 );

	printf( "\n\tDigite qual o ID da atividade deseja editar: " );
	scanf( "%u" , &id  );

	printf( "\n\tAtividade %u : 'quantas horas foram gastas para sua resolução?' " , id );
	scanf( "%u" , &atividades[id-1].horasGast );

	atividades[id-1].status = 1;

}

void excluir( unsigned int qtd ){

	unsigned int id = 0;

	printaTudo( qtd , 2 );

	printf( "\n\tDigite qual o ID da atividade deseja excluir: " );
	scanf( "%u" , &id  );

	limpaVet( id - 1 , qtd );

}
void relatorio( unsigned int qtd ){
	printaTudo( qtd , 1 );
}

void printaTudo( unsigned int qtd , short estado ){

	unsigned int j = 0 , jTot = 0 , jY = 0;
	switch( estado ){
		case 1:

			while( j < qtd ){
				if( atividades[j].status ){
					printf( "\n-----------------------" );
					printf( "\n\tID: %u" , j + 1 );
					printf( "\n\tNome: %s" , atividades[j].nomeAtv );
					printf( "\n\tStatus: %s" , ( atividades[j].status == 0 ) ? "TODO" : "DONE" );
					printf( "\n-----------------------" );
				}
				++j;
			}
			j = 0;
			while( j < qtd ){ if( atividades[j].status ) jTot += atividades[j].horasGast , ++jY; ++j; }
			printf("\n\tForam feitas %u atividades! (Parabéns!)\n\tQuantidade de horas gastas: %u\n\n", jY , jTot );
			break;
		case 2:
			while( qtd > 0 ){
				printf( "-----------------------" );
				printf( "\n\tID: %u" , qtd );
				printf( "\n\tNome: %s" , atividades[qtd-1].nomeAtv );
				printf( "\n\tStatus: %s" , ( atividades[qtd-1].status == 1 ) ? "TODO" : "DONE" );
				printf( "-----------------------" );
				--qtd;
			}	
			break;
	}
	

}

void limpaVet( unsigned int pos , unsigned int qtd ){
	
	int i = 0;

	for( i = pos ; i < qtd ; ++i){
		printf( "DEBUGGGGGGG\n" );
		if( i != qtd - 1) atividades[i] = atividades[i+1];
	}

	atividades = realloc( atividades , qtd );

}