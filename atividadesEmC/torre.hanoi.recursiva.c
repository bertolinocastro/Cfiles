#include <stdio.h>

int main(void){

    int cont = 0;

    void movetorre (int N,char orig, char dest, char aux){
         if(N==1)
                 cont=cont+1;
         else{
               movetorre(N-1,orig,aux,dest);
               cont=cont+1;
               movetorre(N-1,orig,aux,dest);
             }
    };

    unsigned int x;

    scanf( "%u" , &x );

    movetorre( x , 'A' , 'B' , 'C' );

    printf( "Movimentos: %d" , cont );

    return 0;
}

