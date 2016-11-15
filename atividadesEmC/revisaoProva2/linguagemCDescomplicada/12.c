#include <stdio.h>

int min( int *vet, int tam );

int main(int argc, char *argv[]){
	int n;
	scanf( "%d", &n );
	int vet[n];
	for(int i = 0; i < n; ++i) scanf( " %d", &vet[i] );
	printf( "%d\n", min(vet,n) );
	return 0;
}

int min( int *vet, int tam ){
	int aux1,aux2;
	aux1 = *vet;
	if( tam == 1 ) return aux1;
	aux2 = min( vet+1, tam-1 );
	if( aux2 < aux1 ) return aux2;
	return aux1;
}

