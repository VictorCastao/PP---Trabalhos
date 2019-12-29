#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct fazer_o_que{
    char funcao[7];
    char nome_arquivo[11];
    char tamanho_arquivo[7];
    } op;

typedef struct hd{
    char arq[11];
    int tam_arq;
    int apagado;
    struct hd *proximo;
} lista;

int otimizar(lista **p);

void inserir_final (lista **p ,char nome[], int tamanho){
	lista *posicao = *p;
	lista *elemento = malloc (sizeof (lista));
	strcpy (elemento->arq,nome);
    elemento->apagado = 0;
    elemento->tam_arq = tamanho;
	elemento->proximo = NULL;
	while (posicao->proximo != NULL){
		posicao = posicao->proximo;
	}
	posicao->proximo = elemento;
}

int inserir_arquivo (lista **p, char nome_arquivo[], int tamanho_arquivo, int tam_disco, int livre_no_final){
    int tamanho_usado;
    lista *j = *p;
    while (j != NULL)
    {
        if (j->apagado == 0){tamanho_usado+= j->tam_arq;}
        j = j->proximo;
    }
     
    if (tamanho_arquivo > tam_disco || (tamanho_usado+tamanho_arquivo) > tam_disco){
        return -1;
    }
    else{
    //Novo Arquivo
    lista *novo;
    novo = malloc (sizeof(lista));
    novo->apagado = 0;
    strcpy (novo->arq,nome_arquivo);
    novo->tam_arq = tamanho_arquivo;
    novo->proximo = NULL;

    //Inserção de fato
    int insere = 0;
    lista *aux_4 = *p;
    int espaco_disponivel = 0;
    for (aux_4 = *p ; aux_4->proximo == NULL ;){
        lista *aux_5 = aux_4;
        if (aux_4 == *p && aux_4->apagado==1){
            espaco_disponivel += aux_4->tam_arq;
            if (aux_4->proximo->apagado == 1){
                aux_5 = aux_4->proximo;
                while (aux_5->apagado == 1){
                    if (aux_5->proximo == NULL){
                        espaco_disponivel += aux_5->tam_arq;
                        break;
                    }
                    else{
                        espaco_disponivel += aux_5->tam_arq;
                        aux_5 = aux_5->proximo;
                    }
                }
            }
        }
        else{
            if (aux_4->proximo->apagado == 1){
                lista *aux_5 = aux_4->proximo;
                
                while (aux_5->apagado == 1){
                    if (aux_5->proximo == NULL){
                        espaco_disponivel += aux_5->tam_arq;
                        break;
                    }
                    else{
                        espaco_disponivel += aux_5->tam_arq;
                        aux_5 = aux_5->proximo;
                    }
                }
            }
        }
        if (espaco_disponivel > tamanho_arquivo){
            insere++;
            novo->proximo = aux_4->proximo;
            aux_4->proximo = novo;
            novo->proximo->tam_arq -= tamanho_arquivo;
        }
        else{
            espaco_disponivel = 0;
            aux_4 = aux_4->proximo;
        } 
        if (insere != 0) break;
    }
    if (insere == 0){
        if (livre_no_final > tamanho_arquivo){
            inserir_final(&novo,nome_arquivo,tamanho_arquivo);
            return tamanho_arquivo;
        }
        else{
            int a = otimizar(p);
            if (a>tamanho_arquivo){
                inserir_final(&novo,nome_arquivo,tamanho_arquivo);
                return tamanho_arquivo;
            }
            else{
                return -1;
            }
        }
    }
    }
} 


void criar_lista (lista **p,char nome[],int tamanho){
	lista *primeiro = malloc (sizeof (lista));
	strcpy (primeiro->arq,nome);
    primeiro->apagado = 0;
    primeiro->tam_arq = tamanho;
	primeiro->proximo = NULL;
	*p = primeiro;
}

void remover_elemento (lista **p, char nome[]){
	lista *aux = *p;
    for (aux = *p ; aux->proximo == NULL ; aux = aux->proximo){
        if (strcmp (aux->arq , nome) == 0){
            aux->apagado = 1;
            break;
        }
    }    
}

int otimizar (lista **p){
    lista *aux_2 = *p;
    int retorno=0;
    for (aux_2 = *p ; aux_2->proximo->proximo != NULL ; aux_2 = aux_2->proximo){
        if (aux_2 == *p && aux_2->apagado == 1){
            lista *aux_3 = *p;
            aux_2 = aux_2->proximo;
            *p = aux_2;
            retorno+=aux_3->tam_arq;
            free(aux_3);
            continue;
        }
        if (aux_2->proximo->apagado == 1){
            lista *aux_3 = aux_2->proximo;
            aux_2->proximo = aux_2->proximo->proximo;
            retorno+=aux_3->tam_arq;
            free(aux_3);
        }
    }
    if (aux_2->proximo->apagado == 1){
        aux_2 = aux_2->proximo;
        retorno+=aux_2->tam_arq;
        free(aux_2);
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

void unidade_arquivo(char nome[], char retorno[]);
int tamanho_arq (char arquivo[]);


//Função Principal
int main(){
    int operacoes = 0;
    char disco[7];
    int tamanho_disco;
    char unidade[3];
    for(;;){
        scanf ("%d",&operacoes);
        if (operacoes == 0)
            break;
        scanf("%s",disco);
        unidade_arquivo(disco,unidade);
        tamanho_disco = tamanho_arq(disco); //Tamanho de tudo com unidade padrão kb
        int num_arq = 0;
        int tamanho_livre_final = tamanho_disco;
        lista *pont = NULL;
        int deu_ruim = 0;
        for (int i=0 ; i < operacoes ; i++){
            if (deu_ruim != 0) break;
            op Mexer_Hd;
            scanf("%s", Mexer_Hd.funcao);
            int comp3 = strcmp (Mexer_Hd.funcao,"otimiza");
            int comp4 = strcmp (Mexer_Hd.funcao,"remove");

            if (comp3 != 0){
                if (comp4 != 0){
                scanf("%s",Mexer_Hd.nome_arquivo);
                scanf("%s",Mexer_Hd.tamanho_arquivo);}
                else{
                scanf("%s",Mexer_Hd.nome_arquivo);
                }
            }
            int tamanho_aq = tamanho_arq(Mexer_Hd.tamanho_arquivo);
            
            //Realizar operação em questão agora
            if (strcmp(Mexer_Hd.funcao,"insere") == 0){
                if (num_arq == 0){
                criar_lista(&pont,Mexer_Hd.nome_arquivo,tamanho_aq);
                num_arq++;
                }
                else{
                    int resp = inserir_arquivo(&pont,Mexer_Hd.nome_arquivo,tamanho_aq,tamanho_disco,tamanho_livre_final);
                    if (resp > 0){
                        tamanho_livre_final-=resp;
                        num_arq++;
                    }    
                        else{
                            printf("Erro: disco cheio\n");
                            deu_ruim = -1;
                        }
                }
            }

            else if (strcmp(Mexer_Hd.funcao,"remove") == 0){
                remover_elemento(&pont,Mexer_Hd.nome_arquivo);
            }    
            else{
                otimizar(&pont);
            }
            
        }
        apagar_lista(&pont);
    }
    return 0;
}

void unidade_arquivo(char nome[], char retorno[]){
    int tam = (int) strlen(nome);
    int j = 0;
    for (int i = (tam-2) ; i < tam ; i++){
        retorno[j] = nome[i];
        j++;
    }
    retorno[j] = '\0';
}

int tamanho_arq (char arquivo[]){
    int t = 0;
    char unid[3];
    unidade_arquivo(arquivo,unid);
    int i = (int) (strlen(arquivo)-2);
    char valor_numerico[i];
    int j;
    for (j=0 ; j<i ; j++){
        valor_numerico[j] = arquivo[j];
    }
    valor_numerico[j] = '\0';
    int pos = strlen(valor_numerico);
    for (int k = 0 ; k < pos; k++){
        int val = (int) valor_numerico[k] - '0';
        for (int mult = 0 ; mult < (pos-k-1) ; mult++){
            val*=10;
        }
        t+=val;
    }
    int comp1 = strcmp (unid,"Mb");
    int comp2 = strcmp (unid,"Gb");

    if (comp1 == 0) t*=1024;
    if (comp2 == 0) t*= (1024*1024);
    
    return t;
}



