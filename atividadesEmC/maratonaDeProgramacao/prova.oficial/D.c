# include <stdio.h>

int main( int argc, char ** argv ){

    unsigned int a,b,c,d,i,k=0;

    scanf( "%u %u %u %u" , &a , &b , &c , &d );

    for( i = a ; i < c ; ++i ){
        if( i % a == 0 && i % b != 00 && c % i == 0 && d % i != 0  ) break;
        ++k;
    }
    ( k == i ) ? printf( "-1\n" ) : printf( "%u\n" , i );

    return 0;
}
