#include <stdio.h>
#define einteiro( __x ) (  ( ( (long long int) __x ) == ( (long double)  __x ) ) ? 1 : 0 )
//#define einteiro( __x ) (  ( __x % 1.0L == 0 ) ? 1 : 0 )
//#define einteiro( __x ) ( ( (long double)__x - (long long int)__x == 0 ) ? 1 : 0 )

#define INFP (1.0/0)
#define INFN (-1.0/0)

#define MAXLB 18446744073709551616.0L
#define MINLB -18446744073709551616.0L

#define passouLB( __y ) ( ( __y >= MAXLB || __y <= MINLB ) ? 1 : 0 )
#define einfinito( __x ) ( ( __x == INFP || __x == INFN ) ? 1 : 0 )

/* MUDAR ISSO AO ACORDAR <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */
#define printatudo( __z ) ( printf( "Mantissa: %a Expoent: %a Signal: %a\n" , __z.parte.Mantissa , __z.parte.Expoent , __z.parte.Signal ) )
/* MUDAR ISSO AO ACORDAR <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */

typedef union{
	long double f;
	struct {
		unsigned long long int Mantissa : 63;
		unsigned int Expoent : 15 ;
		unsigned int Signal : 1;
	} parte ;
} numerobolado;

long double elevacao( long double k , long double n );
long double potencia( long double k , long long int n );
long double radiciacao( long double k , long long int n );
long long int procuraProximo( long double k , long long int n );

int main(void){

	long double k , n;

	scanf( "%LF %LF" , &k , &n );

	printf( "DEBUG: kint %lli kdb %.30LF\n" , (long long int) k , (long double) k );
	printf( "DEBUG: nint %lli ndb %.30LF\n" , (long long int) n , (long double) n );

	printf( "DEBUG funcao: k: %u e n: %u\n" , einteiro( k ) , einteiro( n ) );
/*
	//printf( "DEBUG k: %d n: %d\n" , kint , nint );
	//printf( "Var k: %LF, parte inteira: %LF, resto: %LF\nVar n: %LF, parte inteira: %LF, resto: %LF\n" , k , (int) k , k - (int) k , n , (int) n , n - (int) n );
	printf( "DEBUG +infinito %lg e -infinito %lg\n" , 1.0/0 , -1.0/0 );
	printf( "DEBUG: einfinito k %u n %u\n" , einfinito( k ) , einfinito( n ) );
	printf( "DEBUG: testando 1.0/0 %u -1.0/0 %u\n" , einfinito( 1.0/0 ) , einfinito( -1.0/0 ) );

	printf( "TAMANHO int %u\n" , sizeof( int ) );
	printf( "TAMANHO float %u\n" , sizeof( float ) );
	printf( "TAMANHO double %u\n" , sizeof( double ) );
	printf( "TAMANHO long double %u\n" , sizeof( long double ) );
*/
/*
	n = 18446744073709551616.0L;
	
	printf( "Mantissa long double: %50LF\n" , n );

	n--;
	printf( "Mantissa long double: %50LF\n" , n );
*/
	numerobolado j;
	j.f = k;
	printatudo( j );
	//printf( "%Lg elevado a %Lg resulta em: %Lg\n" , k , n , elevacao( k , n ) );

	return 0;
}

long double elevacao( long double k , long double n ){

	long double num , nTeste; unsigned int indice = 0;

	if( einteiro( n ) == 1 ) return potencia( k , n );
	
	nTeste = n;

	printf( "DEBUG: eInt n: %u eInf nTes: %u passLB nTes: %u\n" , einteiro( n ) , einfinito( nTeste ) , passouLB( nTeste ) );
	sleep( 4 );
	while( 	einteiro( n ) == 0 &&
			einfinito( nTeste ) == 0 &&
			passouLB( nTeste ) == 0
	 	) n = nTeste , nTeste*=10 , ++indice , printf( "DEBUG: line 33 n: %Lg nTeste: %Lg indice: %u\n" , n , nTeste , indice );

	num = potencia( k , n );

	printf( "DEBUG: line 35 %Lg\n" , num );

	return radiciacao( num , potencia( 10 , indice ) );

}

long double potencia( long double k , long long int n ){

/*
	if( floor(n) == n ){  Verifica se é inteiro
*/
		if( n == 0 ) return 1;

		if( n < 0 ) return (1/k) * potencia( k , n + 1 );

		return k * potencia( k , n - 1 );
/*
	}else{ Caso não seja inteiro 

		while( floor( n ) != n ) n*=10 , ++indice , printf( "DEBUG: line 33 n: %LF indice: %u\n" , n , indice );

		if( n < 0 ) num = (1/k) * potencia( k , n + 1 );
		else num = k * potencia( k , n - 1 );

		printf( "DEBUG: line 38 %LF\n" , num );

		return radiciacao( num , potencia( 10 , indice ) );

	}
*/
}

long double radiciacao( long double k , long long int n ){

	long double potenciada , potenciadaTeste , kAct;
	long long int iteracao /*, kAct */, raiz;
	iteracao = 0;

	printf( "DEBUG: ENTREI NA RADICIACAO\n" );
	printf( "DEBUG: rad k: %Lg\n" , k );
	printf( "DEBUG: rad teste while: %u\n" , einteiro( k * potencia( 10 , iteracao ) ) );


	potenciadaTeste = potenciada = k;
	//printf( "DEBUG: rad bitwise or %u\n" , (einteiro( potenciada ) | einfinito( potenciadaTeste = k * potencia( 10 , iteracao ) )) );
	printf( "DEBUG: é infinito pot %u potTest %u\n" , einfinito( potenciada ) , einfinito( potenciadaTeste ) );

	sleep( 3 );

	while( 	einteiro( potenciada ) == 0  &&
			einfinito( potenciadaTeste ) == 0 &&
			passouLB( potenciadaTeste ) == 0
			/* && iteracao <= 30*/ )

		printf( "DEBUG: rad while iteracao: %lli k*10^itera: %Lg\n" , iteracao , potenciada ) ,
	 	printf( "DEBUG: rad while cast kint: %lli kdb: %Lg\n" , ((long long int) potenciada) , ((long double) potenciada) ) ,
		potenciada = potenciadaTeste,
		potenciadaTeste = k * potencia( 10 , ++iteracao );

	kAct = k * potencia( 10 , --iteracao );

	
	//while( iteracao <= 15 ){

		raiz = procuraProximo( kAct , n );

		printf( "DEBUG: line 56 K: %Lg n: %lli iteracao: %lli kAct: %Lg raiz: %lli\n" , k , n , iteracao , kAct , raiz );

		//if( k == raiz )	return kAct;
		//else if( k > raiz ) kAct *= potencia( 10 , n );
		//++iteracao;

	//}

	return raiz / potencia( 10 , iteracao );

}

long long int procuraProximo( long double k , long long int n ){

	static long double i = 0;

	while( potencia( i , n ) <= k ) printf( "DEBUG: line 73 K: %Lg n: %lli i: %Lg\n" , k , n , i ) , ++i;
	--i;

	return i;
}
