#include <stdio.h>

int main () {

int a, b, c;

printf("Digite tres numeros separados por espaco:");
scanf ("%d %d %d" , &a , &b , &c);

if ((a >= b) && (a >= c))
	printf("O maior eh %d\n", a); 

if ((b >= a) && (b >= c))
	printf("O maior eh %d\n", b);

if ((c >= b) && (c >= a))
	printf("O maior eh %d\n", c);  


return 0;

}


