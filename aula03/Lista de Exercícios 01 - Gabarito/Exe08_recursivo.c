#include <stdio.h>

long long int fatorial(int numero){
	if(numero == 0 || numero == 1){
		return 1;
	}
	
	return numero * fatorial(numero - 1);
}


int main(){
	//8. Crie um programa que tenha uma função fatorial(), que receba um
	//   parâmetro inteiro e retorne o valor do fatorial desse número.
	int numero;
	printf("Informe o valor do fatorial: ");
	scanf("%d", &numero);
	
	printf("Fatorial: %lld", fatorial(numero));
	
}