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

	int **matriz;
	int linha, coluna;
	int i;

	printf("Quantas linhas e quantas colunas deverá existir na matriz? ");
	scanf("%i %i", &linha, &coluna);
	/*Abaixo uma matriz é alocada com a função GC_MALLOC() pertencente a biblioteca <gc.h>
	que funciona como o malloc() convencional para a realização da aloação de memória, porém
	exclui a necessidade da utilização da função free() para desalocação da memória*/
	matriz = GC_MALLOC(linha * sizeof(int*));//alocação de ponteiros para inteiros
	matriz[0] = GC_MALLOC(linha * coluna * sizeof(int));//alocação de inteiros
	for(i=1; i<linha; i++){
		matriz[i] = matriz[i-1] + coluna;
	}

	preenche(matriz, linha, coluna);
	printf("---Matriz Gerada---\n");
	exibir(matriz, linha, coluna);

	return 0;
}

void preenche(int **mat, int linha, int coluna){//preenche a matriz com números aleatórios menores do que 100
	int i = 0, j = 0;
	srand(time(NULL));
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			mat[i][j] = rand() % 100;
		}
	}
}

void exibir(int **mat, int linha, int coluna){//exibe uma matriz mxn
	int i, j;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			printf("%i ", mat[i][j]);
		}
	printf("\n");
	}
}