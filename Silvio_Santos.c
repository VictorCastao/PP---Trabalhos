#include <stdio.h>
#include <stdlib.h>

//Definindo estrutura da lista
typedef struct elementos {
	char conteudo;
	struct elementos *proximo;
} lista;

//Declaração de funções a serem utilizadas
void inserir (lista **p , char valor);

void encontrar_maior (lista *ponteiro , int tamanho,  int qtde);

void remover_elemento (lista *ponteiro , char apagar);

void remover_primeiro (lista **ponteiro);

void imprimir_numero (lista *ponteiro);

lista * busca (lista *p , int pos);

//Função principal
int main(){

for(;;){
	//Início dos passos
	int tamanho, qtde_apagar;
	scanf ("%d %d", &tamanho , &qtde_apagar);
	if (tamanho == 0 && qtde_apagar == 0){
		break;
	}

	//Criação de ponteiros necessários	
	lista *ponteiro = NULL;
	char *numero = malloc ((tamanho+1) * (sizeof (char)));
	scanf ("%s" , numero);
	lista **ponteiro_2 = &ponteiro;
	
	//Inserir elementos na lista encadeada
	for (int i = 0 ; i < tamanho ; i++){
		inserir (ponteiro_2 , numero[i]);	
	}

	//Encontrar o maior número
	encontrar_maior (ponteiro , tamanho , qtde_apagar);
	
	//Printar o maior número
	imprimir_numero(ponteiro);
	printf("\n");

	//Limpar lista
	free (ponteiro);
}

return 0;
}

//Funções a serem utilizadas
void inserir (lista **p , char valor){
	lista *elemento = malloc (sizeof (lista));
	elemento -> conteudo = valor;
	elemento -> proximo = NULL;	
	if (*p == NULL){
		*p = elemento;	
	}
	else{
		lista *auxiliar = *p;
		while (auxiliar -> proximo != NULL){
			auxiliar = auxiliar -> proximo;
		}		
		auxiliar -> proximo = elemento;	
	}
}

void encontrar_maior (lista *ponteiro , int tamanho , int qtde){
	/*char *maior = malloc ((tamanho-qtde) * sizeof (char));
	for (int i=0 ; i<(tamanho-qtde) ; i++){
		maior[i] = '0';	
	}
	int minimo = 0;
	for (int v = 0 ; v < (tamanho-qtde) ; v++){
		int maximo = tamanho-qtde+v+1;
		lista *valor = ponteiro;
		for (int posicao = 0 ; posicao <= maximo ; posicao++){
			if (valor->conteudo > maior[v] && posicao >= minimo && posicao <= maximo){
				maior[v] = (busca(ponteiro , posicao))->conteudo;			
			}
			valor = valor->proximo;
		}
		minimo = maximo;
	}
	for (int i=0 ; i<(tamanho-qtde) ; i++){
		printf ("%c" , maior[i]);	
	}*/

	lista *valor = ponteiro;
	char menor, anterior = '0';
	char *apagar_estes = malloc (qtde * sizeof(char));

		for(int j=0 ; j<qtde ; j++){
			menor = '9';
			valor = ponteiro;
		for (int i = 0 ; i < tamanho ;i++){
			if (valor->conteudo < menor  && valor->conteudo > anterior){
				menor = busca(ponteiro , i)->conteudo;
			}
			valor = valor->proximo;
		}
		anterior = menor;
		apagar_estes[j] =  menor;
		}
		valor = NULL;
		for (int k = 0 ; k<qtde;k++){
		remover_elemento(ponteiro , apagar_estes[k]);}
				
		
		

		//remover_elemento(ponteiro , menor);
		//tamanho--;
	
}	
		
void remover_elemento (lista *ponteiro, char apagar){
	lista *aux_1 = ponteiro;
	while (aux_1->proximo->conteudo != apagar){
		aux_1 = aux_1->proximo;
	}
	lista *aux_2 = aux_1->proximo;
	aux_1->proximo = aux_2->proximo;
	aux_2->proximo = NULL;
	free(aux_2);
	aux_1 = ponteiro;
}

void imprimir_numero (lista *ponteiro){
	lista *print = ponteiro;	
	while (print != NULL){
		printf("%c" ,  print->conteudo);
		print = print->proximo; 
	}
}

void remover_primeiro (lista **ponteiro){
	lista *rem;
	rem = *ponteiro;
	*ponteiro = rem->proximo;
	free (rem);
} 

lista * busca (lista *p , int pos){
	lista *q = p;
	for (int p = 0 ; p < pos ; p++){
		q = q->proximo;
	}
	return q;
}
