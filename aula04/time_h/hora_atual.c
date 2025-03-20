#include <stdio.h>
#include <time.h>

int main(){
	//scruct que armazena o time no formato dd/mm/yyyy hh:mm:ss
	time_t agora;	
	
	//Função que captura o tempo em segundos, baseado no epoch time (01/01/1970)
	time(&agora);
	
	printf("Tempo atual (segundos): %d\n", agora);
	printf("Hora atual: %s", ctime(&agora));
}