#include <stdio.h>
#include <time.h>

int main(){
	time_t agora;//armazena o valor em segundos
	struct tm *data_hora_atual; //struct armazena uma data dd/mm/yyyy hh:mm:ss
	char tempo[80];//armazena
	
	time(&agora);
	//Convertendo de segundos para o tempo local
	
	data_hora_atual = localtime(&agora);
	//Mascaras de data e tempo
	//https://docs.oracle.com/cd/E23389_01/doc.11116/e21038/timeformat.htm
	strftime(tempo, 80, "Data e Hora: %d/%m/%Y (%a) %H:%M:%S", data_hora_atual);
	
	printf("%s\n", tempo);
	
}