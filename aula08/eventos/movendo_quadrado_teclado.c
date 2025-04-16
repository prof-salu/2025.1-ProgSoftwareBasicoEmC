#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

//Posicao inicial
float posX = 0.0f;
float posY = 0.0f;

void desenha(){
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(1.0f, 0.0f, 0.0f);//cor do quadrado (vermelho)
	
	glBegin(GL_QUADS);
		glVertex2f(posX - 0.1f, posY - 0.1f);
		glVertex2f(posX + 0.1f, posY - 0.1f);
		glVertex2f(posX + 0.1f, posY + 0.1f);
		glVertex2f(posX - 0.1f, posY + 0.1f);
	glEnd();
	
	glutSwapBuffers();
}

void tecladoEspecial(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			posY += 0.05f;
			break;
		case GLUT_KEY_DOWN:
			posY -= 0.05f;
			break;
		case GLUT_KEY_RIGHT:
			posX += 0.05f;
			break;
		case GLUT_KEY_LEFT:
			posX -= 0.05f;
			break;
	}
	glutPostRedisplay();//Pede para o glut redesenhar a tela
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Movendo quadrado");	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);//Cor de fundo preta	
	glutDisplayFunc(desenha);
	glutSpecialFunc(tecladoEspecial);
	glutMainLoop();
}