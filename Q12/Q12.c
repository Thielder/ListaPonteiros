#include <stdio.h>
#include <stdlib.h>

float adicao(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);

int main(){
	int oper;
	float a, b, resultado;
	float (*operacoes[4])(float, float);
	operacoes[0] = adicao;
	operacoes[1] = subtracao;
	operacoes[2] = multiplicacao;
	operacoes[3] = divisao;

	printf("1 Para somar\n2 Para subtrair\n3 Para multiplicar\n4 Para dividir\n");
	printf("Escolha a operação: ");
	scanf("%i", &oper);
	if(oper > 0 && oper < 4){
		printf("Informe o valor de a: ");
		scanf("%f", &a);
		printf("Informe o valor de b: ");
		scanf("%f", &b);
		resultado = operacoes[oper-1](a, b);
		printf("Resultado: %.2f\n", resultado);
	} else {
		printf("erro!");
	}
	return 0;
}

float adicao(float a, float b){
	return a + b;
}

float subtracao(float a, float b){
	return a - b;
}

float divisao(float a, float b){
	return a * b;
}

float multiplicacao(float a, float b){
	return a / b;
}