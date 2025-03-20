#include <stdio.h>
#include <time.h>

int main(){
	time_t agora;
	
	struct tm * data_hora_atual;
	
	time(&agora);
	
	//Convertendo de segundos para o tempo local
	data_hora_atual = localtime(&agora);
	
	//struct tm
	//https://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html
	
	
	printf("Dia do mes: %d\n", data_hora_atual->tm_mday);
	printf("Mes: %d\n", data_hora_atual->tm_mon+1);
	printf("Ano: %d\n", data_hora_atual->tm_year + 1900);
	printf("Dia da semana: %d\n", data_hora_atual->tm_wday);
	printf("Dia do ano: %d\n", data_hora_atual->tm_yday+1);
	
	printf("Horas: %d\n", data_hora_atual->tm_hour);
	printf("Minutos: %d\n", data_hora_atual->tm_min);
	printf("Segundos: %d\n", data_hora_atual->tm_sec);
}