#include <windows.h> // Inclui as fun��es e tipos de dados da API do Windows para manipula��o de threads.
#include <stdio.h>   // Inclui fun��es padr�o de entrada/sa�da, como printf para imprimir na tela.
#include <stdlib.h>  // Inclui fun��es de aloca��o de mem�ria (malloc, free) e outras utilidades gerais.

// Estrutura para DadosThread
// Define uma estrutura que ser� usada para passar dados espec�ficos para cada thread.
typedef struct {
    int id;           // Identificador �nico para a thread (ex: Thread 1, Thread 2, etc.).
    long long inicio; // O n�mero inicial do intervalo que esta thread deve contar.
    long long fim;    // O n�mero final do intervalo que esta thread deve contar.
} DadosThread;

// Fun��o que cada thread executa (Contar)
// Esta fun��o � o ponto de entrada para cada thread rec�m-criada.
// DWORD WINAPI � a conven��o de chamada e tipo de retorno esperados pela fun��o CreateThread do Windows.
// LPVOID param � um ponteiro gen�rico que recebe os dados passados para a thread.
DWORD WINAPI Contar(LPVOID param) {
    // Converte o ponteiro gen�rico 'param' de volta para um ponteiro para a estrutura DadosThread.
    DadosThread *dados = (DadosThread *)param;
    long long i = dados->inicio; // Inicializa a vari�vel de loop 'i' com o valor de in�cio do intervalo da thread.

    printf("[ID: %d] Processando...\n", dados->id); // Imprime uma mensagem indicando que a thread come�ou a processar.

    // Loop principal da thread
    // Itera de 'inicio' at� 'fim', simulando um trabalho que consome tempo de CPU.
    // O objetivo � apenas ocupar a CPU, sem fazer nenhuma opera��o complexa dentro do loop.
    for (i; i <= dados->fim; i++) {
        // Nada aqui. Apenas a itera��o para simular trabalho.
    }
    
    // Libera a mem�ria alocada dinamicamente para os dados desta thread.
    // � crucial liberar essa mem�ria para evitar vazamentos de mem�ria (memory leaks).
    free(dados); 
    
    return 0; // Retorna 0 para indicar que a thread terminou sua execu��o com sucesso.
}

// Fun��o principal do programa (main)
// � o ponto de entrada do processo principal.
int main() {
    // Define o n�mero total de itera��es a serem realizadas, um n�mero muito grande para simular trabalho.
    const long long TOTAL = 100000000000; 
    // Define o n�mero de threads que ser�o criadas para dividir o trabalho.
    const int NUM_THREADS = 4; 
    // Um array para armazenar os handles (identificadores) das threads criadas.
    // Handles s�o necess�rios para gerenciar e esperar pelas threads.
    HANDLE handles[NUM_THREADS]; 
    
    // Imprime uma mensagem informativa sobre a tarefa a ser realizada.
    printf("Preparando contagem de 1 a %lld com %d threads...\n", TOTAL, NUM_THREADS);

    // Calcula o n�mero de itera��es que cada thread ir� processar.
    long long por_thread = TOTAL / NUM_THREADS;
    // Vari�vel para controlar o in�cio do intervalo de cada thread.
    long long atual_inicio = 1; 
    
    int i = 0; // Vari�vel de controle para o loop de cria��o de threads.
    // Loop para criar e configurar cada uma das threads.
    for (i; i < NUM_THREADS; i++) {
        // Aloca dinamicamente mem�ria para a estrutura DadosThread.
        // Cada thread precisa de sua pr�pria c�pia de dados para evitar condi��es de corrida
        // e garantir que cada uma trabalhe em seu pr�prio intervalo.
        DadosThread *dados = (DadosThread *)malloc(sizeof(DadosThread));
        
        // Atribui o ID da thread.
        dados->id = i + 1;
        // Define o in�cio do intervalo de contagem para a thread atual.
        dados->inicio = atual_inicio;
        // Define o fim do intervalo de contagem para a thread atual.
        dados->fim = atual_inicio + por_thread - 1;

        // Ajuste para garantir que a �ltima thread processe o restante das itera��es,
        // cobrindo qualquer sobra da divis�o 'TOTAL / NUM_THREADS'.
        if (i == NUM_THREADS - 1) {
            dados->fim = TOTAL;
        }
        
        // Cria a nova thread.
        // - NULL: atributos de seguran�a padr�o.
        // - 0: tamanho da pilha padr�o.
        // - Contar: a fun��o que a thread ir� executar.
        // - dados: o ponteiro para a estrutura DadosThread que ser� passada para a fun��o 'Contar'.
        // - 0: flags de cria��o (0 significa que a thread executa imediatamente).
        // - NULL: n�o estamos interessados em obter o ID da thread aqui.
        handles[i] = CreateThread(NULL, 0, Contar, dados, 0, NULL);
                
        // Atualiza o in�cio do intervalo para a pr�xima thread.
        atual_inicio = dados->fim + 1;
    }

    // Espera todas as threads terminarem
    // - NUM_THREADS: n�mero de handles no array 'handles'.
    // - handles: o array de handles das threads a serem esperadas.
    // - TRUE: significa esperar por TODOS os objetos (threads) no array.
    // - INFINITE: significa esperar indefinidamente at� que todas as threads terminem.
    WaitForMultipleObjects(NUM_THREADS, handles, TRUE, INFINITE);

    // Fecha os handles das threads
    // � crucial fechar os handles das threads ap�s elas terminarem de serem usadas
    // para liberar os recursos do sistema associados a esses handles.
    i = 0; // Reinicia o contador para o loop.
    for (i; i < NUM_THREADS; i++) {
        CloseHandle(handles[i]);
    }

    // Imprime uma mensagem indicando que todas as threads conclu�ram seu trabalho.
    printf("Contagem concluida por todas as threads!\n");

    return 0; // Retorna 0 para indicar que o programa principal terminou com sucesso.
}
