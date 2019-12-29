#include <stdio.h>
#include <stdlib.h>

//Verificar se o elemento pertence a matriz

int elegivel (int linha, int coluna, int num_linha, int num_coluna){
if ((linha >= 0) && (linha < num_linha) && (coluna >= 0) && (coluna < num_coluna))
	return 1;
else
	return 0; 
}

//Função Principal

int main () {

for (int numero_campo = 1;;numero_campo++){

int m , n;
char **matriz_campo_minado;

scanf ("%d %d", &m , &n);


if ((m == 0) && (n == 0)) {
	break;
}

//Construção Matriz

matriz_campo_minado = malloc (m * sizeof (char *));

for (int i = 0 ; i < m ; i++){
	matriz_campo_minado[i] = malloc (n * sizeof (char));
}

for (int linha = 0 ; linha < m ; linha++){
	scanf("%s",matriz_campo_minado[linha]);
}

//Início análises dos caracteres

printf("Campo %d:\n",numero_campo);

//Contadores de Bombas

for (int linha = 0 ; linha < m ; linha++){
	for (int coluna = 0 ; coluna < n ; coluna++){
		int num_bomba = 0;
		if (matriz_campo_minado[linha][coluna] == '*'){
			printf("*");
			continue;
		}
		
		//Verificar se a posição é válida para comparar
 
		int pos1 = elegivel ( (linha-1) , (coluna-1) , m , n);
		int pos2 = elegivel ( (linha-1) , (coluna) , m , n);
		int pos3 = elegivel ( (linha-1) , (coluna+1) , m , n);
		int pos4 = elegivel ( (linha) , (coluna-1) , m , n);
		int pos5 = elegivel ( (linha) , (coluna+1) , m , n);
		int pos6 = elegivel ( (linha+1) , (coluna-1) , m , n);
		int pos7 = elegivel ( (linha+1) , (coluna) , m , n);
		int pos8 = elegivel ( (linha+1) , (coluna+1) , m , n);

		//Comparando posições válidas com a bomba
		//O if foi dividido em dois para não correr o risco de acessar um local indevido da memória
		
		if (pos1 == 1){ 
			if (matriz_campo_minado[linha-1][coluna-1] == '*'){
			num_bomba++;		
			}
		}
		if (pos2 == 1){
			if (matriz_campo_minado[linha-1][coluna] == '*'){
			num_bomba++;		
			}
		}
		if (pos3 == 1){
			if (matriz_campo_minado[linha-1][coluna+1] == '*'){
			num_bomba++;		
			}
		}
		if (pos4 == 1){ 
			if (matriz_campo_minado[linha][coluna-1] == '*'){
			num_bomba++;		
			}
		}
		if (pos5 == 1){ 
			if (matriz_campo_minado[linha][coluna+1] == '*'){
			num_bomba++;		
			}		
		}
		if (pos6 == 1){
			if (matriz_campo_minado[linha+1][coluna-1] == '*'){
			num_bomba++;		
			}
		}
		if (pos7 == 1){
			if (matriz_campo_minado[linha+1][coluna] == '*'){
			num_bomba++;		
			}
		}
		if (pos8 == 1){
			if (matriz_campo_minado[linha+1][coluna+1] == '*'){
			num_bomba++;		
			}
		}
		
		//Printar quantidade de bombas nas vizinhanças

		printf("%d",num_bomba);
	}
		//Pular linha para colocar quantidades de bombas da próxima linha
		
		printf("\n");   
}

//Fim da análise e quebra de linha para analisar próxima matriz

printf("\n");

//Limpar Matriz

for (int i = 0 ; i < m ; i++){
	free (matriz_campo_minado[i]);
}

free (matriz_campo_minado);

}

return 0;

}
