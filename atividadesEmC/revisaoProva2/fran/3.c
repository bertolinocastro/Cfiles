#include <stdio.h>
#include <math.h>

int sf( int n );

int main( int argc, char const *argv[] ){
	unsigned int x;
	scanf( " %u", &x );
	printf( "%d\n", sf( x ) );

	return 0;
}

int sf( int n ){
	static int k = 0;
	if( ++k >= n ) return 1;
	return pow( n-k+1, k ) * sf( n );
}

/*
sf(3)

1 *
1 * 2 *
1 * 2 * 3 


n * (n-1)² * (n-2)³

(n - k)⁽k⁺¹⁾
*/

