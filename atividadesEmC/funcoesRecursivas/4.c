#include <stdio.h>
#include <math.h>

long double potencia( long double k , long double n );
long double radiciacao( long double k , long double n );
long double procuraProximo( long double k , long double n );

int main(void){

	long double k , n;

	scanf( "%Lg %Lg" , &k , &n );

	printf( "%Lg elevado a %Lg resulta em: %Lg\n" , k , n , potencia( k , n ) );

	return 0;
}

long double potencia( long double k , long double n ){

	long double num; unsigned int indice = 0;

	if( floor(n) == n ){ /* Verifica se é inteiro */

		if( n == 0 ) return 1;

		if( n < 0 ) return (1/k) * potencia( k , n + 1 );

		return k * potencia( k , n - 1 );

	}else{ /* Caso não seja inteiro */

		while( floor( n ) != n ) n*=10 , ++indice , printf( "DEBUG: line 33 n: %Lg indice: %u\n" , n , indice );

		if( n < 0 ) num = (1/k) * potencia( k , n + 1 );
		else num = k * potencia( k , n - 1 );

		printf( "DEBUG: line 38 %Lg\n" , num );

		return radiciacao( num , potencia( 10 , indice ) );

	}

}

long double radiciacao( long double k , long double n ){

	long double iteracao , kAct , raiz;
	iteracao = 0;

	kAct = k;
	while( iteracao <= 15 ){

		raiz = procuraProximo( kAct , n );

		printf( "DEBUG: line 56 K: %Lg n: %Lg iteracao: %Lg kAct: %Lg raiz: %Lg\n" , k , n , iteracao , kAct , raiz );

		if( k == raiz )	return kAct;
		else if( k > raiz ) kAct *= potencia( 10 , n );
		++iteracao;

	}

	return raiz / potencia( 10 , iteracao ) ;

}

long double procuraProximo( long double k , long double n ){

	long double i;
	i = 0;

	while( potencia( i , n ) <= k ) printf( "DEBUG: line 73 K: %Lg n: %Lg i: %Lg\n" , k , n , i ) , ++i;
	--i;

	return i;
}
