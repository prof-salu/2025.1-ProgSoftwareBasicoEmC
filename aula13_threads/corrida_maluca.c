#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct{
	char nome[100];
	double velocidade;
	double distanciaCircuito;
	double distanciaPercorrida;
}Piloto;

DWORD WINAPI thread_piloto(LPVOID param){
	Piloto* piloto = (Piloto*) param;
	
	while(piloto->distanciaPercorrida 
							<= piloto->distanciaCircuito){
								
		piloto->distanciaPercorrida += piloto->velocidade;
		
		printf("%s esta no km %.2f\n", piloto->nome, 
									   piloto->distanciaPercorrida);
		Sleep(100);//Coloca a thread para dormir "PAUSE" (milisegundos)		
	}
	
	printf("%s ********TERMINOU********\n", piloto->nome);
}

int main(){
	int tamanhoCircuito = 30;
	//Criando os pilotos {nome, velocidade, circuito, posicao}
	Piloto p1 = {"Jonin", 1.1, tamanhoCircuito, 0.0};
	Piloto p2 = {"Gigi", 1.2, tamanhoCircuito, 0.0};
	Piloto p3 = {"Gabi", 1.3, tamanhoCircuito, 0.0};
	Piloto p4 = {"Juca", 1.0, tamanhoCircuito, 0.0};
	Piloto p5 = {"Harry", 1.2, tamanhoCircuito, 0.0};
	
	HANDLE threads[5];//Vetor de threads
	//Criando a thread que representa cada piloto
	threads[0] = CreateThread(NULL, 0, thread_piloto, &p1, 0, NULL);
	threads[1] = CreateThread(NULL, 0, thread_piloto, &p2, 0, NULL);
	threads[2] = CreateThread(NULL, 0, thread_piloto, &p3, 0, NULL);
	threads[3] = CreateThread(NULL, 0, thread_piloto, &p4, 0, NULL);
	threads[4] = CreateThread(NULL, 0, thread_piloto, &p5, 0, NULL);
	//Aguarda todas as threads terminarem
	WaitForMultipleObjects(5, threads, TRUE, INFINITE);
	
	//Libera os recursos utilizados  pelas threads
	for(int i = 0; i < 5; i++){
		CloseHandle(threads[i]);
	}
	printf("FIM DA CORRIDA!\n");
}



