#include <stdio.h>

void converteHorario(int hora24, int minuto, int *hora12, char *periodo){
	if(hora24 == 0){
		*hora12 = 12;
		*periodo = 'A';
	}else if(hora24 == 12){
		*hora12 = 12;
		*periodo = 'P';
	}else if(hora24 > 12){
		*hora12 = hora24 - 12;
		*periodo = 'P';
	}else{
		*hora12 = hora24;
		*periodo = 'A';
	}
}

void exibeHora(int hora12, int minuto, char periodo){
	printf("Horario: %02d:%02d %c", hora12, minuto, periodo);
}

int main(){
	//9. Faça um programa que converta da notação de 24 horas para a notação de
	//	 12 horas. Por exemplo, o programa deve converter 14:25 em 2:25 P.M. A
	//	 entrada é dada em dois inteiros. Deve haver pelo menos duas funções: uma
	//	 para fazer a conversão e uma para a saída. Registre a informação A.M./P.M.
	//	 como um valor ‘A’ para A.M. e ‘P’ para P.M. Assim, a função para efetuar as
	//	 conversões terá um parâmetro formal para registrar se é A.M. ou P.M.
	int hora24 = 23;
	int minuto = 7;
	int hora12;
	char periodo;
	
	converteHorario(hora24, minuto, &hora12, &periodo);
	
	exibeHora(hora12, minuto, periodo);
}