#include <stdio.h>
#include <locale.h>
#include <math.h>

int main (){
setlocale(LC_ALL,"portuguese");
int a = 10;
int b = 20;
b = a;
a = b;
printf("O valor de A é %d e o valor de B é %d .",a,b);

return 0;

}
