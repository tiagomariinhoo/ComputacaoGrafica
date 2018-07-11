// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>      
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265

    // glBegin(GL_QUADS);
    //   glVertex2d(90, 110);
    //   glVertex2d(110, 110);
    //   glVertex2d(110, 90);
    //   glVertex2d(90, 90);
    // glEnd();

    // glBegin(GL_QUADS);
    //   glVertex2d(130, 110);
    //   glVertex2d(150, 110);

    //   glVertex2d(150, 90);
    //   glVertex2d(130, 90);
    // glEnd();

    // glBegin(GL_QUADS);
    //   glVertex2d(170, 110);
    //   glVertex2d(190, 110);

    //   glVertex2d(190, 90);
    //   glVertex2d(170, 90);
    // glEnd();

    // glBegin(GL_QUADS);
    //   glVertex2d(210, 110);
    //   glVertex2d(230, 110);
    //   glVertex2d(230, 90);
    //   glVertex2d(210, 90);
    // glEnd();

    // drawFillCircle(100, 120, 10);
    // drawFillCircle(140, 120, 10);
    // drawFillCircle(220, 120, 10);
    // drawFillCircle(180, 120, 10);
vector < pair<double, double> > q1 = {
  {90, 110},
  {110, 110},
  {110, 90},
  {90, 90}
};

vector < pair<double, double> > q2 = {
  {130, 110},
  {150, 110},
  {150, 90},
  {130, 90}
};

vector < pair<double, double> > q3 = {
  {170, 110},
  {190, 110},
  {190, 90},
  {170, 90}
};

vector < pair<double, double> > q4 = {
  {210, 110},
  {230, 110},
  {230, 90},
  {210, 90}
};

pair< pair < double, double > , int > c1 = {{100, 120}, 10};
pair< pair < double, double > , int > c2 = {{140, 120}, 10};
pair< pair < double, double > , int > c3 = {{180, 120}, 10};
pair< pair < double, double > , int > c4 = {{220, 120}, 10};

int step = 1;

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

void drawFillCircle(GLfloat x, GLfloat y, GLfloat radius){
  int i;
  int triangleAmount = 20;

  GLfloat twicePi = 2.0f * PI;

  glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for(int i=0;i<=triangleAmount;i++){
      glVertex2d(
          x + (radius * cos(i * twicePi/triangleAmount)),
          y + (radius * sin(i * twicePi/triangleAmount))
        );
    }
    glEnd();
}

void desenhaLinha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    for(int i=0;i<4;i++) glVertex2d(q1[i].first, q1[i].second);
    glEnd();

    glBegin(GL_QUADS);
    for(int i=0;i<4;i++) glVertex2d(q2[i].first, q2[i].second);
    glEnd();

    glBegin(GL_QUADS);
    for(int i=0;i<4;i++) glVertex2d(q3[i].first, q3[i].second);
    glEnd();

    glBegin(GL_QUADS);
    for(int i=0;i<4;i++) glVertex2d(q4[i].first, q4[i].second);
    glEnd();


    drawFillCircle(c1.first.first, c1.first.second, c1.second);
    drawFillCircle(c2.first.first, c2.first.second, c2.second);
    drawFillCircle(c3.first.first, c3.first.second, c3.second);
    drawFillCircle(c4.first.first, c4.first.second, c4.second);

    glFlush();


}

void toLeft(){

}

void delay(float secs)
{
  float end = clock()/CLOCKS_PER_SEC + secs;
  while((clock()/CLOCKS_PER_SEC) < end);
}

void wait ( int seconds ) 
{ 
  clock_t endwait; 
  endwait = clock () + seconds * CLOCKS_PER_SEC ; 
  while (clock() < endwait) {} 
} 
 

void toRight(){
  if(step == 1){
    
    for(int i=0;i<4;i++){
      q2[i].second += 10;
    }

    for(int i=0;i<4;i++){
      q3[i].second += 20;
    }

    for(int i=0;i<4;i++){
      q4[i].second += 30;
    }

    c2.first.second += 10;

    c3.first.second += 20;

    c4.first.second += 30;

    step++;

  glutPostRedisplay();
  } else if(step == 2){
    for(int i=0;i<4;i++){
      q1[i].second += 30;
    }
    for(int i=0;i<4;i++){
      q2[i].second += 20;
    }
    for(int i=0;i<4;i++){
      q3[i].second += 10;
    }

    c1.first.second += 30;
    c2.first.second += 20;
    c3.first.second += 10;

    step++;

  glutPostRedisplay();
  // wait(3);
  } else if(step == 3){

    for(int i=0;i<4;i++){
      q2[i].second -= 10;
    }

    for(int i=0;i<4;i++){ 
      q3[i].second -= 20;
    }

    for(int i=0;i<4;i++){
      q4[i].second -= 30;
    }

    c2.first.second -= 10;
    c3.first.second -= 20;
    c4.first.second -= 30;

    step++;

  glutPostRedisplay();
  } else if(step == 4){

    for(int i=0;i<4;i++){
      q1[i].second -= 30;
    }

    for(int i=0;i<4;i++){
      q2[i].second -= 20;
    }

    for(int i=0;i<4;i++){
      q3[i].second -= 10;
    }

    c1.first.second -= 30;
    c2.first.second -= 20;
    c3.first.second -= 10;
    step = 1;
  }

  glutPostRedisplay();
}

void MyKeyboardFunc(unsigned char Key, int x, int y){
  switch(Key){
    // case 'a': rotateLeft();
    // break;
    case 'd': toRight();
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
