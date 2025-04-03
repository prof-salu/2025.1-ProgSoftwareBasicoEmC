#include <stdio.h>
#include <time.h>

// Função para obter o nome do dia da semana
const char* obterDiaSemana(int diaSemana) {
    const char* dias[] = {
        "Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", 
        "Quinta-feira", "Sexta-feira", "Sábado"
    };
    return dias[diaSemana];
}

int main() {
    char dataStr[11];
    struct tm data = {0};

    // Entrada da data
    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%10s", dataStr);
    sscanf(dataStr, "%d/%d/%d", &data.tm_mday, &data.tm_mon, &data.tm_year);

    // Ajusta para o formato do struct tm
    data.tm_year -= 1900; // Ano desde 1900
    data.tm_mon -= 1;     // Mês no formato 0-11

    // Converte para timestamp
    if (mktime(&data) == -1) {
        printf("Erro ao calcular o dia da semana!\n");
        return 1;
    }

    // Obtem o dia da semana
    int diaSemana = data.tm_wday; // 0 = Domingo, 6 = Sábado
    printf("O dia da semana correspondente é: %s\n", obterDiaSemana(diaSemana));

    return 0;
}
