#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Terceira questão :
int main (){
setlocale(LC_ALL,"portuguese");

int valor;
int ant;
printf("Digite um valor : ");
scanf("%d",&valor);
ant = valor - 1;
printf("O antecessor do valor %d é %d .",valor,ant);





return 0;

}
