#include <stdio.h>
#include <stdlib.h>

struct Num{
	int n1, n2;
};

int main(){
	struct Num obj;
	
	FILE *arquivo;
	
	arquivo = fopen("arquivo_binario.bin", "rb");
	
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo binario!");
		exit(1);
	}else{
		while(fread(&obj, sizeof(struct Num), 1, arquivo)== 1){
			printf("n1: %d\tn2: %d\n", obj.n1, obj.n2);
		}
		fclose(arquivo);
		printf("Fim da leitura do arquivo binario.\n");
	}
}