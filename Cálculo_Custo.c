#include <stdio.h>
#include <stdlib.h>
int quick_sort(int A[] , int final[] , int tamanho, int pivo_inicio, int confirmar_pivo);

int main() {
	int tamanho;
	scanf ("%d" , &tamanho);
	int vetor_principal[tamanho];
	for (int i=0;i<tamanho;i++){
		scanf ("%d", &vetor_principal[i]);
	}
	int vetor_ordenado[1];
	int custo_total = 0;
	for (int i=0 ; i<tamanho ; i++){
		vetor_ordenado[0] = 0;
		quick_sort (vetor_principal,vetor_ordenado,tamanho,vetor_principal[2],1);
		custo_total+=vetor_ordenado[0];
	} 
	float custo_medio = custo_total / tamanho;
	printf("%.10f", custo_medio);
}

int quick_sort (int A[] , int final[], int tamanho, int pivo_inicio, int confirmar_pivo){

	if (tamanho < 2){
		final[0]+=0;
		return 0;
	}
	else{
	int custo = 0;	
		int pivo;
		if (confirmar_pivo == 0){
			pivo = A[tamanho/2];
		}
		else{
			pivo = pivo_inicio;
		}
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
			if (i< (tamanho/2)){
				if (A[i] != pivo && A[i] < pivo){
					esquerda[pos_esq]=A[i];
					pos_esq++;
					continue;
				}
				if (A[i] != pivo && A[i] > pivo){
					direita[pos_dir]=A[i];
					pos_dir++;
					custo++;
					continue;
				}
			}
			if (i> (tamanho/2)){
				if (A[i] != pivo && A[i] < pivo){
					esquerda[pos_esq]=A[i];
					pos_esq++;
					custo++;
					continue;
				}
				if (A[i] != pivo && A[i] > pivo){
					direita[pos_dir]=A[i];
					pos_dir++;
					continue;
				}
			}
		}

		quick_sort(esquerda,final,qtde_menor,0,0);


		quick_sort(direita,final,qtde_maior,0,0);
		final[0]+=custo;
	return 0;
	}	
	

	

}



