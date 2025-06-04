#include <stdio.h> // Necessario para a funcao printf()

int main() {
    // Define o limite superior da contagem 100.000.000.000
    const long long LIMITE = 100000000000;
    long long i; // Variavel de controle do loop (contador)

    printf("Iniciando a contagem de 1 a %lld...\n", LIMITE);
	
	printf("Processando...\n");
	
    // Loop que ira de 1 ate o LIMITE, incrementando de 1 em 1
    for (i = 1; i <= LIMITE; i++) {
        // Apenas a iteracao para simular trabalho.
    }

    printf("Contagem concluida!\n");

    return 0; // Indica que o programa terminou com sucesso
}
