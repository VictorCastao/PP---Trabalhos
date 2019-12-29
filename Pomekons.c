#include <stdio.h>
#include <string.h>

// Calcular as frequencias das strings
void frequencimetro (char matriz[1000][128],int tamanho,int saida[1000]){
	int i,j,repeticoes;
	for (j=0 ; j<tamanho ; j++){
		repeticoes = 0;
		for (i=0 ; i<tamanho; i++){
			int comparacao = strcmp (matriz[j],matriz[i]);
			if (comparacao == 0)
			repeticoes++;
		}
		saida[j] = repeticoes;
	}
}

// Calcular as frequencias das strings eliminando strings repetidas
int eliminar_repeticoes (char matriz[1000][128],int tamanho, int frequencia[1000], char strings_unicas[1000][128], int frequencias_unicas[1000]){
	int i,j;
	int posicao_nova = 0;
	for (j=0 ; j<tamanho ; j++){
		int acc = 0;
		for(i=0 ; i<posicao_nova ; i++){
			int comparacao = strcmp (matriz[j],strings_unicas[i]);
			if (comparacao == 0)
				acc++;  
		}
		if (acc == 0){
		strcpy (strings_unicas[posicao_nova], matriz[j]);
		frequencias_unicas[posicao_nova] = frequencia[j];		
		posicao_nova++;
		}
	}
	return posicao_nova;
}

// Determinar o valor máximo de repetições
int maximo (int vetor[1000], int tamanho_vetor){
	int i;
	int max = 0;
	for (i=0 ; i<tamanho_vetor ; i++){
		if (vetor[i] > max)
			max = vetor[i];
	}
	return max;
}

// Printar mais frequentes
void printar(char nomes[1000][128],int frequencias[1000], int tamanho, int maximo){
	int i;
	for (i=0 ; i<tamanho ; i++){
		if (frequencias[i] == maximo)
			printf("%s ", nomes[i]);
	}
}


int main () {

 int n,i;
 for(;;){
	char capturados[1000][128];
	int frequencias[1000];
	int numero_pomekons_diferentes;
	char lista_sem_repeticao[151][128];
	int frequencia_sem_repeticao[151];
	int maior_frequencia;
	int faltantes;
	
	scanf("%d",&n);
		
	if (n == 0)
		break;
	else{
		for (i=0 ; i<n ; i++) {
			scanf("%s", &capturados[i][0]);
		}
		frequencimetro (capturados, n, frequencias);
		numero_pomekons_diferentes = eliminar_repeticoes (capturados, n, frequencias, lista_sem_repeticao, frequencia_sem_repeticao); 
		maior_frequencia = maximo (frequencia_sem_repeticao, numero_pomekons_diferentes);
		faltantes = 151 - numero_pomekons_diferentes;
		printf("Falta(m) %d pomekon(s).\n", faltantes);
		printf("Pomekon(s) mais repetido(s): ");
		printar (lista_sem_repeticao, frequencia_sem_repeticao, numero_pomekons_diferentes, maior_frequencia);
		printf("\n\n");
	}
 }
 return 0;
}
