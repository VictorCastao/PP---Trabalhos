#include <stdio.h>
#include <stdlib.h>
int quick_sort(int A[] , int final[] , int tamanho);

int main() {
	int tamanho;
	scanf ("%d" , &tamanho);
	int vetor_principal[tamanho];
	for (int i=0;i<tamanho;i++){
		scanf ("%d", &vetor_principal[i]);
	}
	int vetor_ordenado[tamanho];
	quick_sort (vetor_principal,vetor_ordenado,tamanho);
	
}

int quick_sort (int A[] , int final[], int tamanho){	
	if (tamanho < 2){
		final = A;
	}
	else{
		int pivo = A[tamanho/2];
		int qtde_menor = 0;
		int qtde_maior = 0;
		for (int i=0;i<tamanho;i++){
			if (A[i] != pivo && A[i] < pivo){
				qtde_menor++;
			}
			if (A[i] != pivo && A[i] > pivo){
				qtde_maior++;
			}
		}
		int esquerda [qtde_menor];
		int direita [qtde_maior];
		int pos_esq = 0;
		int pos_dir = 0;
		for (int i=0;i<tamanho;i++){
			if (A[i] != pivo && A[i] < pivo){
				esquerda[pos_esq]=A[i];
				pos_esq++;
			}
			if (A[i] != pivo && A[i] > pivo){
				direita[pos_dir]=A[i];
				pos_dir++;
			}
		}
		

	}	
	
	return 0;
	

}



