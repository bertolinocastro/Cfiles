#include  <stdio.h>
#include  <stdlib.h>
#include  <locale.h>
#define print() as printf()



main(){

setlocale(LC_ALL,"Portuguese");

int x;


printf("Digite o valor do número : ");
scanf("%d",&x);

if (x % 2 == 0){
    printf("O número digitado é par.\n");
}else{
    printf("O número digitado é ímpar.\n");
}

print("Ola");














system("pause");

}
