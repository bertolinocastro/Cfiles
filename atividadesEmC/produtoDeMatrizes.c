#include <stdio.h>
#include <stdlib.h>
/*#include <alloca.h>*/

int main(void){

    int a , b , c , d , i , j , k ;
    double **m;
    double **n;
    double **p;

    do {

        printf( "Bem vindo ao sistema de criação de matrizes!\n" );
        printf( "Digite a quantidade de linhas e colunas, respectivamente, (separadas por um único espaço) da 1ª matriz: " );
        scanf( "%d %d" , &a , &b );

        printf( "Digite a quantidade de linhas e colunas, respectivamente, (separadas por um único espaço) da 2ª matriz: " );
        scanf( "%d %d" , &c , &d );

        if ( b != c ){
            printf( "\bMatriz incompatíveis para a operação PRODUTO!\nRecrie suas matrizes!\n" );
        }else{
            printf( "\nHORA DO SHOW!!!!!! BIRL\n" ); break ; }


    }while( 1 );

    /*double **m;*/
    m = malloc( a * sizeof  ( double *) ) ;
    for ( i = 0 ; i < a ; ++i ) m[i] = malloc( b * sizeof ( double ) );

    /*double **n;*/
    n = malloc( c * sizeof  ( double *) ) ;
    for ( i = 0 ; i < c ; ++i ) n[i] = malloc( d * sizeof ( double ) );

    /*double **p;*/
    p = malloc( a * sizeof  ( double *) ) ;
    for ( i = 0 ; i < a ; ++i ) p[i] = malloc( d * sizeof ( double ) );

    /*double m[a][b] , n[c][d] , p[a][d];*/

    /*Populando as matrizes dinâmicas*/
    for ( i = 0 ; i < a ; ++i ) for ( j = 0 ; j < b ; ++j ) ( printf( "\nPopule M[%d][%d]: " , i , j ) , scanf( "%lf" , &m[i][j] ) ) ;
    for ( i = 0 ; i < c ; ++i ) for ( j = 0 ; j < d ; ++j ) ( printf( "\nPopule N[%d][%d]: " , i , j ) , scanf( "%lf" , &n[i][j] ) ) ;

    /*Desenhano as atrizes dinâmicas*/
    printf( "\nMatriz M: \n" );
    for ( i = 0 ; i < a ; ++i ) for ( j = 0 ; j < b ; ++j ) j != b - 1 ? printf( " %7.2f " , m[i][j] ) : printf( " %7.2f \n" , m[i][j] ) ;

    printf( "\nMatriz N: \n" );
    for ( i = 0 ; i < c ; ++i ) for ( j = 0 ; j < d ; ++j ) j != d - 1 ? printf( " %7.2f " , n[i][j] ) : printf( " %7.2f \n" , n[i][j] ) ;

    /*Criando a matriz produto M*N*/
    for ( i = 0 ; i < a ; ++i ) for ( k = 0 ; k < d ; ++k ) for ( j = 0 ; j < b ; ++j ) p[i][k] += m[i][j] * n[j][k] ;

    /*Desenhando a matriz produto M*N*/
    printf( "\nMatriz PRODUTO: \n" );
    for ( i = 0 ; i < a ; ++i ) for ( k = 0 ; k < d ; ++k ) k != d - 1 ? printf( " %7.2f " , p[i][k] ) : printf( " %7.2f \n" , p[i][k] ) ;

    getchar();

    return 0;
}
