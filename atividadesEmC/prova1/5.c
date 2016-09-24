# include <stdio.h>

float fat( float n ){
    if( n <= 1 ){
        return 1;
    }else{
        return n * fat( n - 1 );
    }
}

int main(void){

    float x;

    scanf( "%f" , &x );

    printf( "%f\n" , fat( x ) );

    return 0;
}

