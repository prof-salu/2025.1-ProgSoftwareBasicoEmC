#include <stdio.h>

int main(){
	//5. Faça um Programa que verifique se uma letra digitada é 
	//   vogal ou consoante.
	
	char letra;
	
	printf("Informe uma letra: ");
	scanf("%c", &letra);
	
	if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || 
		letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' ||
		letra == 'O' || letra == 'U'){
			printf("A letra informada e uma vogal");
		}else{
			printf("A letra informada e uma consoante");
		}

}