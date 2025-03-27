#include <stdio.h>
#include <time.h>

int main(){
	//Escreva um programa que obtenha a data e hora atuais do sistema e 
	//as exiba no formato: “Dia/Mês/Ano Hora:Minutos:Segundos”. 
	
	time_t segundos;
	struct tm *tempo;
	
	time(&segundos);
	
	tempo = localtime(&segundos);
	
	printf("%02d/%02d/%04d %02d:%02d:%02d\n", tempo->tm_mday, 
											  tempo->tm_mon + 1,
											  tempo->tm_year + 1900,
											  tempo->tm_hour,
											  tempo->tm_min,
											  tempo->tm_sec);
}