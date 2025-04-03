#include <gl/glut.h>

void desenha(){
	//Limpa a janela de visualizacao
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Define a cor vermelha (RGB)
	glColor3f(1.0f, 0.0f, 0.0f);
	
	//Inicia o desenho de um quadrado
	glBegin(GL_QUADS);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(-0.5, 0.5);	
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
	glutCreateWindow("Quadrado");
	
	glutDisplayFunc(desenha);
	inicializa();
	//Loop principal
	glutMainLoop();
}