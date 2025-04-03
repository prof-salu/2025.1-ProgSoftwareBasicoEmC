#include <gl/glut.h>
#include <math.h>

void desenha(){
	//Limpa a janela de visualizacao
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Define a cor vermelha (RGB)
	glColor3f(1.0f, 0.0f, 0.0f);
	
	float cx = 0.0f;//posicao do centro em X
	float cy = 0.0f;//posicao do centro em Y
	float raio = 0.5f;//tamanho do raio
	int totalTriangulos = 64;//Total de trinagulos utilizados
	
	//Inicia o desenho de um quadrado
	glBegin(GL_POLYGON);
	for(int i = 0; i < totalTriangulos; i++){
		float angulo = 2.0f * M_PI * i / totalTriangulos;
		float x = cx + raio * cosf(angulo);
		float y = cy + raio * sinf(angulo);
		glVertex2f(x,y);
	}
			
	//Finaliza o desenho
	glEnd();
	
	//Executa os comandos opengl
	glFlush();
}

void inicializa(){
	//Cor preta (RGBA)
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv){
	//Inicializa o glut
	glutInit(&argc, argv);
	//Definindo o buufer mode (SINGLE) e o color (RGB)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Definindo o tamanho da janela
	glutInitWindowSize(400, 300);
	//Nome da janela
	glutCreateWindow("Circulo");
	
	glutDisplayFunc(desenha);
	inicializa();
	//Loop principal
	glutMainLoop();
}