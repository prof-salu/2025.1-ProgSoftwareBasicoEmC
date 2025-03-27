#include <stdio.h>
#include <time.h>

int main(){
	//Crie um programa que meça o tempo decorrido entre dois pontos de 
	//execução do código. Pesquise sobre a função clock() para obter o 
	//tempo em ticks de clock e calcule o tempo em segundos.
	
	clock_t inicio, fim;
	float tempoDecorrido;
	
	inicio = clock();
	
	for(int i = 0; i  < 1000000; i++){
		printf("%d ", i);
	}
	
	fim = clock();
	
	tempoDecorrido = (fim - inicio) / CLOCKS_PER_SEC;
	
	printf("\nTempo decorrido: %.2f", tempoDecorrido);
}