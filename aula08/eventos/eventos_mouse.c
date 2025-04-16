#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void eventosMouse(int botao, int estado, int x, int y){
	if(botao == GLUT_LEFT_BUTTON){
		if(estado == GLUT_DOWN){
			printf("Botao esquerdo do mouse pressionado.\n");
		}else{
			printf("Botao esquerdo do mouse liberado.\n");
		}
	}else if(botao == GLUT_RIGHT_BUTTON){
		if(estado == GLUT_DOWN){
			printf("Botao direito do mouse pressionado.\n");
		}else{
			printf("Botao direito do mouse liberado.\n");
		}
	}else if(botao == 3){
		if(estado == GLUT_UP){
			printf("SCROLL CIMA.\n");
		}
	}else if(botao == 4){
		if(estado == GLUT_UP){
			printf("SCROLL BAIXO.\n");
		}
	}else if(botao == GLUT_MIDDLE_BUTTON){
		if(estado == GLUT_DOWN){
			printf("Botao do meio do mouse pressionado.\n");
		}else{
			printf("Botao do meio do mouse liberado.\n");
		}
	}
}

void movimentoMouse(int x, int y){
	printf("Mouse movendo com botao pressionado em (%d, %d).\n", x, y);
}

void movimentoMousePassivo(int x, int y){
	printf("Mouse movendo sem botao pressionado em (%d, %d).\n", x, y);
}

void desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Eventos de Mouse");
	glutDisplayFunc(desenha);
	
	glutMouseFunc(eventosMouse);
	glutMotionFunc(movimentoMouse);
	glutPassiveMotionFunc(movimentoMousePassivo);
	
	glutMainLoop();
}