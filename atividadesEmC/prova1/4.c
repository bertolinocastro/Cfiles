# include <stdio.h>

int main(void){

    float vet[10]; unsigned int i , j , x = 0;

    for( i = 0 ; i < 10 ; ++i ) scanf( " %f" , &vet[i] );

    for( i = 0 ; i < 9 ; ++i ) for( j = i + 1 ; j < 10 ; ++j ) if( vet[i] == vet[j] ) { x = 1; break; };

    ( x == 1 ) ? printf( "Existe repetição" ) : printf( "Não existe repetição" );

    return 0;
}

