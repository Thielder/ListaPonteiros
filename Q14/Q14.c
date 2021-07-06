#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//protótipo das funções
void exibir(float *vetor, int n);
void receber(float *vetor, int n);
int comparar(const void *a, const void *b);

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
	qsort(vetor, n, sizeof(float), comparar);
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

int comparar(const void *a, const void *b){//ordena o vetor em ordem crescente
	if(*(float *)a > *(float *)b){
		return 1;
	} else {
		return 0;
	}
}