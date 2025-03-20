#include <stdio.h>

int main(){
	//2. Faça um Programa que pergunte quanto você ganha por hora e o 
	//   número de horas trabalhadas no mês. Calcule e mostre o total 
	//   do seu salário no referido mês.
	float valorHora, salarioMensal;
	int horasTrabalhadas;
	
	printf("Informe quanto voce ganha por hora: ");
	scanf("%f", &valorHora);
	
	printf("Informe o total de horas trabalhadas no mes: ");
	scanf("%d", &horasTrabalhadas);
	
	salarioMensal = valorHora * horasTrabalhadas;
	
	printf("Salario do mes: R$ %.2f", salarioMensal);
	
	
}