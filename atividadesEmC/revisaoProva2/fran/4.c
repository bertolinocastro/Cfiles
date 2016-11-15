#include <stdio.h>

int catalan( int n );

int main( int argc, char const *argv[] ){

	return 0;
}

int catalan( int n ){

	if( !n ) return 1;
	return (2*(2*n - 1)/(n + 1))
}