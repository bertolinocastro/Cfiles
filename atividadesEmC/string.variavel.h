/*
 *
 * Para incluir esse arquivo no seu arquivo principal, caso esteja na
 * mesma pasta em que será chamado, escreva:
 *
 * # include "string.variavel.h"
 *
 * Caso esteja em outra pasta:
 *
 * # include < <caminho/do/arquivo/completo> >
 *
 * Observe que não há a necessidade de incluir <stdio.h> , <stdarg.h>
 * nem <stdlib.h> uma vez que já estão incluídas nesse arquivo.
 *
 * A chamada da função `pegastr()` deve ser feita passando um ponteiro
 * pré-declarado por "referência" (passando o endereço de memória dele,
 * já que C não possui passagem por referência). E, opcionalmente, pas-
 * sando o limite de caracteres que a string deve possuir.
 *
 * Dessa forma, a chamada dentro do seu arquivo principal deve ser feita
 * da seguinte forma:
 *
 *      pegastr( &<ponteiro> ); ou
 *      pegastr( &<ponteiro> , <limite> );
 *
 * O ponteiro deve ser previamente declarado como tipo char:
 *
 *      char *<ponteiro>;
 *
 * Resultado final, ex:
 *
 *      char *mariaBonita;
 *      pegastr( &mariaBonita ); ou
 *      pegastr( &mariaBonita , 70 );
 *
 * A utilização da função se dá no mesmo formato que o scanf(), porém,
 * ela armazena todo o texto inserido pelo usuário formatado para o tipo
 * "string" (char) e armazena todo o valor até a inserção do ENTER '\n'.
 * Ou até a string atingir o tamanho definido na chamada da função.
 *
 * OBS:
 *
 *      Em caso de criação de um vetor de strings, a declaração deve ser
 *      feita a seguinte forma:
 *
 *          char *<ponteiro>[<tamanho>];
 *
 *      O <tamanho> deve ser um valor inteiro positivo, podendo ser uma
 *      variável ou um número direto na declaração.
 *
 *      E a chamada da função é feita da seguinte forma:
 *
 *          pegastr( &<ponteiro>[<indice-atual>] );
 *
 *      Ex.:
 *
 *          char *isaac[10] , *asimov[x];
 *
 *          //Dentro da iteração:
 *              pegastr( &isaac[i] ); pegastr( &asimov[i] );
 *
 * OBS2:
 *
 *      Em caso de inicializar o ponteiro, proceda da seguinte forma:
 *
 *          char *<ponteiro> = NULL , *<ponteiro>[tamanho] = { NULL };
 *
 *      Ex.:
 *
 *          char *bertolino = NULL , *descricoes[n] = { NULL };
 *
 *
 * OBS3:
 *
 *      Vale ressaltar que, a cada chamada da função `pegastr()`, o buffer
 *      de entrada é limpo completamente para que não hajam comportamen-
 *      tos indevidos em chamadas seguintes a outras funções de entrada.
 *      Ou seja, caso seja digitada uma palavra maior que a necessitada
 *      numa chamada anterior da função `pegastr()`, os caracteres exce-
 *      dentes são eliminados do buffer.
 *
 *
 * OBS4:
 *
 *      A passagem do valor 0 como limite para a string a torna dinâmica,
 *      ou seja, sem tamanho limite. Pois, possui o mesmo comportamento
 *      caso não fosse passado o segunto argumento da função.
 */

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void pegastr( char **str , ... ){

    va_list valist;
    char x , *guardaStr ;
    unsigned int j , limit ;

    va_start( valist , str );
    limit = va_arg( valist , unsigned int );
    va_end( valist );

    guardaStr = malloc( 1 );
    if( guardaStr == NULL ) exit(1);
    guardaStr[0] = '\0';

    j = 1;
    while( 1 ){

        x = getc( stdin );
        if( x == '\n' || ( limit != 0 && j > limit ) ){ if( j == 1 ){ continue; }else{ break; } }/* Para não preencher uma string sem valores, possuindo pelo menos 1 caractere, exceto o '\n' */

        guardaStr = realloc( guardaStr , j + 1 );
        if( guardaStr == NULL ) exit(1);
        guardaStr[j-1] = x;
        guardaStr[j] = '\0';

        ++j;
    }

    *str = guardaStr;
    /*fflush( stdin );*/
    while( x != '\n' && x != EOF ) x = getc( stdin ) ; /* Modo alternativo de limpar o buffer de entrada */
}







