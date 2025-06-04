#include <windows.h> // Funcoes da API do Windows para processos
#include <stdio.h>   // Funcoes de entrada/saida (printf)

int main() {
    STARTUPINFO si;              // Informacoes de inicializacao para o novo processo
    PROCESS_INFORMATION pi;      // Informacoes sobre o processo filho criado

    // Zera as estruturas para garantir campos limpos
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si); // Define o tamanho da estrutura STARTUPINFO
    ZeroMemory(&pi, sizeof(pi));

    // Define o comando a ser executado (ex: Bloco de Notas)
    LPCSTR cmd = "notepad.exe";

    // Tenta criar o novo processo
    if (!CreateProcess(
        NULL,            // Nao especifica o nome do aplicativo (inferido da linha de comando)
        (LPSTR)cmd,      // Linha de comando do executavel
        NULL,            // Atributos de seguranca do processo (padrao)
        NULL,            // Atributos de seguranca da thread (padrao)
        FALSE,           // Nao herda handles do processo pai
        0,               // Sem flags de criacao especiais
        NULL,            // Usa o ambiente do processo pai
        NULL,            // Usa o diretorio atual do processo pai
        &si,             // Ponteiro para a estrutura STARTUPINFO
        &pi              // Ponteiro para a estrutura PROCESS_INFORMATION
    )) {
        // Se a criacao do processo falhar, imprime o codigo de erro
        printf("Falha ao criar o processo! Codigo de erro: %lu\n", GetLastError());
        return 1; // Indica erro
    }

    // Processo filho criado com sucesso
    printf("Processo filho criado com sucesso! PID: %lu\n", pi.dwProcessId);
    printf("Thread principal do processo filho ID: %lu\n", pi.dwThreadId);

    // Opcional: espera o processo filho terminar
    // WaitForSingleObject(pi.hProcess, INFINITE);
    // printf("Processo filho terminou.\n");

    // Fecha os handles do processo e da thread para liberar recursos
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0; // Indica sucesso
}
