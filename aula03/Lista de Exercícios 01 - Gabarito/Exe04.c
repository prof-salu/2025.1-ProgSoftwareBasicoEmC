#include <stdio.h>

int main(){
	//4. Faça um Programa que peça três números e imprima o maior deles.
	
	int n1, n2, n3;
	
	printf("Informe N1: ");
	scanf("%d", &n1);
	
	printf("Informe N2: ");
	scanf("%d", &n2);
	
	printf("Informe N3: ");
	scanf("%d", &n3);
	
	if(n1 >= n2 && n1 >= n3){
		printf("Maior valor: %d", n1);
	}else if (n2 >= n1 && n2 >= n3){
		printf("Maior valor: %d", n2);
	}else{
		printf("Maior valor: %d", n3);
	}
}