#include <stdio.h>

int main(){
	float PI = 3.14159265359;
	
	//Imprime com duas casas decimais
	printf("Valor de PI: %.2f\n", PI);	
	//Imprime com quatro casas decimais
	printf("Valor de PI: %.4f\n", PI);	
	//Imprime com seis casas decimais
	printf("Valor de PI: %.6f\n", PI);	
	//Imprime com oito casas decimais
	printf("Valor de PI: %.8f\n", PI);
	
	int distancia = 453;
	//Imprime com 4 digitos
	printf("Valor da distancia: %04d\n", distancia);
	
	//Imprime com 6 digitos
	printf("Valor da distancia: %06d\n", distancia);
}