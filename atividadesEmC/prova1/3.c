# include <stdio.h>
# include <stdlib.h>

int main(void){

    float **matriz , soma = 0 , sumact = 0 , dp = 0 , ds = 0; unsigned int n , i , j , x = 0;

    scanf( "%u" , &n );

    matriz = malloc( n * sizeof( float * ) );
    for( i = 0 ; i < n ; ++i ) matriz[i] = malloc( n * sizeof( float ) );

    for( i = 0 ; i < n ; ++i ) for( j = 0 ; j < n ; ++j ) scanf( " %f" , &matriz[i][j] );

    for( i = 0 ; i < n ; ++i ) soma += matriz[0][i];

    for( i = 0 ; i < n ; ++i ){
        for( j = 0 , sumact = 0 ; j < n ; ++j ) sumact+= matriz[i][j];
        if( soma != sumact ){ x = 1 ; break; }
        for( j = 0 , sumact = 0 ; j < n ; ++j ) sumact+= matriz[j][i];
        dp += matriz[i][i];
        ds += matriz[i][n-1-i];
    }

    if( x == 1 || dp != soma || ds != soma ){
        printf( "Matriz não é um quadrado mágico!\n" );
    }else{
        printf( "Matriz é um quadrado mágico!\n" );
    }

    return 0;
}
