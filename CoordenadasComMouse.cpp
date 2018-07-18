#include <bits/stdc++.h>    
#include <GL/glut.h>

int winWidth = 2000, winHeight = 2000;

void displayFcn(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10.0);
	glFlush();
	// glutSwapBuffers();
}

void plotPoint(GLint x, GLint y){
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){
	if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
		int x1 = xMouse;
		int y1 = winHeight - yMouse;
		plotPoint(x1, y1);
		// cout << " ( " << x1 << " , " << y1 << " ) " << endl;
	}
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, GLdouble(winWidth), 0.0, GLdouble (winHeight), -1.0, 1.0);
	// float r = newWidth / newHeight;
	// glViewport(0, 0, newWidth, newHeight);
	// glOrtho(-50 * r, 50 * r, -50, 50, 1.0, -1.0);
}

void init(){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 200.0, 0.0, 150.0, -1.0, 1.0);
	glFlush();
}


int main(int argc, char** argv){

	//Inicia glut
	glutInit(&argc, argv);

	//Janela com buffer simples e em RGB
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(winWidth, winHeight);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Pontos usando Mouse");

	init(); //Chama procedimentos de inicializacao

	glutDisplayFunc(displayFcn);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mousePtPlot);

	glutMainLoop();

	return 0;
}
