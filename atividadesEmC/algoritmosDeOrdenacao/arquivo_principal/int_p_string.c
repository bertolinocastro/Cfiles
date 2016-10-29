#include <stdlib.h>
#include <stdio.h>
#include "int_p_string.h"

int int_p_string( int num , char **ptr ){
	int i , count = 0;
	if( *ptr ) free( *ptr ) , *ptr = NULL;
	do{
		*ptr = (char *) realloc( *ptr , (count + 1) * sizeof( char ) );
		if( !(*ptr) ) printf("Erro com ponteiro. Arquivo: Int_P_String.\n"), exit(1);
		i = num % 10;
		*(*ptr+count) = i + '0';
		num /= 10;
		++count;
	}while( num );
	return count;
}