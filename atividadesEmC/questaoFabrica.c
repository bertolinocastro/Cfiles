#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale( LC_ALL , "Portuguese" );

    float Lpi, E, espacamentoV, espacamentoH;
    int i, N;

   /* printf( "--------------------------------------------------------------------------------\n" );
    printf( "* * * * * * * * * * * * * * * * * * ATENÇÃO * * * * * * * * * * * * * * * * * *\n" );
    printf( "   TODOS OS DADOS INFORMADOS PELO USUÁRIO DEVEM SER DIGITADOS EM MILÍMETROS!   \n" );
    printf( "--------------------------------------------------------------------------------\n" );*/

    do {
       // printf( "\nDigite o espaçamento entre os 'pilares' do jogo: " );
        scanf( "%f" , &Lpi );
    } while ( Lpi <= 0 );

    do {
       // printf( "\nDigite a quantidade de aletas que o jogo possui: " );
        scanf( "%d" , &N );
    } while ( N <= 0 );

    do {
        //printf( "\nDigite a espessura média de todas as aletas: " );
        scanf( "%f" , &E );
    } while ( E <= 0 );

    float Y[N], La[N];

    for ( i = 0 ; i < N ; i++ ) {

        /*printf( "\nDigite a coordenada em Y da %dª aleta: " , i + 1 );*/
        scanf( "%f" , &Y[i] );

        while( Y[i] <= 0 ){
            /*printf( "\nCoordenada em Y não-positiva não é aceita!" );
            printf( "\nDigite novamente a coordenada em Y da %dª aleta: " , i + 1 );*/
            scanf( "%f" , &Y[i] );
        }

        while ( i > 0 && Y[i] <= Y[i-1] + E ) {
            /*printf( "\nAs aletas estão a se encostar!" );
            printf( "\nCoordenada em Y atual menor ou igual à da aleta anterior." );
            printf( "\nDigite novamente a coordenada em Y da %dª aleta: " , i + 1 );*/
            scanf( "%f" , &Y[i] );
        }

        /*printf( "\nDigite o comprimento da %dª aleta: " , i + 1 );*/
        scanf( "%f" , &La[i] );

        while ( La[i] <= 0 ) {
            /*printf( "O comprimento deve ser positivo!" );
            printf( "Digite novamente o comprimento da %dª aleta: " , i + 1 );*/
            scanf( "%f" , &La[i] );
        }

        while ( La[i] >= Lpi ) {
            /*printf( "\nComprimento da aleta é superior à largura permitida para prateleira!" );
            printf( "\nDigite novamente o comprimento da %dª aleta: " , i + 1 );*/
            scanf( "%f" , &La[i] );
        }
    }

    espacamentoV = Y[1] - ( Y[0] + E );
    espacamentoH = Lpi - La[0];

    for ( i = 1 ; i < N - 1 ; i++ ) {
        if ( espacamentoV > Y[i+1] - ( Y[i] + E ) )
            espacamentoV = Y[i+1] - ( Y[i] + E );
    }
    for ( i = 1 ; i < N ; i++ ) {
        if ( espacamentoH > Lpi - La[i] )
            espacamentoH = Lpi - La[i];
    }


    ( espacamentoH >= espacamentoV ) ?
        printf( "Tamanho da bola deve ser: %.2fmm" , espacamentoV ) :
        printf( "Tamanho da bola deve ser: %.2fmm" , espacamentoH ) ;

    return 0;
}
