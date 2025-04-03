#include <gl/glut.h>

void desenha(){
	//Limpa a janela de visualizacao
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Define a cor vermelha (RGB)
	glColor3f(1.0f, 0.0f, 0.0f);
	
	//Desenha 5 pontos na tela
	glBegin(GL_POINTS);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(-0.5f, 0.5f);
			glVertex2f(0.5f, -0.5f);
	//Finaliza o desenho
	glEnd();
	
	//Define a cor roxa (RGB)
	glColor3f(1.0f, 0.0f, 1.0f);
	
	//Desenha uma reta
	glBegin(GL_LINES);
		glVertex2f(0.7f, 0.7f);
		glVertex2f(-0.7f, 0.7f);
	glEnd();
	
	
	//Desenha uma reta
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(1.5f, 1.5f);
	glEnd();
	
	//Executa os comandos opengl
	glFlush();
}

void inicializa(){
	//Cor preta (RGBA)
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv){
	//Inicializa o glut
	glutInit(&argc, argv);
	//Definindo o buufer mode (SINGLE) e o color (RGB)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Definindo o tamanho da janela
	glutInitWindowSize(400, 300);
	//Nome da janela
	glutCreateWindow("Linhas e pontos");
	
	glutDisplayFunc(desenha);
	inicializa();
	//Loop principal
	glutMainLoop();
}