#include <stdio.h>

int main(){
	//1. Faça um Programa que peça as 4 notas bimestrais e 
	//   mostre a media.
	
	float n1, n2, n3, n4, media;
	
	printf("Informe a nota 01: ");
	scanf("%f", &n1);
	
	printf("Informe a nota 02: ");
	scanf("%f", &n2);
	
	printf("Informe a nota 03: ");
	scanf("%f", &n3);
	
	printf("Informe a nota 04: ");
	scanf("%f", &n4);
	
	media = (n1 + n2 + n3 + n4) / 4;
	
	printf("Media do aluno: %.2f", media);
}