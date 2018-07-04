
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>      
#include <GL/glut.h>

void Desenha(void) //Desenha quads
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     //         R     G     B
     glColor3f(1.0f, 0.0f, 0.0f);

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_QUADS);
               glVertex2i(100,150);
               glVertex2i(100,100);
               // Especifica que a cor corrente é azul
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(150,100);
               glVertex2i(150,150);               
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

void Desenha2(){ //Desenha os pontos
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glPointSize(5);

   glBegin(GL_POINTS);
      glVertex2i(100, 50);
      glVertex2i(100, 130);
      glVertex2i(150, 130);
      glVertex2i(200, 130);
      glVertex2i(250, 130);
   glEnd(); 
   
   glFlush();
}

void Desenha3(){ //desenha as lines
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);

   glBegin(GL_LINES);
      glVertex2i(100,50);
      glVertex2i(150,50);
      glVertex2i(200,30);
      glVertex2i(250, 40);
   glEnd();
   glFlush();
}

void Desenha4(){ //Desenha line strip
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glBegin(GL_LINE_STRIP);
      glVertex2i(100, 50);
      glVertex2i(300, 80);
      glVertex2i(150, 60);
      glVertex2i(109, 40);
   glEnd();
   glFlush();
}

void Desenha5(){ //desenha line loop
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glBegin(GL_LINE_LOOP);
      glVertex2i(100, 50);
      glVertex2i(300, 80);
      glVertex2i(150, 60);
      glVertex2i(230, 100);
      glVertex2i(420, 40);
      glVertex2i(109, 40);
   glEnd();
   glFlush();
}

void Desenha6(){ //Desenha Triangulo
    glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glBegin(GL_TRIANGLES);
      glVertex2i(100, 50);
      glVertex2i(300, 80);
      // glVertex2i(150, 60);
      // glVertex2i(230, 100);
      glVertex2i(420, 40);
      // glVertex2i(109, 40);
   glEnd();
   glFlush();
}

void Desenha7(){ //Triangle Strip
    glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glBegin(GL_TRIANGLE_STRIP);
      glVertex2i(100, 50);
      glVertex2i(300, 80);
      glVertex2i(150, 60);
      glVertex2i(230, 100);
      // glVertex2i(420, 40);
      glVertex2i(109, 40);
   glEnd();
   glFlush();
}

void Desenha8(){ //Quad Strip
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glBegin(GL_QUAD_STRIP);
      glVertex2i(100, 50);
      glVertex2i(300, 80);
      glVertex2i(150, 60);
      glVertex2i(230, 100);
      glVertex2i(420, 40);
      glVertex2i(109, 40);
      glVertex2i(50, 200);
      glVertex2i(50, 400);
   glEnd();
   glFlush();
}  

void Desenha9(){ //POLYGON
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glBegin(GL_POLYGON);
      // glVertex2i(100, 50);
      // glVertex2i(300, 80);
      // glVertex2i(150, 60);
      glVertex2i(230, 100);
      glVertex2i(420, 40);
      glVertex2i(109, 40);
      glVertex2i(50, 200);
      glVertex2i(50, 400);
   glEnd();
   glFlush();
}

void Desenha10(){ //Triangle Fan
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.3f, 1.0f, 1.0f);
   glBegin(GL_TRIANGLE_FAN);
      glVertex2i(100, 50);
      glVertex2i(300, 80);
      glVertex2i(150, 60);
      glVertex2i(230, 100);
      glVertex2i(420, 40);
      glVertex2i(109, 40);
      glVertex2i(50, 200);
      glVertex2i(50, 400);
   glEnd();
   glFlush();
}

// Inicializa parâmetros de rendering
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

// Programa Principal 
int main(int argc, char** argv)
{
      glutInit(&argc, argv);


     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Quadrado");
     glutDisplayFunc(Desenha10);
     glutReshapeFunc(AlteraTamanhoJanela);
     Inicializa();
     glutMainLoop();
}
