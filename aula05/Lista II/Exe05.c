#include <stdio.h>
#include <time.h>
#include <conio.h> 


//Desenvolva um programa que simule um cronômetro. O programa deve iniciar a contagem do tempo quando o usuário pressionar uma tecla e parar quando outra tecla for pressionada. Exiba o tempo decorrido no formato “Minutos:Segundos”. 
int main() {
    char tecla;
    time_t inicio, fim;
    double tempoDecorrido;

    printf("Pressione qualquer tecla para iniciar o cronometro...\n");
    getch(); // Aguarda o pressionamento de uma tecla
    time(&inicio); // Obtem o tempo inicial

    printf("Cronometro iniciado! Pressione qualquer tecla para parar...\n");
    
    getch(); // Captura o pressionamento da tecla para interromper
    time(&fim); // Obtem o tempo final

    // Calcula o tempo decorrido em segundos
    tempoDecorrido = difftime(fim, inicio);

    // Exibe o tempo no formato Minutos:Segundos
    int minutos = (int)tempoDecorrido / 60;
    int segundos = (int)tempoDecorrido % 60;
    printf("Tempo decorrido: %02d:%02d\n", minutos, segundos);

    return 0;
}
