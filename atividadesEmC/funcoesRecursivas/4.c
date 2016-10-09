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

unsigned int einteiro( long double __x , int linha ){
	long double resto; long long int inteiro;

	inteiro = (long long int) __x / 1;
	resto = __x - inteiro;

	printf( "DEBUG linha %d: int %lli resto %Lg __x %Lg\n" , linha , inteiro , resto , __x );

	if( resto == ((unsigned) 0.0L) ) return 1;
	return 0;
}

long double elevacao( long double k , long double n );
long double potencia( long double k , long long int n );
long double radiciacao( long double k , long long int n );
long double procuraProximo( long double k , long long int n );
long double limpaDecimal( long double m , long double mTeste , unsigned int *virgula );

int main(void){

	long double k , n;

	scanf( "%LF %LF" , &k , &n );
/*
	unsigned int l = 0;

	printf( "%Lg , %u\n" , limpaDecimal( 35 , 35 , &l ) , l );
	printf( "%u\n" , l );
*/
	printf( "%Lg elevado a %Lg resulta em: %+Lg\n" , k , n , elevacao( k , n ) );

	return 0;
}

long double limpaDecimal( long double m , long double mTeste , unsigned int *virgula ){

	printf( "limpou %Lg %Lg %u\n" , m , mTeste , *virgula );

	if( einteiro( m , __LINE__ ) == 0 && eLB( mTeste ) == 1 ) { if( m != mTeste ) *virgula += 1 ; return limpaDecimal( mTeste , mTeste * e( 1.0L )  , virgula ); }
	if( eLB( m ) == 0 ) fprintf(stderr, "O número excedeu os limites do bom senso.\nAcho melhor ser justo.\n" ) , exit(1);
	return m;
}

long double elevacao( long double k , long double n ){

	printf( "----ELEVACAO-----\n" );

	long double /* num , */base /*, nTeste*/; unsigned int indice = 0;

	if( einteiro( n , __LINE__ ) == 1 ) return potencia( k , n );
	
	//nTeste = n;
/*
	while( 	einteiro( n , __LINE__ ) == 0 &&
			eLB( nTeste ) == 1
	 	) n = nTeste , nTeste*= e( 1.0L )  , ++indice , printf( "indice %u\n" , indice );
	//--indice;
*/

	n = limpaDecimal( n , n , &indice );

	printf( "ele ind %u\n" , indice );
/*
	if( einteiro( n , __LINE__ ) == 0 ) fprintf(stderr, "O número excedeu os limites do bom senso.\nAcho melhor ser justo.\n" ) , exit(1);

	num = potencia( k , n );

	printf( "olha o debug aí!: %Lg\n\n" , num );
*/
	//if( eLB( num ) == 0 ) fprintf(stderr, "O número excedeu os limites do bom senso.\nAcho melhor ser justo.\n" ) /*, exit(1)*/;

	//return radiciacao( num , e( indice ) );

	base = radiciacao( k , e( indice ) );

	return potencia( base , n );

}

long double potencia( long double k , long long int n ){

	if( n == 0 ) return 1;

	if( n < 0 ) return (1/k) * potencia( k , n + 1 );

	return k * potencia( k , n - 1 );

}

long double radiciacao( long double k , long long int n ){

	printf( "\n\n------- Radiciacao ---------\n\n" );

	long double/* potenciada ,*/ raiz/* , potenciadaTeste*/ , denum; unsigned int iteracao = 0; unsigned short int kNegativo = 0;

	//iteracao = 0;

	/*potenciadaTeste = potenciada = k;*/
/*
	while( einteiro( potenciada , __LINE__ ) == 0 && eLB( potenciadaTeste ) == 1 ) potenciada = potenciadaTeste, potenciadaTeste = k * e( iteracao ), ++iteracao , 
		printf( "DEBUG: rad while %Lg , %Lg , %u\n" , potenciada , potenciadaTeste , iteracao );
	//--iteracao;
*/

	k = limpaDecimal( k , k , &iteracao );

	printf( "rad int %d\n", iteracao );sleep( 1 );

	//printf( "SAI do loop pq: %u , %u\n" , einteiro( potenciada , __LINE__ ) , eLB( potenciadaTeste ) );

	//raiz = procuraProximo( potenciada , n );

	if( k >= 0 ) raiz = procuraProximo( k , n );
	else raiz = procuraProximo( -k , n ) , kNegativo = 1;

	printf( "\nNotação científica: %Lg\n\n" , e( iteracao ) );

	denum = procuraProximo( e( iteracao ) , n );
	printf( "\nRaiz do denominador (notacao cientifica) %Lg\n" , denum );
	raiz /= denum;
	printf( "\nResultado: r/denum%s%Lg\n" , ( kNegativo == 1 ) ? " i" : " " , raiz );

	return ( kNegativo == 1 ) ? -raiz : raiz;

}

long double procuraProximo( long double k , long long int n ){

	printf( "\n\n---Procura próximo----\n\n" );

	long double i , iTeste , val; unsigned short int achou = 0; unsigned int passo = 0; long double pot = 0;
	iTeste = i = 0; val = 1;

	while( achou != 1 ){

		if( eLB( ( pot = potencia( i , n ) ) ) == 1 && passo < PRECISAO ) {
			
			if( i - val > 0 ) iTeste = i - val;
			printf( "DEBUG: val %Lg iTeste inLoop %Lg i %Lg\n" , val , iTeste , i );
			if( pot > k ){
				if( iTeste >= 0 ) i-= val , ++passo , val = 1/e( passo ) , printf( "DEBUG: iT>0 -> i: %.17LF passo: %u\n" , i , passo );
				else i-=val , achou = 1;
			}else{
				iTeste = i + val;
				if( iTeste >= 0 ) i = iTeste;
				else achou = 1 , printf( "DEBUG: iTeste é negativo!\n" );
			}
		}else{
			achou = 1;
			printf( "DEBUG: NÃO É LB!\n" );
		}
		printf( "DEBUG: line 73 K: %Lg n: %lli i: %.17LF i^n: %Lg passo: %u achou: %hu\n" , k , n , i , pot , passo , achou );
	}
	printf( "\nRaiz sem notação científica: %.17LF\n\n" , i );

	return i;
}
