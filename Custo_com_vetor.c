#include <stdio.h>
#include <stdlib.h>
int quick_sort(int vetor[] , int tamanho, int pivo);

int main() {
	int tamanho;
	scanf ("%d" , &tamanho);
	int vetor_principal[tamanho];
	for (int i=0;i<tamanho;i++){
		scanf ("%d", &vetor_principal[i]);
	}
	int soma_custos = 0;
	for (int j=0 ; j<tamanho ; j++){
		int custo_op = quick_sort(vetor_principal , tamanho , vetor_principal[j]);
		soma_custos += custo_op;
	}
	//float custo_medio = soma_custos/tamanho;
	float custo_medio = quick_sort(vetor_principal , tamanho, 2);	
	printf("%.10f\n" , custo_medio); 	
	return 0;
}

int quick_sort (int vetor[] , int tamanho, int pivo){
	int custo = 0;
	int vet[2];
	vet[1]=3;
	int *pont;
	pont = vet;
	
	
	return pont;
}



