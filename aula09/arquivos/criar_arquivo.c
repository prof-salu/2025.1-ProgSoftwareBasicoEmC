#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declara um ponteiro para o arquivo
	FILE *arquivo;
	char texto[] = "Mensagem que sera gravada no arquivo.\n";
	
	//modo de operacao
	//w --> abre o arquivo para escrita
	//r --> abre o arquivo apenas para leitura
	
	//arquivo = fopen("C:\\\\teste\\\\nome_arquivo.txt", "w");
	arquivo = fopen("nome_arquivo.txt", "a");
		
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo!");
		exit(1);//Encerra o programa
	}else{
		//Escrevendo dentro do arquivo
		int i = 1;
		for (i; i < 10;i++){
			fprintf(arquivo, "%s", texto);
		}		
		//**fecha o arquivo**
		fclose(arquivo);
		printf("Arquivo criado com sucesso!");
	}
}