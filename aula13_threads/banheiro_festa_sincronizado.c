#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//HANDLE global
HANDLE hMutex;

typedef struct{
	const char* nome; //Nome do convidado
	int tarefa; //tarefa executada NUMERO 1 ou 2
}Convidado;

void fazNumero1(const char* nome){
	printf("%s batendo na porta.\n", nome);
	fflush(stdout);//Garanete que a mensagem seja impressa imediatamente
	
	//Tenta capturar a chave (MUTEX)
	DWORD dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	
	//Conseguiu pegar a chave
	if(dwWaitResult == WAIT_OBJECT_0){
		printf("%s pegou a chave.\n", nome);
		printf("%s entrou no banheiro.\n", nome);
		printf("%s fazendo coisa rapida.\n", nome);
		fflush(stdout);	
		Sleep(5000);
		printf("%s dando descarga.\n", nome);
		Sleep(3000);
		printf("%s lavando as maos.\n", nome);
		Sleep(3000);
		printf("%s saindo do banheiro.\n", nome);
		Sleep(1000);
		fflush(stdout);
		//Libera a chave para a proxima thread
		ReleaseMutex(hMutex);
	}
}

void fazNumero2(const char* nome){
	printf("%s batendo na porta.\n", nome);
	fflush(stdout);//Garante que a mensagem seja impressa imediatamente
	
	//Tenta capturar a chave (MUTEX)
	DWORD dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	
	//Conseguiu pegar a chave
	if(dwWaitResult == WAIT_OBJECT_0){	
		printf("%s pegou a chave.\n", nome);
		printf("%s entrou no banheiro.\n", nome);
		printf("%s fazendo coisa demorada.\n", nome);
		fflush(stdout);	
		Sleep(10000);
		printf("%s dando descarga.\n", nome);
		Sleep(3000);
		printf("%s lavando as maos.\n", nome);
		Sleep(3000);
		printf("%s saindo do banheiro.\n", nome);
		Sleep(1000);
		fflush(stdout);	
		ReleaseMutex(hMutex);
	}
}

DWORD WINAPI rotinaBanheiro(LPVOID param){
	Convidado* convidado = (Convidado*) param;
	
	if(convidado->tarefa == 1){
		fazNumero1(convidado->nome);
	}else if(convidado->tarefa == 2){
		fazNumero2(convidado->nome);
	}
}

int main(){
	//NULL: atributo de seguranca [padrao]
	//FALSE: indicia a thread inicial nao inicia com o MUTEX
	//NULL: MUTEX sem nome
	hMutex = CreateMutex(NULL, FALSE, NULL);
	
	Convidado c1 = {"Jonin", 2};
	Convidado c2 = {"Gigi", 1};
	Convidado c3 = {"Gabi", 1};
	Convidado c4 = {"Harry", 2};
	
	HANDLE threads[4];
	
	//Alocando a memoria
	threads[0] = (Convidado*)malloc(sizeof(Convidado));
	threads[1] = (Convidado*)malloc(sizeof(Convidado));
	threads[2] = (Convidado*)malloc(sizeof(Convidado));
	threads[3] = (Convidado*)malloc(sizeof(Convidado));
	//Criando as threads
	threads[0] = CreateThread(NULL, 0, rotinaBanheiro, &c1, 0, NULL );
	threads[1] = CreateThread(NULL, 0, rotinaBanheiro, &c2, 0, NULL );
	threads[2] = CreateThread(NULL, 0, rotinaBanheiro, &c3, 0, NULL );
	threads[3] = CreateThread(NULL, 0, rotinaBanheiro, &c4, 0, NULL );
	
	WaitForMultipleObjects(4, threads, TRUE, INFINITE);
	
	printf("Todos os convidados liberaram o banheiro.\n");
	
	//Libera os recursos utilizados  pelas threads
	for(int i = 0; i < 4; i++){
		CloseHandle(threads[i]);
	}
	
	CloseHandle(hMutex);
}