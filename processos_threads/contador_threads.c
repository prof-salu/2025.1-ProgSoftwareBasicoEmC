#include <windows.h> // Inclui as funções e tipos de dados da API do Windows para manipulação de threads.
#include <stdio.h>   // Inclui funções padrão de entrada/saída, como printf para imprimir na tela.
#include <stdlib.h>  // Inclui funções de alocação de memória (malloc, free) e outras utilidades gerais.

// Estrutura para DadosThread
// Define uma estrutura que será usada para passar dados específicos para cada thread.
typedef struct {
    int id;           // Identificador único para a thread (ex: Thread 1, Thread 2, etc.).
    long long inicio; // O número inicial do intervalo que esta thread deve contar.
    long long fim;    // O número final do intervalo que esta thread deve contar.
} DadosThread;

// Função que cada thread executa (Contar)
// Esta função é o ponto de entrada para cada thread recém-criada.
// DWORD WINAPI é a convenção de chamada e tipo de retorno esperados pela função CreateThread do Windows.
// LPVOID param é um ponteiro genérico que recebe os dados passados para a thread.
DWORD WINAPI Contar(LPVOID param) {
    // Converte o ponteiro genérico 'param' de volta para um ponteiro para a estrutura DadosThread.
    DadosThread *dados = (DadosThread *)param;
    long long i = dados->inicio; // Inicializa a variável de loop 'i' com o valor de início do intervalo da thread.

    printf("[ID: %d] Processando...\n", dados->id); // Imprime uma mensagem indicando que a thread começou a processar.

    // Loop principal da thread
    // Itera de 'inicio' até 'fim', simulando um trabalho que consome tempo de CPU.
    // O objetivo é apenas ocupar a CPU, sem fazer nenhuma operação complexa dentro do loop.
    for (i; i <= dados->fim; i++) {
        // Nada aqui. Apenas a iteração para simular trabalho.
    }
    
    // Libera a memória alocada dinamicamente para os dados desta thread.
    // É crucial liberar essa memória para evitar vazamentos de memória (memory leaks).
    free(dados); 
    
    return 0; // Retorna 0 para indicar que a thread terminou sua execução com sucesso.
}

// Função principal do programa (main)
// É o ponto de entrada do processo principal.
int main() {
    // Define o número total de iterações a serem realizadas, um número muito grande para simular trabalho.
    const long long TOTAL = 100000000000; 
    // Define o número de threads que serão criadas para dividir o trabalho.
    const int NUM_THREADS = 4; 
    // Um array para armazenar os handles (identificadores) das threads criadas.
    // Handles são necessários para gerenciar e esperar pelas threads.
    HANDLE handles[NUM_THREADS]; 
    
    // Imprime uma mensagem informativa sobre a tarefa a ser realizada.
    printf("Preparando contagem de 1 a %lld com %d threads...\n", TOTAL, NUM_THREADS);

    // Calcula o número de iterações que cada thread irá processar.
    long long por_thread = TOTAL / NUM_THREADS;
    // Variável para controlar o início do intervalo de cada thread.
    long long atual_inicio = 1; 
    
    int i = 0; // Variável de controle para o loop de criação de threads.
    // Loop para criar e configurar cada uma das threads.
    for (i; i < NUM_THREADS; i++) {
        // Aloca dinamicamente memória para a estrutura DadosThread.
        // Cada thread precisa de sua própria cópia de dados para evitar condições de corrida
        // e garantir que cada uma trabalhe em seu próprio intervalo.
        DadosThread *dados = (DadosThread *)malloc(sizeof(DadosThread));
        
        // Atribui o ID da thread.
        dados->id = i + 1;
        // Define o início do intervalo de contagem para a thread atual.
        dados->inicio = atual_inicio;
        // Define o fim do intervalo de contagem para a thread atual.
        dados->fim = atual_inicio + por_thread - 1;

        // Ajuste para garantir que a última thread processe o restante das iterações,
        // cobrindo qualquer sobra da divisão 'TOTAL / NUM_THREADS'.
        if (i == NUM_THREADS - 1) {
            dados->fim = TOTAL;
        }
        
        // Cria a nova thread.
        // - NULL: atributos de segurança padrão.
        // - 0: tamanho da pilha padrão.
        // - Contar: a função que a thread irá executar.
        // - dados: o ponteiro para a estrutura DadosThread que será passada para a função 'Contar'.
        // - 0: flags de criação (0 significa que a thread executa imediatamente).
        // - NULL: não estamos interessados em obter o ID da thread aqui.
        handles[i] = CreateThread(NULL, 0, Contar, dados, 0, NULL);
                
        // Atualiza o início do intervalo para a próxima thread.
        atual_inicio = dados->fim + 1;
    }

    // Espera todas as threads terminarem
    // - NUM_THREADS: número de handles no array 'handles'.
    // - handles: o array de handles das threads a serem esperadas.
    // - TRUE: significa esperar por TODOS os objetos (threads) no array.
    // - INFINITE: significa esperar indefinidamente até que todas as threads terminem.
    WaitForMultipleObjects(NUM_THREADS, handles, TRUE, INFINITE);

    // Fecha os handles das threads
    // É crucial fechar os handles das threads após elas terminarem de serem usadas
    // para liberar os recursos do sistema associados a esses handles.
    i = 0; // Reinicia o contador para o loop.
    for (i; i < NUM_THREADS; i++) {
        CloseHandle(handles[i]);
    }

    // Imprime uma mensagem indicando que todas as threads concluíram seu trabalho.
    printf("Contagem concluida por todas as threads!\n");

    return 0; // Retorna 0 para indicar que o programa principal terminou com sucesso.
}
