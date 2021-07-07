#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void recebe(int **mat, int row, int Col);
void multi(int **m_a, int **m_b, int **m_c, int rowA, int ColArowB,int ColB);
void exibir(int **mat, int row, int Col);

int main(){
	setlocale(LC_ALL, "Portuguese");
	int **m_a, **m_b, **m_r;
	int rowA = 0, ColArowB = 0, ColB = 0;
	int i = 0; 

	//recebendo linhas e colunas
	printf("Quantas linhas para a matriz A? ");
	scanf("%i", &rowA);
	printf("Quantas colunas para a matriz A e linhas para a matriz B? ");
	scanf("%i", &ColArowB);
	printf("Quantas colunas para a matriz B? ");
	scanf("%i", &ColB);

	//alocações das matrizes
	//matriz A
	m_a = malloc(rowA * sizeof(int*));
	m_a[0] = malloc(ColArowB * rowA * sizeof(int));
	for(i=1; i<rowA; i++){
		m_a[i] = m_a[i - 1] + ColArowB;
	}
	//matriz B
	m_b = malloc(ColArowB * sizeof(int*));
	m_b[0] = malloc(ColArowB * ColB * sizeof(int));
	for(i=1; i<ColArowB; i++){
		m_b[i] = m_b[i - 1] + ColB;
	}
	//matriz R
	m_r = malloc(rowA * sizeof(int*));
	m_r[0] = malloc(rowA * ColB * sizeof(int));
	for(i=1; i<rowA; i++){
		m_r[i] = m_r[i - 1] + ColB;
	}

	//recebendo os valores das matrizes A e B
	printf("---Matriz A---\n");
	recebe(m_a, rowA, ColArowB);
	printf("---Matriz B---\n");
	recebe(m_b, ColArowB, ColB);

	system("clear");
	//exibir matrizes A e B
	printf("---Matriz A---\n");
	exibir(m_a, rowA, ColArowB);
	printf("---Matriz B---\n");
	exibir(m_b, ColArowB, ColB);

	//resultado final
	printf("---Matriz AB---\n");
	multi(m_a, m_b, m_r, rowA, ColArowB, ColB);
	exibir(m_r, rowA, ColB);

	free(m_a[0]);
	free(m_a);
	free(m_b[0]);
	free(m_b);
	free(m_r[0]);
	free(m_r);
	return 0;
}

void recebe(int **mat, int row, int Col){
	int i = 0, j = 0;
	for(i=0; i<row; i++){
		for(j=0; j<Col; j++){
			printf("informe o valor para a posição %i x %i: ", i+1, j+1);
			scanf("%i", &mat[i][j]);
		}
	}
}

void multi(int **m_a, int **m_b, int **m_r, int rowA, int ColArowB, int ColB){
	int i, j, k, aux, cont = 0;
	for(i=0; i<rowA; i++){
		for(j=0; j<ColB; j++){
			aux = 0;
			for(k=0; k<ColArowB; k++){
				aux = aux + (m_a[i][k] * m_b[k][j]);
			}
			m_r[i][j] = aux;
		}
	}
}

void exibir(int **mat, int row, int Col){//exibe uma matriz mxn
	int i, j;
	for(i=0; i<rowA; i++){
		for(j=0; j<Col; j++){
			printf("%i ", mat[i][j]);
		}
	printf("\n");
	}
}