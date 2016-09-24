# include <stdio.h>
# include <string.h>

int main(void){

    char palavra[1024]; unsigned int x = 0 , n , i;

    scanf( "%s" , palavra );

    n = strlen( palavra );

    for( i = 0 ; i < n ; ++i ) if( palavra[i] != palavra[n-1-i] ) { x = 1; break; };

    ( x == 1 ) ? printf( "Não-palíndroma\n" ) : printf( "Palíndroma\n" );

    return 0;
}
