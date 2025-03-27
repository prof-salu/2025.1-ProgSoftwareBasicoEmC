#include <gl/glut.h>

void desenha(){
	//Limpa a tela em execução com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);	
	glFlush();
}

void inicializa(){
	//Define a cor de fundo (RGBA) da janela (PRETO)
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glutCreateWindow("Ola mundo GLUT!");	
	glutDisplayFunc(desenha);	
	inicializa();	
	glutMainLoop();
}