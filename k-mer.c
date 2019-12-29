#include <stdio.h>
#include <string.h>

int main () 
{
	int k;
	char sequencia[1025];
	scanf("%s", sequencia);
	scanf("%d", &k);
	int tamanho_string = strlen(sequencia);
	int i;
	int acumulador;
	int maior_repeticao = 0;
	int repeticao_atual = 0;	
	int deslocamento_1 = 0;
	int deslocamento_2 = 0;
	char string_final[1025];
	char string_atual[1025];
	int limite_d1 = tamanho_string - (2*k);
	int limite_d2 = tamanho_string - k + 1;
	char auxiliar;

	for (deslocamento_1 = 0 ; deslocamento_1 <= limite_d1 ; deslocamento_1++) {
		repeticao_atual = 0;			

		for (deslocamento_2 = 0; deslocamento_2 <= limite_d2 ; deslocamento_2++) {
			acumulador = 0;
			strcpy (string_atual , "");
			for (i=0 ; i < k ; i++) {
				if (sequencia[i + deslocamento_1] == sequencia[i + k + deslocamento_2 + deslocamento_1]) {
					acumulador += 1;	
					string_atual[i] = sequencia [i + deslocamento_1]; 
				}
			}
						
			if (acumulador == k) {
				repeticao_atual += 1;
			}
		if (repeticao_atual > maior_repeticao) {
			maior_repeticao = repeticao_atual;
			strcpy (string_final , string_atual);
		}
		if (repeticao_atual == maior_repeticao){
			
			strcpy (string_final , strcat (string_final , " "));
			strcpy (string_final , strcat (string_final , string_atual));	
		}
		}
	}
	printf("%s\n",string_final);	
}
