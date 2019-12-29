#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *proximo;
} lista;

void criar_lista (lista **p);

void inserir_final (lista **p , int v);

void remover_final (lista **p);

void apagar_lista (lista **p);

int topo (lista *p);

int main(){
	int tamanho , temporario;
	lista *pilha = NULL;
	lista *pilha_2 = NULL;
	for(;;){
		int top,valido,soma;
		top = 0;
		valido = 1;	
		scanf("%d" , &tamanho);
		if (tamanho == 0){
			break;		
		}	
		criar_lista (&pilha);
		criar_lista (&pilha_2);		
		for (int i = 0 ; i < tamanho ; i++){
			scanf ("%d" , &temporario);
			//Verificação da forma da lista (em sintaxe)
			if (temporario < 0){
				if (top != 0 && temporario <= top){
					valido = 0;
					
				}
				else{
					inserir_final (&pilha , temporario);
					inserir_final (&pilha_2 , temporario);
					top = topo(pilha);
				}
			}
			else if (temporario > 0){
				if (temporario != ((top) * (-1))){
					valido = 0;
					
				}
				else if (temporario == ((top) * (-1))){
					remover_final (&pilha);
					inserir_final (&pilha_2 , temporario);
					top = topo(pilha);
				}
			}
		}
		//Verificação da forma da lista (soma das camadas internas)
		if (valido == 1){
			lista *cursor_1 , *cursor_2 , *posicao;
			posicao = pilha_2->proximo;
			for (int i=0 ; i<(tamanho/2) ; i++ ){
				soma = 0;
				cursor_1 = posicao->proximo;
				cursor_2 = posicao->proximo;
				while ((cursor_1->valor) != ((posicao->valor) * (-1))){
					while ((cursor_2->valor) != ((cursor_1->valor) * (-1))){
						cursor_2 = cursor_2->proximo;
					}
					soma += (int) cursor_2->valor;
					cursor_1 = cursor_2->proximo;
					cursor_2 = cursor_2->proximo; 
				}
				if ((soma) >= (int)((posicao->valor) * (-1))){
					valido = 0;
					soma=0;
					break;
				}
				else {
					while(posicao->valor > 0)
					posicao = posicao->proximo;
				}
			}
			cursor_1 = NULL;
			free(cursor_1);
			cursor_2 = NULL;			
			free(cursor_2);
			posicao=NULL;			
			free(posicao);
		}
		if (valido == 1 && pilha->valor == 0){
			printf(":-) Matrioshka!\n");
		}
		else{
			printf(":-( Tente novamente.\n");	
		}
		apagar_lista(&pilha_2);
		apagar_lista(&pilha);
	}
	return 0;
}

//Funções Auxiliares
void criar_lista (lista **p){
	lista *primeiro = malloc (sizeof (lista));
	primeiro->valor = 0;
	primeiro->proximo = NULL;
	*p = primeiro;
}

void inserir_final (lista **p , int v){
	lista *posicao = *p;
	lista *elemento = malloc (sizeof (lista));
	elemento->valor = v;
	elemento->proximo = NULL;
	while (posicao->proximo != NULL){
		posicao = posicao->proximo;
	}
	posicao->proximo = elemento;
	(*p)->valor++;
}

void remover_final (lista **p){
	lista *busca_ultimo = *p;
	if (busca_ultimo->valor == 0){
	}
	else if (busca_ultimo->valor == 1){
		busca_ultimo = busca_ultimo->proximo;
		(*p)->proximo = NULL;
		free(busca_ultimo);
		(*p)->valor--;
	}
	else{	
		while (busca_ultimo->proximo->proximo != NULL){
			busca_ultimo = busca_ultimo->proximo;
		}
		lista *aux = busca_ultimo->proximo;
		busca_ultimo->proximo = NULL;
		free (aux);
		(*p)->valor--;
	}
}

void apagar_lista (lista **p){
	lista *q;
	while (*p != NULL) {
		q = *p;
		*p = (*p)->proximo;
		free(q);
	}
}

int topo (lista *p){
	lista *topo;
	topo = p;
	while (topo->proximo != NULL){
		topo = topo->proximo;
	}
	return (int) topo->valor;
}
