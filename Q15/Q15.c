#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//protótipo das funções
void exibir(float *vetor, int n);
void receber(float *vetor, int n);
int comparar(float *a, float *b);
void ordenar(float *vetor, int n, int (*comparar)(float *, float *));

int main(){
	setlocale(LC_ALL, "Portuguese");
	int n;
	float *vetor;
	//recebendo quantos elementos terá o vetor
	printf("Quantos números deseja informar? ");
	scanf("%i", &n);
	//alocando a memória e recebendo os elementos do vetor
	vetor = malloc(n * sizeof(float));
	receber(vetor, n);
	//exibindo na ordem original
	printf("----Números na ordem em que foram informados----\n");
	exibir(vetor, n);
	//ordenando vetor com qsort
	ordenar(vetor, n, comparar);
	//exibindo na ordem crescente
	printf("----Números na ordem crescente----\n");
	exibir(vetor, n);
	
	free(vetor);
	return 0;
}

void exibir(float *vetor, int n){//exibe n elementos de um vetor na tela
	int i;
	for(i=0; i<n; i++){
		printf("Posição %i: %.2f\n", i+1, vetor[i]);
	}
}

void receber(float *vetor, int n){//recebe n elementos de um vetor
	int i;
	for(i=0; i<n; i++){
		printf("Informe o número de posição %i: ", i+1);
		scanf("%f", &vetor[i]);
		system("clear");
	}
}

int comparar(float *a, float *b){//ordena o vetor em ordem crescente
	if(*a < *b){
		return 1;
	} else {
		return 0;
	}
}

void ordenar(float *vetor, int n, int (*comparar)(float *, float *)){//ordena o vetor em ordem crescente
	int i, j;
	float aux;
	for(i=0; i<n; i++){
		aux = vetor[i];
		for(j=0; j<n; j++){
			if(comparar(&vetor[i], &vetor[j])){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}