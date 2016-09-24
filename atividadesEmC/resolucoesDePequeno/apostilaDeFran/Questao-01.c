#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Primeira questão :
int main (){
    setlocale(LC_ALL,"portuguese");
    float num;
    printf("Digite um número inteiro : ");
    scanf("%f",&num);
    float calculo = pow(num,2);
    printf("O resultado é : %.0f",calculo);

return 0;

}
