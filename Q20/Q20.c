#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <gc.h>//importando a biblioteca libgc
#include <time.h>

void preenche(int **mat, int linha, int coluna);
void exibir(int **mat, int linha, int coluna);

int main(){
	setlocale(LC_ALL, "Portuguese");
	GC_INIT();//iniciando o coletor

	time_t tempoGC;
	time_t tempoFree;
	int **matriz;
	int linha = 5, coluna = 5;
	int i, j;

	/*printf("Quantas linhas e quantas colunas deverá existir na matriz? ");
	scanf("%i %i", &linha, &coluna);*/
	//medição do tempo para alocação e desalocação utilizando o garbage collector
	tempoGC = clock();
	for(j=0; j<100000; j++){
		matriz = GC_MALLOC(linha * sizeof(int*));
		matriz[0] = GC_MALLOC(linha * coluna * sizeof(int));
		for(i=1; i<linha; i++){
			matriz[i] = matriz[i-1] + coluna;
		}

		preenche(matriz, linha, coluna);
		/*printf("---Matriz Gerada---\n");
		exibir(matriz, linha, coluna);*/
	}
	tempoGC = clock() - tempoGC;

	//medição de tempo para alocação e desalocação com as funções padrões da linguagem
	tempoFree = clock();
	for(j=0; j<100000; j++){
		matriz = malloc(linha * sizeof(int*));
		matriz[0] = malloc(linha * coluna * sizeof(int));
		for(i=1; i<linha; i++){
			matriz[i] = matriz[i-1] + coluna;
		}
		preenche(matriz, linha, coluna);
		/*printf("---Matriz Gerada---\n");
		exibir(matriz, linha, coluna);*/
		free(matriz);
		free(matriz[0]);
	}
	tempoFree = clock() - tempoFree;
	printf("Tempo para a execução utilizando a libgc em segundos: %lf\n", ((double)tempoGC)/CLOCKS_PER_SEC);
	printf("Tempo para a execução utilizando as funções padrão em segundos: %lf\n", ((double)tempoFree/CLOCKS_PER_SEC));
	/*É possível notar apenas uma pequena diferença neste caso, mas é possível que em programas mais complexos
	a diferença seja acentuada devido a maior dificuldade que o libgc enfrentaria em identificar quando a desalocação deve ser realizada*/
	printf("Diferença de tempo entre os dois em segundos: %lf\n", ((double)tempoGC)/CLOCKS_PER_SEC - ((double)tempoFree)/CLOCKS_PER_SEC);
	return 0;
}

//função para preencher a matriz com números aleatórios menores do que 100
void preenche(int **mat, int linha, int coluna){
	int i = 0, j = 0;
	srand(time(NULL));
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			mat[i][j] = rand() % 100;
		}
	}
}

//função para exibir a matriz na tela
void exibir(int **mat, int linha, int coluna){//exibe uma matriz mxn
	int i, j;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			printf("%i ", mat[i][j]);
		}
	printf("\n");
	}
}