#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//protótipo das funções
void exibir(float *vetor, int n);
void receber(float *vetor, int n);
int comparar(const void *a, const void *b);

int main(){
	setlocale(LC_ALL, "Portuguese");
	time_t tempo;
	int n;
	float *vetor;
	
	/*recebendo quantos elementos terá o vetor
	printf("Quantos números deseja informar? ");
	scanf("%i", &n);*/
	n = 100000;//substituindo por uma quantidade fixa e alta para questão de testes rápidos

	//alocando a memória e recebendo os elementos do vetor
	vetor = malloc(n * sizeof(float));
	receber(vetor, n);
	
	//exibindo na ordem original
	printf("----Números na ordem em que foram informados----\n");
	exibir(vetor, n);
	
	tempo = clock();//inicio da contagem
	//ordenando vetor com qsort
	qsort(vetor, n, sizeof(float), comparar);
	tempo = clock();//fim da contagem
	printf("O tempo de execução da função qsort em milisegundos é %lf\n", ((double)tempo)/(CLOCKS_PER_SEC));
	getchar();

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
	srand(time(NULL));
	for(i=0; i<n; i++){
		/*printf("Informe o número de posição %i: ", i+1);
		scanf("%f", &vetor[i]);
		system("clear");*/
		vetor[i] = (rand() % 100000 * 0.01);
	}
}

int comparar(const void *a, const void *b){//ordena o vetor em ordem crescente
	if(*(float *)a > *(float *)b){
		return 1;
	} else {
		return 0;
	}
}