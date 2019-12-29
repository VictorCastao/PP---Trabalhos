#include <stdio.h>

int main () {

int a;

printf("Digite um numero:");
scanf("%d" , &a);

if (((a % 2 == 0) && (a > 10)) || ((a % 2 != 0) && (a < 50)))
	printf("SIM\n");
else
	printf("NAO\n");

return 0;

}


