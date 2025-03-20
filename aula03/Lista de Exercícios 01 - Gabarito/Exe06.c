#include <stdio.h>
#include <string.h>

int main(){
	//6. Faça um programa que leia e valide as seguintes informações:
			// Nome: maior que 3 caracteres;
			// Idade: entre 0 e 150;
			// Salário: maior que zero;
			// Sexo: 'f' ou 'm';
			// Estado Civil: 's', 'c', 'v', 'd';
    char nome[100];
    int idade;
    float salario;
    char sexo, estadoCivil;
    
    
	//Capturar e validar o nome			
	do{
		printf("Informe o seu nome: ");
		scanf("%s", &nome);
	}while(strlen(nome) <= 3);
	
	//Capturar e validar a idade
	do{
		printf("Informe a sua idade: ");
		scanf("%d", &idade);
	}while(idade < 0 || idade > 150);
	
	//Capturar e validar o salario
	do{
		printf("Informe o seu salario: ");
		scanf("%f", &salario);
	}while(salario <= 0);
	
	//Capturar e validar o sexo
	do{
		printf("Informe o sexo: ");
		scanf(" %c", &sexo);
	}while(sexo != 'f' && sexo != 'm'&& sexo != 'F' && sexo != 'M');
	
	//Capturar e validar o estado civil
	do{
		printf("Informe o estado civil: ");
		scanf(" %c", &estadoCivil);
	}while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v'
	       && estadoCivil != 'd');
	
	
	printf("Dados cadastrados com sucesso!\n");
	printf("\nNome: %s", nome);
	printf("\nIdade: %d", idade);
	printf("\nSalario: R$ %.2f", salario);
	printf("\nSexo: %c", sexo);
	printf("Estado civil: %c", estadoCivil);	
}