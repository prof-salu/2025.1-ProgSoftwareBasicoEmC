#include <stdio.h>
#include <time.h>

// Função para converter uma data no formato Dia/Mês/Ano em um struct tm
struct tm stringParaData(const char *dataStr) {
    struct tm data = {0};
    sscanf(dataStr, "%d/%d/%d", &data.tm_mday, &data.tm_mon, &data.tm_year);
    data.tm_year -= 1900; // Ajusta o ano para o formato do struct tm
    data.tm_mon -= 1;     // Ajusta o mês para o formato do struct tm (0-11)
    return data;
}

int main() {
    char data1Str[11], data2Str[11];
    printf("Digite a primeira data (dd/mm/aaaa): ");
    scanf("%10s", data1Str);
    printf("Digite a segunda data (dd/mm/aaaa): ");
    scanf("%10s", data2Str);

    struct tm data1 = stringParaData(data1Str);
    struct tm data2 = stringParaData(data2Str);

    // Converte para timestamps (segundos desde 01/01/1970)
    time_t timestamp1 = mktime(&data1);
    time_t timestamp2 = mktime(&data2);

    // Calcula a diferença em segundos e converte para dias
    double diferencaSegundos = difftime(timestamp2, timestamp1);
    int diferencaDias = diferencaSegundos / (60 * 60 * 24);

    printf("A diferenca em dias entre as duas datas é: %d dias\n", abs(diferencaDias));

    return 0;
}
