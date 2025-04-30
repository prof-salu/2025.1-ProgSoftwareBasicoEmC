#include <stdio.h>
#include <string.h>
int main(){
	char texto[100];	
	//Copia a string para a variavel texto
	strcpy(texto, "Copiando dados para uma string");
	//Imprime a string e adiciona uma quebra de linha
	puts(texto);
}