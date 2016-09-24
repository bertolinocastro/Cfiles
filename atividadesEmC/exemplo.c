# include "string.variavel.h"

int main(void){

    char *palavrao , *torrada;

    pegastr( &palavrao );

    pegastr( &torrada , 10 );

    printf( "%s\n%s" , palavrao , torrada );

    return 0;
}
