#include <stdio.h>
#include <math.h>

double potencia( double k , double n );
double fatorador( double k , double n );

int main(void){

	double k , n;

	scanf( "%lf %lf" , &k , &n );

	printf( "%g elevado a %g resulta em: %g\n" , k , n , potencia( k , n ) );

	return 0;
}

double potencia( double k , double n ){

	double num; unsigned int indice = 0;

	if( floor(n) == n ){ /* Verifica se é inteiro */

		if( n == 0 ) return 1;

		if( n < 0 ) return (1/k) * potencia( k , n + 1 );

		return k * potencia( k , n - 1 );

	}else{ /* Caso não seja inteiro */

		while( floor( n ) != n ) n*=10 , ++indice;

		if( n < 0 ) num = (1/k) * potencia( k , floor( n ) + 1 );
		else num = k * potencia( k , floor( n ) - 1 );

		return fatorador( num , potencia( 10 , indice ) );

	}


}

double fatorador( double k , double n ){

	if( k / (10*n) > 0 ) {

	}else{
		
	}

}

