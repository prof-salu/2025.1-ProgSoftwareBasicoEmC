#include <stdio.h>

int main(){
	//3. Faça um Programa que peça a temperatura em graus Fahrenheit, 
	//   transforme e mostre a temperatura em graus Celsius. 
	//   C = (5 * (F-32) / 9).
	
	float fahrenheit, celsius;
	
	printf("Informe a temperatura em FAHRENHEIT: ");
	scanf("%f", &fahrenheit);
	
	celsius = (5 * (fahrenheit - 32) / 9);
	
	printf("Temperatura convertida em CELSIUS: %.2f", celsius);
}