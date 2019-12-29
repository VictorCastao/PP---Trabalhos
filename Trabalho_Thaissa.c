#include <stdio.h>
#include <string.h>


void fun1(char st[128], char vetdif[1000][128], char vetig[1000][128], int N) {
	int i, cont = 0; //posição da string no vetor
	for(i = 0; i <= N; i++) {
		if (strcmp (st, vetdif[i]) == 0) {
			strcpy (vetig[cont], vetdif[1000][128]);
			cont++;
			strcpy (vetdif[i], "");
		}
		else {
			strcpy(vetdif[i], st);		
		}
	}
}



int main() {
	int N, i;
	char st[128];
	char dif[1000][128];
	char ig[1000][128];
	
	do{
		scanf("%d", &N);
		for(i = 1; i <= N; i++) {
			scanf ("%s", st);
		}
	}
}












	}
	while (N > 0 && N <= 1000);
	return 0;	
}
