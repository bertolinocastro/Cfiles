#include <stdio.h>
#include <stdlib.h>

#define mod( __u ) ( ( __u >= 0.0L ) ? __u : -__u )

#define PRECISAO 18

#define INFP (1.0/0)
#define INFN (-1.0/0)
/*
#define MAXLB 18446744073709551616.0L
#define MINLB -18446744073709551616.0L
*/
#define NaN ( 0.0L / 0.0L )

// A limitação de tamanho está impedindo que valores, que ainda são double, permanecam
//#define passouLB( __y ) ( ( __y >= MAXLB || __y <= MINLB ) ? 1 : 0 )
#define einfinito( __x ) ( ( __x == INFP || __x == INFN ) ? 1 : 0 )
#define enan( __w ) ( ( __w == NaN ) ? 1 : 0 )

#define eLB( __v ) ( (/* passouLB( __v ) == 0 &&*/ einfinito( __v ) == 0 && enan( __v ) == 0 ) ? 1 : 0 )

#define e( __n ) ( potencia( 1.0e1L , __n ) )

#define RESTO_PRECISO ( e( -PRECISAO ) )

long double elevacao( long double k , long double n );
long double potencia( long double k , long long int n );
long double radiciacao( long double k , long long int n );
long double procuraProximo( long double k , long long int n );
//long double procuraProximoCallBack( long double k , long double n/* , long double i , long double val*/ );
long double limpaDecimal( long double m , long double mTeste , unsigned int *virgula );

unsigned int einteiro( long double __x , int linha ){
	long double resto; long long int inteiro;

	inteiro = (long long int) __x / 1;
	resto = __x - inteiro;

	printf( "DEBUG linha %d: int %lli resto %Lg __x %Lg\n" , linha , inteiro , resto , __x );

	if( mod( resto ) <= mod( RESTO_PRECISO ) ) return 1;
	return 0;
}


int main(void){

	long double k , n;

	scanf( "%LF %LF" , &k , &n );

	printf( "%Lg elevado a %Lg resulta em: %+Lg\n" , k , n , elevacao( k , n ) );

	return 0;
}

long double limpaDecimal( long double m , long double mTeste , unsigned int *virgula ){

	static unsigned int passadas = 0;
	printf( "limpou %Lg %Lg %u\n" , m , mTeste , *virgula );

	if( einteiro( m , __LINE__ ) == 0 && eLB( mTeste ) == 1 && passadas < PRECISAO ) { if( m != mTeste ) *virgula += 1; ++passadas; return limpaDecimal( mTeste , mTeste * e( 1.0L )  , virgula ); }
	if( eLB( m ) == 0 ) fprintf(stderr, "O número excedeu os limites do bom senso.\nAcho melhor ser justo.\n" ) , exit(1);
	passadas = 0;
	return m;
}

long double elevacao( long double k , long double n ){

	printf( "----ELEVACAO-----\n" );

	long double base; unsigned int indice = 0;

	if( einteiro( n , __LINE__ ) == 1 ) return potencia( k , n );

	n = limpaDecimal( n , n , &indice );

	printf( "ele ind %u\n" , indice );

	if( indice >= 5 ) { printf( "Expoente com casas decimais acima do suportado.\nTenha bom senso\n" ); exit( 1 ); }

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

	long double raiz , denum; unsigned int iteracao = 0; unsigned short int kNegativo = 0;

	k = limpaDecimal( k , k , &iteracao );

	printf( "rad int %d\n", iteracao );//sleep( 1 );
	//sleep( 4 );

	if( k >= 0 ) raiz = procuraProximo( k , n );
	else raiz = procuraProximo( -k , n ) , kNegativo = 1;

	printf( "\nNotação científica: %Lg\n\n" , e( iteracao ) );
//	exit(1);
	denum = procuraProximo( e( iteracao ) , n );
	printf( "\nRaiz do denominador (notacao cientifica) %Lg\n" , denum );
	raiz /= denum;
	printf( "\nResultado: r/denum%s%Lg\n" , ( kNegativo == 1 ) ? " i" : " " , raiz );

	return ( kNegativo == 1 ) ? -raiz : raiz;

}
/*
long double procuraProximo( long double k , long long int n ){*/
/*
	printf( "\n\n---Procura próximo----\n\n" );

	long double i , iTeste , val; unsigned short int achou = 0; unsigned int passo = 0; long double pot = 0;
	iTeste = i = 0; val = 1;

	printf( "teste: k %Lg n %lli\n", k , n );*/
/*
	while( achou != 1 ){

		if( eLB( ( pot = potencia( i , n ) ) ) == 1 && passo < PRECISAO ) {
			
			//if( i - val > 0 ) iTeste = i - val , printf( "presta pra nada\n" );
			printf( "DEBUG: val %Lg iTeste inLoop %Lg i %Lg\n" , val , iTeste , i );
			if( pot > k ){
				if( iTeste >= 0 ) i-= val , ++passo , val = 1/e( passo ) , printf( "DEBUG: iT>0 -> i: %.17LF passo: %u\n" , i , passo );
				else i-=val , achou = 1 , printf( "debug: pot>k else\n" );
			}else{
				iTeste = i + val;
				if( iTeste >= 0 ) i = iTeste;
				else achou = 1 , printf( "DEBUG: iTeste é negativo!\n" );
			}
		}else{
			printf( "DEBUG: pot não é LB: %Lg\n" , pot );
			achou = 1;
			printf( "DEBUG: NÃO É LB!\n" );
		}
		printf( "DEBUG: line 73 K: %Lg n: %lli i: %.17LF i^n: %Lg passo: %u achou: %hu\n" , k , n , i , pot , passo , achou );
	}
	printf( "\nRaiz sem notação científica: %.17LF\n\n" , i );
*/
/*	return procuraProximoCallBack( k , n *//*, 0 , 1*/ /*);
}
*/
long double procuraProximo( long double k , long long int n /* , long double i , long double val/*/ ){
	static unsigned int passo = 0; static long double val = 1 , i = 0;
	long double pot = potencia( i , n );
	printf( "\n\n\nchamada da funcao: k %Lg n %lli i %Lg val %Lg passo %u\n" , k , n , i , val , passo );
	printf( "potencia %Lg\n" , pot );
	if( eLB( pot ) == 1 && passo < PRECISAO ){
		if( pot >= k ){ i-=val; val= 1/e( ++passo );
			printf( "pot>k" );
			printf( "\ti-=val %Lg val = 1/e( passo + 1 ) %Lg ++passo %u\n" , i , val , passo );
			//sleep( 0.5L );
			return procuraProximo/*CallBack*/( k , n /*, i-=val , val = 1/e( passo )*/ );
		}else{ i+= val;
			printf( "pot<=k" );
			printf( "\ti + val %Lg val = %Lg passo %u\n" , i , val , passo );
			//sleep( 0.5L );
			return procuraProximo/*CallBack*/( k , n /*, i + val , val */);
		}
	}else{ long double resp = i; passo = i = 0; val = 1; printf( "VALOR DE I: %Lg\n" , resp ); return resp;}

}
