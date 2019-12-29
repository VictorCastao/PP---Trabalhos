#include <stdio.h>
#include <string.h>

int main () {

char A [50] = "Iscas de Carne ao Molho Ferrugem";
char B [50] = "Filé de Peixe à Escabeche";
char C [50] = "Arroz Fazendeiro";
char D [50] = "Frango Cremoso";
char E [50] = "Sair do Menu";
int escolha = 0;

printf("Escolha uma das opcoes:\n 1 - %s \n 2 - %s \n 3 - %s \n 4 - %s \n 5 - %s \n",A,B,C,D,E);

while (escolha != 5) {

scanf ("%d", &escolha);

if (escolha == 1)
printf("Prato Escolhido: %s\n" , A);

if (escolha == 2)
printf("Prato Escolhido: %s\n" , B);

if (escolha == 3)
printf("Prato Escolhido: %s\n" , C);

if (escolha == 4)
printf("Prato Escolhido: %s\n" , D);

}

printf ("%s\n", E);
 

return 0;

}


