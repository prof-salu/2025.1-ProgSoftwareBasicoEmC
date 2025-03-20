#include <stdio.h>

//Foram anotadas as idades e alturas de 10 alunos. Faça um Programa 
//que determine quantos alunos com mais de 13 anos possuem altura 
//inferior à média de altura desses alunos.

int main(){
	int idades[10];
	float alturas[10];
	
	float somaAltura = 0, mediaAltura = 0;
	int idadeAcima13AlturaAbaixoMedia = 0;
	
	for(int i = 0; i < 10; i++){
		printf("Informe a idade do aluno %03d: ", (i + 1));
		scanf("%d", &idades[i]);
		
		printf("Informe a altura do aluno %03d: ", (i + 1));
		scanf("%f", &alturas[i]);
		
		somaAltura += alturas[i];
	}
	
	mediaAltura = somaAltura / 10;
	
	for(int i = 0; i < 10; i++){
		if(idades[i] > 13 && alturas[i] < mediaAltura){
			idadeAcima13AlturaAbaixoMedia++;
		}
	}
	
	printf("Total de alunos: %d", idadeAcima13AlturaAbaixoMedia);
}