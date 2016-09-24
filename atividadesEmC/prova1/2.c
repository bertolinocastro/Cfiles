# include <stdio.h>

int main(void){

    int x , sum = 0; unsigned int c = 0;

    do{
        scanf( "%d" , &x );
        if( x % 2 == 0 ) sum += x;
        ++c;
    }while( x != 0 && c < 10 );

    printf( "%d\n" , sum );

    return 0;
}
