#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *arquivo;
	char texto[100];
	
	arquivo = fopen("nome_arquivo.txt", "r");
	
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}else{
		printf("Conteudo do arquivo: \n");
		while(fgets(texto, sizeof(texto), arquivo) != NULL){
			printf("%s", texto);
		}
		
		fclose(arquivo);
		
		printf("Fim do arquivo!");		
	}
}