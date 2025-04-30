#include <stdio.h>
#include <stdlib.h>

struct Num{
	int n1, n2;
};

int main(){
	struct Num obj;
	FILE *arquivo;
	
	arquivo = fopen("arquivo_binario.bin", "wb");
	
	if(arquivo == NULL){
		printf("Falha ao abrir o arquivo!");
		exit(1);
	}else{
		int i = 1;
		for(i; i < 10; i++){
			obj.n1 = i;
			obj.n2 = i + 12;
			
			fwrite(&obj, sizeof(struct Num), 1, arquivo);
		}
		fclose(arquivo);
		printf("Dados gravados com sucesso!");
	}
}