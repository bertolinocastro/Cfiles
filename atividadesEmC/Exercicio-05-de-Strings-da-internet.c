/*Crie uma função que mostre os caracteres da string que se repetem.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

	char str[40];
	int tamanho,x,y;

	printf("Digite uma string : ");
	gets(str);
	printf("\n");

	tamanho = strlen(str);

	for (x=0;x<tamanho;x++)
		for (y=x+1;y<=tamanho;y++)
			if (x!=y)
				if (str[x] == str[y])
					printf("Os caracteres presentes nas posicoes %d e %d sao iguais.\n\n",x+1,y+1);
	return 0;
}
