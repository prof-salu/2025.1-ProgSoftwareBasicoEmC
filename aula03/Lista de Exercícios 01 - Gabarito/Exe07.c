#include <stdio.h>

int main(){
	//7. Faça um Programa que leia um vetor de 5 números inteiros, 
	//   mostre a soma, a multiplicação e os números.
	
	int numeros[5];
	int soma = 0;
	int multiplicacao = 1;
	
	printf("Informe o 5 numeros inteiros: \n");
	for(int i = 0; i < 5; i++){
		printf("N%d: ", i+1);
		scanf("%d", &numeros[i]);
	}
	
	//Calcula a soma e a multiplicacao dos elementos
	for(int i = 0; i < 5; i++){
		soma += numeros[i];
		multiplicacao *= numeros[i];		
	}
	
	printf("Soma: %d", soma);
	printf("\nMultiplicacao: %d", multiplicacao);
	printf("\nElementos: ");
	for(int i = 0; i < 5; i++){
		printf("%d ", numeros[i]);
	}
}