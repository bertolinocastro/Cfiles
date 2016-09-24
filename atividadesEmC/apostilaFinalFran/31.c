#include <stdio.h>

int main(void){

    unsigned int Ndiscos , i;

    scanf( "%u" , &Ndiscos );

    void hanoi( unsigned int n , char Ori , char Dest , char Aux ){
        if( n == 1 ){
            printf( "Movendo disco %u do pilar %c para o %c\n" , n , Ori , Dest);
        }else{
            hanoi( n - 1 , Ori , Aux , Dest );
            printf( "Movendo disco %u do pilar %c para o %c\n" , n , Dest , Aux );
            hanoi( n - 1 , Ori , Dest , Aux );
        }
    }
    hanoi( Ndiscos , '1' , '2' , '3' );

    return 0;
}
