#include <stdio.h>
#include <string.h>

#define MAX_NOME 52
#define MAX_END 102
#define MAX_TEL 14
#define MAX_ANIV 10

typedef struct informacoes {
			char nome [MAX_NOME];
			char endereco [MAX_END];
			char telefone [MAX_TEL];
			char aniversario [MAX_ANIV];
			int posicao;				
			} t_info;

int inserir (int num ,t_info contatos[1000]){
	fgets(contatos[num].nome, MAX_NOME , stdin);
	fgets(contatos[num].endereco , MAX_END , stdin);
	fgets(contatos[num].telefone , MAX_TEL , stdin);
	fgets(contatos[num].aniversario , MAX_ANIV , stdin);
	contatos[num].posicao = num + 1;
	//lembrar que as informações possuem um \n devido ao fgets (lembrar disso para printar nomes)
	printf("Registro inserido.\n\n");
	int retorno = num + 1;
	return retorno;	
}

void imprimir (int num, t_info contatos[1000]){
	printf("Listagem:\n");
	if (num == 0)
		printf("Nenhum registro.\n\n");
	else{
		for (int i=0 ; i<num ; i++){
			printf("%d- %s", contatos[i].posicao , contatos[i].nome);
			printf("%s", contatos[i].endereco);
			printf("%s", contatos[i].telefone);		
			printf("%s", contatos[i].aniversario);
			printf("\n");		
		}
	}
}

void buscar (int num , t_info contatos[1000]){
	char trecho_busca[MAX_NOME];
	fgets(trecho_busca , MAX_NOME , stdin);	
	int tamanho = strlen(trecho_busca) - 1;
	int resultados = 0;
	printf("Resultado da busca:\n");

	for (int num_vet = 0 ; num_vet < num ; num_vet++){
		int tam_nome = strlen(contatos[num_vet].nome);
		int limite_for = tam_nome - tamanho;
		int acc2 = 0;
		
		for (int deslocamento = 0 ; deslocamento <= limite_for ; deslocamento++){
			int acc1 = 0;
		
			for (int inicio = 0 ; inicio < tamanho ; inicio++){
				if ( contatos[num_vet].nome[inicio+deslocamento] == trecho_busca[inicio] )
					acc1++;
			}
			if (acc1 == tamanho){
				acc2++;
				break;
			} 
		}	
		if (acc2 > 0){
			printf("%d- %s", contatos[num_vet].posicao , contatos[num_vet].nome);
			printf("%s", contatos[num_vet].endereco);
			printf("%s", contatos[num_vet].telefone);		
			printf("%s", contatos[num_vet].aniversario);
			printf("\n");
			resultados++;			
		}
	}
	if (resultados == 0)
		printf("Nenhum registro.\n\n");
}

int remover (int num , t_info contatos[1000]){
	int removidos = 0;
	char remover[MAX_NOME];
	fgets(remover , MAX_NOME , stdin);
	
	for (int i=0 ; i<num ; i++){
		int comparador = strcmp (remover , contatos[i].nome);
		if (comparador == 0){
			strcpy (contatos[i].nome , " "); 
			strcpy (contatos[i].endereco , " "); 
			strcpy (contatos[i].telefone , " "); 
			strcpy (contatos[i].aniversario , " ");
			removidos++;
		}
	}
	printf("%d registros removidos.\n\n", removidos);

	//reposicionar endereços após remover
	for (int j=0 ; j<num ; j++){
		int vazio = strcmp (contatos[j].nome , " ");
		if (vazio == 0){
			for (int k=j ; k<num ; k++){
				strcpy (contatos[k].nome , contatos[k+1].nome);
				strcpy (contatos[k].endereco , contatos[k+1].endereco);
				strcpy (contatos[k].telefone , contatos[k+1].telefone);
				strcpy (contatos[k].aniversario , contatos[k+1].aniversario);
			}
		}
	}	
	int novo_num = num - removidos;
	return novo_num;
}

int main (){
	t_info agenda[1000];
	int numero_contatos = 0;
	for(;;) {
		char operacao[4]; //tamanho 4 para permitir fgets
		fgets (operacao,4,stdin); 
		//fgets ao inves de scanf para corrigir problema ao chamar a função (estava considerando o "enter")  
		//tamanho 4 devido ao espaço dado na função remover em um dos casos teste
		//tentar descobrir um jeito para melhorar essas questões		
		if (operacao[0] == 'f')
			break;
		if (operacao[0] == 'i')
			numero_contatos = inserir (numero_contatos , agenda);
		if (operacao[0] == 'p')
			imprimir (numero_contatos , agenda);
		if (operacao[0] == 'b')
			buscar (numero_contatos , agenda);
		if (operacao[0] == 'r')
			numero_contatos = remover (numero_contatos , agenda);	
		}

	return 0;
}
