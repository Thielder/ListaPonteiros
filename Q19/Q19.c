#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <gc.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	printf("Hello");
	return 0;
}