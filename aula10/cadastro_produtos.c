#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Criar um arquivo.txt para cadastrar produtos (nome, preço)

//CONSTANTES
#define NOME_TAMANHO 50
#define NOME_ARQUIVO "produtos.txt"

//Estrutura para o produto
typedef struct{
	char nome[NOME_TAMANHO];
	float preco;
}Produto;

void cadastrar(FILE *arquivo){
	Produto novo;
	printf("\n--NOVO PRODUTO--\n");
	printf("Nome: ");
	//limita a entrada de dados a 49 caracteres.
	scanf(" %49[^\n]", novo.nome);
	printf("Preco: ");
	scanf("%f", &novo.preco);
	
	//GRAVANDO NO ARQUIVO fprintf
	fprintf(arquivo, 
			"Produto: %s, Preco: %.2f\n", 
			novo.nome, 
			novo.preco);
	
	printf("\nProduto cadastrado!\n");
}

void listar(FILE *arquivo){
	printf("\n--LISTA DE PRODUTOS--\n");
	char linha[100];//armazena os dados de cada linha do arquivo
	
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		printf("%s", linha);
	}
}

int main(){
	int opcao;
	FILE *arquivo;
	//Tenta abrir/criar o arquivo
	
	//a+ permite adicionar ao final do arquivo e ler o conteduo
	arquivo = fopen(NOME_ARQUIVO, "a+");
	
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo");
		return 1;//Retorna 1 para indicar que o programa terminou com erro
	}
	
	do{
		printf("\n-- Menu de cadastro de produtos --\n");
		printf("\t1- Cadastrar\n");
		printf("\t2- Listar\n");
		printf("\t0- Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				cadastrar(arquivo);
				break;
			case 2:
				listar(arquivo);
				break;
			case 0:
				printf("Saindo do programa");
				break;
			default:
				printf("Opcao invalida.");
		}
		
	}while(opcao != 0);
	
	//FECHANDO O ARQUIVO
	fclose(arquivo);
}
