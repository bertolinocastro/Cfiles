#include <stdio.h>
#include <locale.h>
#include <math.h>

int main (){
setlocale(LC_ALL,"portuguese");


float total;
float brancos;
float nulos;
float val;

printf("Digite o total de eleitores no município : ");
scanf("%f",&total);

printf("Digite o total de votos brancos : ");
scanf("%f",&brancos);

printf("Digite o total de votos nulos : ");
scanf("%f",&nulos);

printf("Digite o total de votos válidos : ");
scanf("%f",&val);

float pbrancos = (brancos/total) * 100;
float pnulos = (nulos/total) * 100;
float pval = (val/total) * 100;



printf("A porcentagem de votos brancos foi de %.2f %%.\nA porcentagem de votos nulos foi de %.2f %%.\nA porcentagem de votos válidos foi de %.2f %%. ",pbrancos,pnulos,pval);







return 0;

}
