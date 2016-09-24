#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Quarta questão :
int main (){
setlocale(LC_ALL,"portuguese");

float base;
float altura;
float area;

printf("Digite o valor da base do retângulo(cm) : ");
scanf("%f",&base);
printf("Digite o valor da altura do retântangulo(cm) : ");
scanf("%f",&altura);
area = base * altura;
printf("O valor da área do retângulo é %.2f centímetros. ",area);



return 0;

}
