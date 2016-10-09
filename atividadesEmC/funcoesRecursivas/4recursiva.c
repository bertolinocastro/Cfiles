#include <stdio.h>
#include <stdlib.h>

#define PRECISAO 18

#define INFP (1.0/0)
#define INFN (-1.0/0)

#define MAXLB 18446744073709551616.0L
#define MINLB -18446744073709551616.0L

#define NaN ( 0.0L / 0.0L )

#define passouLB( __y ) ( ( __y >= MAXLB || __y <= MINLB ) ? 1 : 0 )
#define einfinito( __x ) ( ( __x == INFP || __x == INFN ) ? 1 : 0 )
#define enan( __w ) ( ( __w == NaN ) ? 1 : 0 )

#define eLB( __v ) ( ( passouLB( __v ) == 0 && einfinito( __v ) == 0 && enan( __v ) == 0 ) ? 1 : 0 )

#define e( __n ) ( potencia( 1.0e1L , __n ) )

unsigned int einteiro( long double __x ){
	long double resto; long long int inteiro;

	inteiro = (long long int) __x / 1;
	resto = __x - inteiro;

	if( resto == ((unsigned) 0.0L) ) return 1;
	return 0;
}

long double elevacao( long double k , long double n );
long double potencia( long double k , long long int n );
long double radiciacao( long double k , long long int n );
long double procuraProximo( long double k , long double n );

int main(void){

	long double k , n;

	scanf( "%LF %LF" , &k , &n );

	printf( "%Lg elevado a %Lg resulta em: %Lg\n" , k , n , elevacao( k , n ) );

	return 0;
}

long double elevacao( long double k , long double n ){

	long double num , nTeste; unsigned int indice = -1;

	if( einteiro( n ) == 1 ) return potencia( k , n );
	
	nTeste = n;

	while( 	einteiro( n ) == 0 &&
			eLB( nTeste ) == 1
	 	) n = nTeste , nTeste*= e( 1.0L )  , ++indice;

	if( einteiro( n ) == 0 ) fprintf(stderr, "O número excedeu os limites do bom senso.\nAcho melhor ser justo.\n" ) , exit(1);

	num = potencia( k , n );

	return radiciacao( num , e( indice ) );

}

long double potencia( long double k , long long int n ){

	if( n == 0 ) return 1;

	if( n < 0 ) return (1/k) * potencia( k , n + 1 );

	return k * potencia( k , n - 1 );

}

long double radiciacao( long double k , long long int n ){

	long double potenciada , potenciadaTeste;
	long long int iteracao , raiz;
	iteracao = 0;

	potenciadaTeste = potenciada = k;

	while( 	einteiro( potenciada ) == 0 && eLB( potenciadaTeste ) == 1 ) potenciada = potenciadaTeste, potenciadaTeste *= e( n ), ++iteracao;

	raiz = procuraProximo( potenciada , n );

	printf( "\nNotação científica: %Lg\n\n" , e( iteracao ) );

	return raiz / e( iteracao );

}

long double procuraProximo( long double k , long double n ){

	long double i , iTeste , val; unsigned short int achou = 0; unsigned long long int passo = 0; long double pot = 0;
	iTeste = i = 0; val = 1;

	while( achou != 1 ){

		if( eLB( ( pot = potencia( i , n ) ) ) == 1 && passo < PRECISAO ) {
			
			if( i - val > 0 ) iTeste = i - val;
			//printf( "DEBUG: val %Lg iTeste inLoop %Lg\n" , val , iTeste );
			if( pot > k ){
				if( iTeste >= 0 ) i-= val , ++passo , val/= e( 1 ) /*, printf( "DEBUG: iT>0 -> i: %.17LF passo: %lli\n" , i , passo )*/;
				else achou = 1;
			}else{
				iTeste = i + val;
				if( iTeste >= 0 ) i = iTeste;
				else achou = 1 /*, printf( "DEBUG: iTeste é negativo!\n" )*/;
			}
		}else{
			achou = 1;
			//printf( "DEBUG: NÃO É INTEIRO!\n" );
		}
		//printf( "DEBUG: line 73 K: %Lg n: %Lg i: %.17LF i^n: %Lg passo: %lli achou: %hu\n" , k , n , i , pot , passo , achou );
	}
	printf( "\nRaiz sem notação científica: %.17LF\n\n" , i );

	return i;
}
