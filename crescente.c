#include <stdio.h>

int main () {

int a, b, c;
int maior, menor, meio;

printf("Digite tres numeros separados por espaco:");
scanf ("%d %d %d" , &a , &b , &c);

if ((a >= b) && (a >= c))
	maior = a;

if ((b >= a) && (b >= c))
	maior = b;

if ((c >= b) && (c >= a))
	maior = c;

if ((a <= b) && (a <= c))
	menor = a;

if ((b <= a) && (b <= c))
	menor = b;

if ((c <= b) && (c <= a))
	menor = c;

if (((a <= b) && (a >= c)) || ((a >= b) && (a <= c)))
	meio = a;

if (((b <= a) && (b >= c)) || ((b >= a) && (b <= c)))
	meio = b;

if (((c <= b) && (c >= a)) || ((c >= b) && (c <= a)))
	meio = c;

printf("A ordem crescente eh: %d %d %d\n", menor, meio, maior);

return 0;

}


