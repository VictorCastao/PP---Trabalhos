#include <stdio.h>
#include <stdlib.h>
int quick_sort(int *vetor , int tamanho, int pivo, int *vet_ord , int primeira);

int main() {
	int tamanho;
	scanf ("%d" , &tamanho);
	int *vetor_principal = malloc (tamanho * (sizeof (int)));
	for (int i=0;i<tamanho;i++){
		scanf ("%d", &vetor_principal[i]);
	}
	int soma_custos = 0;
	for (int j=0 ; j<tamanho ; j++){
		int *vetor_ordenado;
		vetor_ordenado = malloc (tamanho * (sizeof (int)));
		int custo_op = quick_sort(vetor_principal , tamanho , vetor_principal[j] , vetor_ordenado, 1);
		soma_custos += custo_op;
		free (vetor_ordenado);
	}
	//float custo_medio = soma_custos/tamanho;
	free(vetor_principal); 	
	return 0;
}

int quick_sort (int *vetor , int tamanho, int pivo, int *vet_ord , int primeira){
	int custo = 0; 	
	if (tamanho < 2){
		*vet_ord = *vetor;
	}
	else{
		int tam_esq = 0;
		int tam_dir = 0;
		int pivo_2;
		if(primeira_vez == 0){
			pivo_2 = vetor[tamanho/2];
		}
		else{
			pivo_2 = pivo;
		}
		int *esq = NULL;
		int *dir = NULL;	
		for (int i=0 ; i<tamanho ; i++){
			if (vetor[i] == pivo_2){
				continue;
			}
			if (i < (tamanho/2)){
				if (vetor[i] < pivo_2){
					tam_esq++;
					esq = realloc (esq, tam_esq * (sizeof(int)));
					esq[tam_esq - 1] = vetor[i];
					continue;
				}
				else{
					custo++;
					tam_dir++;
					dir = realloc (dir, tam_dir * (sizeof(int)));
					dir[tam_dir - 1] = vetor[i];
					continue;
				}
			}
			if (i > (tamanho/2)){
				if (vetor[i] > pivo_2){
					tam_dir++;
					dir = realloc (dir, tam_dir * (sizeof(int)));
					dir[tam_dir - 1] = vetor[i];
					continue;
				}
				else{
					custo++;
					tam_esq++;
					esq = realloc (esq, tam_esq * (sizeof(int)));
					esq[tam_esq - 1] = vetor[i];
					continue;
				}
			}		
		}
		int *vet_esq = NULL;
		int *vet_dir = NULL;
		quick_sort (esq , tam_esq , 0 , vet_esq , 0);
		quick_sort (dir , tam_dir , 0 , vet_dir , 0);
		//pensar tamanho correto para concatenar
		free(esq);
		free(dir);	
	}

	
	
	
	return custo;
}



