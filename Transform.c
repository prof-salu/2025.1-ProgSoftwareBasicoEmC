#include <GL/glut.h>
//Posicao do quadrado
float quadradoX = 0.0;
float quadradoY = 0.0;
//Incremento da velocidade de movimentacao
float incremento = 0.01f;

void desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);//vermelho
	
	//Salva a matriz de transformacao
	glPushMatrix();
	//Move o objeto pela cena
		glTranslatef(quadradoX, quadradoY, 0.0f);
		glBegin(GL_QUADS);
			glVertex2f(-0.1f, -0.1f);
			glVertex2f( 0.1f, -0.1f);
			glVertex2f( 0.1f,  0.1f);
			glVertex2f(-0.1f,  0.1f);
		glEnd();
	//Restaura a matriz de transformacao anterior
	glPopMatrix();
	
	//Troca os buffers para exibir o desenhado
	glutSwapBuffers();
	
}

void atualizar(int valor){
	//Atualiza a posicao do quadrado
	quadradoX += incremento;
	quadradoY += incremento;
	
	if(quadradoX > 1.0f || quadradoX < -1.0f){
		incremento *= -1;
	}
	
	//Define que a janela sera redesenhada
	glutPostRedisplay();
	
	//Intervalo para a chamada da funcao
	glutTimerFunc(16, atualizar, 0);//16ms ==> 60FPS
	
}

void inicializa(){
	//Cor de fundo preto
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void redimensiona(int largura, int altura){
	//Define a dimensao da janela utilizada para desenhar(tela toda)
	glViewport(0, 0, largura, altura);
	//Define que as transformacoes afetarao a projecao
	glMatrixMode(GL_PROJECTION);
	//Reseta a matriz de projecao
	glLoadIdentity();
	//Define uma projecao ortogonal
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	//Define que as operacoes afetaram a modelagem e a visao
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Transformacoes");
	
	inicializa();	
	glutDisplayFunc(desenha);
	glutReshapeFunc(redimensiona);
	glutTimerFunc(16, atualizar, 0);	
	glutMainLoop();
}