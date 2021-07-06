#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void receber(int *vetor, int n);
void soma(int *v_a, int *v_b, int *v_c, int n);
void exibir(int *v, int n);

int main(){
	int *v_a, *v_b, *v_c;
	int n;
	printf("Quantos elementos deseja armazenar em cada vetor? ");
	scanf("%i", &n);
	
	printf("-----Informe os valores do vetor A-----\n");
	v_a = (int *) (malloc(n * sizeof(int)));
	receber(v_a, n);

	printf("-----Informe os valores do vetor B-----\n");
	v_b = (int *) (malloc(n * sizeof(int)));
	receber(v_b, n);
	v_c = (int *) (malloc(n * sizeof(int)));
	soma(v_a, v_b, v_c, n);
	printf("-----Vetor soma----\n");
	exibir(v_c, n);

	free(v_a);
	free(v_b);
	free(v_c);
	return 0;
}

void receber(int *vetor, int n){//recebe n elementos de um vetor
	int i;
	for(i=0; i<n; i++){
		printf("Informe o número de posição %i: ", i+1);
		scanf("%i", &vetor[i]);
		//system("clear");
	}
}

void soma(int *v_a, int *v_b, int *v_c, int n){//recebe n elementos de um vetor
	int i;
	for(i=0; i<n; i++){
		v_c[i] = v_a[i] + v_b[i];
	}
}

void exibir(int *v, int n){//exibe n elementos de um vetor na tela
	int i;
	for(i=0; i<n; i++){
		printf("Posição %i: %i\n", i+1, v[i]);
	}
}