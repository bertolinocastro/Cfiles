#include  <stdio.h>
#include  <stdlib.h>
#include  <locale.h>



main(){

setlocale(LC_ALL,"Portuguese");

int x,y;

printf("Digite o primeiro número : ");
scanf("%d",&x);
printf("Digite o segundo número : ");
scanf("%d",&y);


if (x>y){
    printf("O maior número digitado é : %d.\n",x);
}else{
    printf("O maior número digitado é : %d.\n",y);
}














system("pause");

}
