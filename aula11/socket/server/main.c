#include <stdio.h>
#include <winsock2.h> // Cabecalho principal do Winsock
#include <ws2tcpip.h> // Necessario para inet_ntop e INET_ADDRSTRLEN
#include <process.h>  // Necessario para _beginthreadex
#include <stdlib.h> // Para malloc e free
#include <string.h> // Para memset

#pragma comment(lib, "ws2_32.lib") // Linka a biblioteca Winsock 2

#define PORTA 12345
#define BUFFER_SIZE 1024

//parameter project --> -lws2_32

// Estrutura para passar o socket do cliente para o thread
struct ClientSocketInfo {
    SOCKET cliente_socket;
    struct sockaddr_in cliente_endereco;
};

// Funcao que sera executada por cada thread de cliente
unsigned __stdcall verificaCliente(void* arg) {
    struct ClientSocketInfo *cliente_info = (struct ClientSocketInfo *)arg;
    SOCKET cliente_socket = cliente_info->cliente_socket;
    struct sockaddr_in cliente_endereco = cliente_info->cliente_endereco;

    char buffer[BUFFER_SIZE];
    int bytes_recebidos;

    // Converter IP para formato legivel para impressao no thread
    char cliente_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(cliente_endereco.sin_addr), cliente_ip, INET_ADDRSTRLEN);
    unsigned short cliente_porta = ntohs(cliente_endereco.sin_port);

    printf("Thread %lu: Iniciado para cliente %s:%d\n", GetCurrentThreadId(), cliente_ip, cliente_porta);

    // Loop para receber MULTIPLAS mensagens deste cliente
    while (1) {
        memset(buffer, 0, BUFFER_SIZE); // Limpa o buffer
        bytes_recebidos = recv(cliente_socket, buffer, BUFFER_SIZE - 1, 0);

        if (bytes_recebidos > 0) {
            buffer[bytes_recebidos] = '\0'; // Garante terminacao nula
            printf("Thread %lu: Mensagem de %s:%d: %s\n", GetCurrentThreadId(), cliente_ip, cliente_porta, buffer);
        } else if (bytes_recebidos == 0) {
            printf("Thread %lu: Cliente %s:%d desconectado.\n", GetCurrentThreadId(), cliente_ip, cliente_porta);
            break; // Sai do loop se o cliente desconectar
        } else {
            // Erro no recv (ignorado para simplificacao, mas printado)
            printf("Thread %lu: Erro no recv do cliente %s:%d. Codigo de erro: %d\n", GetCurrentThreadId(), cliente_ip, cliente_porta, WSAGetLastError());
            break;
        }
    }

    // Fechar o socket especifico deste cliente e liberar a memoria da estrutura
    closesocket(cliente_socket);
    free(cliente_info); // Liberar memoria alocada no thread principal

    printf("Thread %lu: Finalizado para cliente %s:%d\n", GetCurrentThreadId(), cliente_ip, cliente_porta);

    _endthreadex(0); // Termina o thread corretamente
    return 0; // Retorno formal (na pratica _endthreadex é chamado)
}


int main() {
    WSADATA wsaData;
    SOCKET server_socket;
    struct sockaddr_in server_endereco;
    int cliente_tamanho_endereco;

    // 1. Inicializar o Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Erro ao inicializar o Winsock. Codigo de erro: %d\n", WSAGetLastError());
        return 1;
    }

    // 2. Criar socket do servidor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_endereco.sin_family = AF_INET;
    server_endereco.sin_addr.s_addr = INADDR_ANY; // Escuta em qualquer IP
    server_endereco.sin_port = htons(PORTA);

    // 3. Vincular socket
    bind(server_socket, (struct sockaddr *)&server_endereco, sizeof(server_endereco));

    // 4. Comecar a escutar (fila de ate 5 conexoes pendentes)
    listen(server_socket, 5);

    printf("Servidor multi-threaded Winsock aguardando conexoes na porta %d...\n", PORTA);

    // Loop infinito para aceitar novas conexoes
    while (1) {
        struct ClientSocketInfo *cliente_info = (struct ClientSocketInfo *)malloc(sizeof(struct ClientSocketInfo));
        cliente_tamanho_endereco = sizeof(cliente_info->cliente_endereco);

        // 5. Aceitar uma nova conexao
        cliente_info->cliente_socket = accept(server_socket, (struct sockaddr *)&(cliente_info->cliente_endereco), &cliente_tamanho_endereco);

        if (cliente_info->cliente_socket == INVALID_SOCKET) {
            printf("Erro ao aceitar conexao. Codigo de erro: %d\n", WSAGetLastError());
            free(cliente_info); // Libera a memoria se accept falhar
            continue; // Volta para aguardar a proxima conexao
        }

        // 6. Criar um novo thread para lidar com este cliente
        _beginthreadex(NULL, 0, &verificaCliente, (void*)cliente_info, 0, NULL);
    }
    return 0;
}
