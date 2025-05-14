#include <stdio.h>
#include <string.h> // Para strlen, strcmp, strcspn
#include <winsock2.h> // Cabecalho principal do Winsock
#include <ws2tcpip.h> // Necessario para inet_pton e INET_ADDRSTRLEN
#include <stdlib.h> // Para exit, etc.

#pragma comment(lib, "ws2_32.lib") // Linka a biblioteca Winsock 2

#define PORTA 12345
#define BUFFER_SIZE 1024
#define IP_BUFFER_SIZE 32 // Tamanho suficiente para IPv4 string + newline

int main() {
    WSADATA wsaData;
    SOCKET cliente_socket = INVALID_SOCKET; // Inicializa com valor invalido
    struct sockaddr_in server_endereco;
    char mensagem[BUFFER_SIZE];
    char server_tamanho_ip[IP_BUFFER_SIZE]; // Buffer para ler o IP do usuario
    int status_mensagem;

    // 1. Inicializar o Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Erro ao inicializar o Winsock. Codigo de erro: %d\n", WSAGetLastError());
        return 1;
    }

    // 2. Solicitar o endereco IP do servidor ao usuario
    printf("Digite o endereco IP do servidor: ");
    if (fgets(server_tamanho_ip, IP_BUFFER_SIZE, stdin) == NULL) {
        printf("Erro na leitura do IP.\n");
        WSACleanup();
        return 1;
    }
    // Remover o caractere de nova linha lido pelo fgets
    server_tamanho_ip[strcspn(server_tamanho_ip, "\n")] = 0;

    // 3. Criar socket do cliente
    cliente_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (cliente_socket == INVALID_SOCKET) {
         printf("Erro ao criar socket. Codigo de erro: %d\n", WSAGetLastError());
         WSACleanup();
         return 1;
    }

    server_endereco.sin_family = AF_INET;
    server_endereco.sin_port = htons(PORTA);

    // 4. Definir endereco do servidor usando o IP fornecido pelo usuario
    if (inet_pton(AF_INET, server_tamanho_ip, &server_endereco.sin_addr) <= 0) {
        // inet_pton retorna 0 para IP invalido, -1 para erro
        printf("Endereco IP '%s' invalido.\n", server_tamanho_ip);
        closesocket(cliente_socket);
        WSACleanup();
        return 1;
    }

    // 5. Conectar ao servidor
    if (connect(cliente_socket, (struct sockaddr *)&server_endereco, sizeof(server_endereco)) < 0) {
        printf("Erro ao conectar ao servidor %s:%d. Codigo de erro: %d\n", server_tamanho_ip, PORTA, WSAGetLastError());
        closesocket(cliente_socket);
        WSACleanup();
        return 1;
    }

    printf("Conectado ao servidor %s:%d\n", server_tamanho_ip, PORTA);
    printf("Digite mensagens para enviar (digite 'sair' para desconectar):\n");

    // 6. Loop para enviar MULTIPLAS mensagens
    while (1) {
        printf("> "); // Prompt para o usuario
        if (fgets(mensagem, BUFFER_SIZE, stdin) == NULL) {
            printf("\nErro ou fim de entrada.\n");
            break;
        }

        // Remover o caractere de nova linha lido pelo fgets
        mensagem[strcspn(mensagem, "\n")] = 0;

        // Verificar se o usuario digitou o comando para sair
        if (strcmp(mensagem, "sair") == 0) {
            printf("Desconectando...\n");
            break; // Sai do loop
        }

        // Verificar se a mensagem nao esta vazia antes de enviar
        if (strlen(mensagem) > 0) {
             // Enviar a mensagem
            status_mensagem = send(cliente_socket, mensagem, strlen(mensagem), 0);
            if (status_mensagem == SOCKET_ERROR) {
                printf("Erro ao enviar mensagem. Codigo de erro: %d\n", WSAGetLastError());
                break; // Sai do loop em caso de erro de envio
            }
        }
    }

    // 7. Fechar o socket apos sair do loop
    closesocket(cliente_socket);

    // 8. Limpar o Winsock apos fechar o socket
    WSACleanup();

    printf("Conexao encerrada.\n");

    return 0;
}
