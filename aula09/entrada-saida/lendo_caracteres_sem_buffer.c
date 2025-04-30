#include<stdio.h>
#include<ctype.h>
#include<conio.h>//Funções para o console

int main(){
	char caractere;
	printf("Entre com um texto ['.' para sair]");
	
	do{
		//Le um caractere do teclado sem ecoar no console
		caractere = getch();
		if(islower(caractere)){
			//Converte para caixa alta
			caractere = toupper(caractere);
		}else{
			//Converte para caixa baixa
			caractere = tolower(caractere);
		}
		//Exibe um caractere do teclado
		putchar(caractere);
	}while(caractere != '.');
}