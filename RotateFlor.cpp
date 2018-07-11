// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>      
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265

     // glVertex2d(90, 180);
     //  glVertex2d(60, 130);
     //  glVertex2d(135, 120);

     //  glVertex2d(135, 120);
     //  glVertex2d(90, 60);
     //  glVertex2d(60, 110);
     //  glVertex2d(135, 120);

     //  glVertex2d(135, 120);
     //  glVertex2d(180, 180);
     //  glVertex2d(210, 130);
     //  glVertex2d(135, 120);

     //  glVertex2d(135, 120);
     //  glVertex2d(180, 60);
     //  glVertex2d(210, 110);
     //  glVertex2d(135, 120);
vector< pair< double, double > > coord =
{
  {90, 180},
  {60,130},
  {135,120},
  
  {135,120},
  {90,60},
  {60,110},
  {135,120},
  
  {135,120},
  {180,180},
  {210,130},
  {135,120},
  
  {135,120},
  {180,60},
  {210,110},
  {135,120},
  
};

void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,200,0,150);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

void desenhaLinha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3f, 1.0f, 1.0f);

    glBegin(GL_LINES);
      glVertex2i(135, 0);
      glVertex2i(135, 120);

    glEnd();

    glBegin(GL_LINES);
      glVertex2i(135, 0);
      glVertex2i(135, 120);
    glEnd();  

    //Petala 1

    glBegin(GL_TRIANGLE_STRIP);
      for(int i=0;i<coord.size();i++)
        glVertex2d(coord[i].first, coord[i].second);
      
    glEnd();

    glFlush();


}

void rotateLeft(){
  double xCenter = 135, yCenter = 120;
  for(int i=0;i<coord.size();i++){
    double x = coord[i].first, y = coord[i].second;
    coord[i].first = xCenter + cos(PI/180) * (x - xCenter) - sin(PI/180) * (y - yCenter);
    coord[i].second = yCenter + sin(PI/180) * (x - xCenter) + cos(PI/180) * (y - yCenter);
  }
  glutPostRedisplay();
}

void rotateRight(){
  double xCenter = 135, yCenter = 120;
  for(int i=0;i<coord.size();i++){
    double x = coord[i].first, y = coord[i].second;
    coord[i].first = xCenter + cos(-(PI/180)) * (x - xCenter) - sin(-(PI/180)) * (y - yCenter);
    coord[i].second = yCenter + sin(-(PI/180)) * (x - xCenter) + cos(-(PI/180)) * (y - yCenter);
  }
  glutPostRedisplay();
}

void MyKeyboardFunc(unsigned char Key, int x, int y){
  switch(Key){
    case 'a': rotateLeft();
    break;
    case 'd': rotateRight();
    break;
  }
}

// Programa Principal 
int main(int argc, char** argv)
{
      glutInit(&argc, argv);


     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Quadrado");
     glutDisplayFunc(desenhaLinha);
     glutReshapeFunc(AlteraTamanhoJanela);
     Inicializa();
     glutKeyboardFunc(MyKeyboardFunc);
     // glutSwapBuffers();
     glutMainLoop();
}