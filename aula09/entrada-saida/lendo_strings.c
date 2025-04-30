#include <stdio.h>
#include <string.h>
//char[5] ==> ['c', 'a', 's', 'a', '\0']
int main(){
	char texto[50];
	printf("Digite um texto: ");
	
	fgets(texto, sizeof(texto), stdin);
	
	printf("Tamanho: %d\n", strlen(texto)-1);
	printf("Texto digitado: %s", texto);
}