#include <stdio.h>
#include <stdlib.h>

int main(void){

    int a , b , c , d , i , j , k ;

    do {

        printf( "Bem vindo ao sistema de criação de matrizes!" );
        printf( "Digite a quantidade de linhas e colunas, respectivamente, (separadas por um único espaço) da 1ª matriz: " );
        scanf( "%d %d" , &a , &b );

        printf( "Digite a quantidade de linhas e colunas, respectivamente, (separadas por um único espaço) da 2ª matriz: " );
        scanf( "%d %d" , &c , &d );

        if ( b != c ){
            printf( "Matriz incompatíveis para a operação PRODUTO!\nRecrie suas matrizes!" );
        }else{
            printf( "HORA DO SHOW!!!!!! BIRL" ); break ; }


    }while( 1 );

    double m[a][b] , n[c][d] , p[a][d];

    for ( i = 0 ; i < a ; ++i ) for ( j = 0 ; j < b ; ++j ) ( printf( "Popule M[%d][%d]: " , i , j ) , scanf( "%lf" , &m[i][j] ) ) ;
    for ( i = 0 ; i < c ; ++i ) for ( j = 0 ; j < d ; ++j ) ( printf( "Popule N[%d][%d]: " , i , j ) , scanf( "%lf" , &n[i][j] ) ) ;

    for ( i = 0 ; i < a ; ++i ) for ( k = 0 ; k < d ; ++k ) for ( j = 0 ; j < b ; ++j ) p[i][k] += m[i][j] * n[j][k] ;

    for ( i = 0 ; i < a ; ++i ) for ( k = 0 ; k < d ; ++k ) k == 3 ? printf( " %lf " , p[i][k] ) : print( " %lf \n" , p[i][k] ) ;

    getchar();

    return 0;
}
