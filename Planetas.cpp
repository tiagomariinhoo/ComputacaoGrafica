#include <bits/stdc++.h>    
#include <GL/glut.h>

int year = 0, day = 0;

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);

  glPushMatrix();
    glRotatef((GLfloat) year, 1.0, 0.0, 0.0);
    glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
    glutWireSphere(1.0, 20, 16);
  glPopMatrix();

  glPushMatrix();
    glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
    glutWireSphere(0.2, 10, 8);
  glPopMatrix();

  glPushMatrix();
    glRotatef((GLfloat) -year, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
    glutWireSphere(0.2, 10, 8);
  glPopMatrix();

  glPushMatrix();
    glRotatef((GLfloat) -year, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0, 0.0);
    glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
    glutWireSphere(0.05, 10, 8);
  glPopMatrix();

  glutSwapBuffers();
}

void init(){
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  // glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int w, int h){
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluPerspective(60.0,(GLfloat) w/(GLfloat) h, 1.0, 20.0);
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char Key, int x,int y){
  switch(Key){
    case 'd':
      day = (day + 10)%360;
      glutPostRedisplay();
      break;
    case 'D':
      day = (day - 10)%360;
      glutPostRedisplay();
      break;
    case 'y':
      year = (year + 10)%360;
      glutPostRedisplay();
      break;
    case 'Y':
      year = (year - 10)%360;
      glutPostRedisplay();
      break;
  }
}

void delay(int value){
  // year = (year + 10)%360;
  // day = (day + 10)%360;
  // glutPostRedisplay();
  // glutTimerFunc(40, delay, 1);
}

int main(int argc, char** argv){ 
  
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Rotacao de Planetas");

  init(); //Chama procedimentos de inicializacao


  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);

  glutTimerFunc(100, delay, 1);

  glutMainLoop();

  return 0;
}
