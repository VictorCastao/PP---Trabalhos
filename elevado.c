#include <stdio.h>
#include <string.h>

int main () {


int a, b, i;

printf("Escolha dois numeros de forma a calcular a^b\n");

printf("Valor de a:\n");

scanf("%d" , &a);

printf("Valor de b:\n");

scanf("%d" , &b);

if (b == 0)
printf("%d\n", 1);

else{
for (i = 2 ; i <= b ; i ++) {
	a*=a;
}  
}

printf("%d\n", a);
return 0;

}


