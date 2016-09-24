#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Quinta questão :
int main (){
setlocale(LC_ALL,"portuguese");

int anos;
int meses;
int dias;

printf("Digite quantos anos você tem : ");
scanf("%d",&anos);
printf("Digite quantos meses você tem : ");
scanf("%d",&meses);
printf("Digite quantos dias você tem : ");
scanf("%d",&dias);

int total = (365 * anos) + (meses * 30) + dias;

printf("O valor total expresso em dias é de : %d.",total);


return 0;

}
