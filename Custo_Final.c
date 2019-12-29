#include <stdio.h>
#include <stdlib.h>
double quick_sort(int A[] , int tamanho, int pivo_inicio, int confirmar_pivo, int fim);

int main() {
	int tamanho;
	scanf ("%d" , &tamanho);
	int vetor_principal[tamanho];
	for (int i=0;i<tamanho;i++){
		scanf ("%d", &vetor_principal[i]);
	}
	double custo_op = 0.0;
	double custo_total = 0.0;
	for (int j=0;j<tamanho;j++){
		custo_op = 0;
		custo_op = quick_sort(vetor_principal , tamanho, vetor_principal[j], 1, vetor_principal[tamanho-1]);
		custo_total+=custo_op;
		
	}
	double custo_medio = custo_total / tamanho;
	printf("%.10lf\n", custo_medio);
}

double quick_sort (int A[], int tamanho, int pivo_inicio, int confirmar_pivo , int fim){
	double custo = 0;
	if (tamanho<2){
		return custo;
	}
	else{
		int pivo;
		if (confirmar_pivo == 1){
			pivo = pivo_inicio;	
		}
		if (confirmar_pivo == 0){
			pivo = A[0];
		}
		int menores[tamanho];
		int maiores[tamanho];
		int qtde_menores = 0;
		int qtde_maiores = 0;
		int posicao_pivo = 0;
		double c1=0.0,c2=0.0;
		double c_ma = 0.0 , c_me=0.0;
		while (A[posicao_pivo] != pivo){
			posicao_pivo++;		
		}
		for (int j=0;j<posicao_pivo;j++){
			if (A[j]<pivo){
				menores[qtde_menores]=A[j];
				qtde_menores++;
			}
			if (A[j]>pivo){
				maiores[qtde_maiores]=A[j];
				qtde_maiores++;
				custo++;
				c_ma++;
			}
		}
		for (int j=posicao_pivo;j<tamanho;j++){
			if (A[j]<pivo){
				menores[qtde_menores]=A[j];
				qtde_menores++;
				custo++;
				c_me++;
			}
			if (A[j]>pivo){
				maiores[qtde_maiores]=A[j];
				qtde_maiores++;
			}
		}
		for (int i=0;i<qtde_menores;i++){
			c1 +=((quick_sort(menores, qtde_menores, menores[i], 0, menores[qtde_menores-1])));
		}		
		for (int i=0;i<qtde_maiores;i++){
			c2 += ((quick_sort(maiores, qtde_maiores, maiores[i], 0, maiores[qtde_maiores-1])));
		}
		
		double custo_rec = (c1+c2)/custo;
		return custo + custo_rec;
	}
}
