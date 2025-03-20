#include <stdio.h>
#include <time.h>

int main(){	
	// Realizar um benchmark para armazenar o tempo decorrido em segundos 
	// para a contagem de 0 a 1000000	
	time_t inicio, fim;
	int diferencaTempo = 0;
	
	printf("Tempo inicial capturado.\n");
	time(&inicio);
		
	for(int i = 0; i < 100000; i++){
		printf("%d\n", i);
	}
	
	printf("\nTempo final capturado.\n");
	time(&fim);
	
	diferencaTempo = fim - inicio;
	
	printf("Duracao: %d", diferencaTempo);
	printf("\nDuracao: %f", difftime(fim, inicio));
}