#include  <stdio.h>
#include  <stdlib.h>
#include  <locale.h>



main(){

setlocale(LC_ALL,"Portuguese");

int x,r;


printf("Digite o valor do número : ");
scanf("%d",&x);

if (x >= 10) {
    r = x + 5;
    printf("%d\n",r);
}else{
    r = x - 7;
    printf("%d\n",r);
}


















system("pause");

}
