#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void eventosTeclado(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			printf("Tecla W (%d) (%d, %d) pressionada!\n", key, x, y);
			break;
		case 's':
			printf("Tecla S (%d) (%d, %d)pressionada!\n", key, x, y);
			break;
		case 'a':
			printf("Tecla A (%d) (%d, %d) pressionada!\n", key, x, y);
			break;
		case 'd':
			printf("Tecla D (%d) (%d, %d) pressionada!\n", key, x, y);
			break;
		default:
			printf("Tecla %c (%d) pressionada!\n", key, key);
			break;
	}
}

void eventosTecladoEspecial(int key, int x, int y){
	switch(key){
		case GLUT_KEY_LEFT:
			printf("Seta da esquerda pressionada!");
			break;
		case GLUT_KEY_RIGHT:
			printf("Seta da direita pressionada!");
			break;
		case GLUT_KEY_UP:
			printf("Seta pra cima pressionada!");
			break;
		case GLUT_KEY_DOWN:
			printf("Seta pra baixo pressionada!");
			break;
		case 27:
			//Tecla ESC
			exit(0);
			break;
		default:
			printf("Tecla especial pressionada %d", key);
			break;	
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Eventos de teclado");
	glutDisplayFunc(desenha);
	glutKeyboardFunc(eventosTeclado);
	glutSpecialFunc(eventosTecladoEspecial);
	glutMainLoop();
}