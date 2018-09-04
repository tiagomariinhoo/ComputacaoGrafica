#include <GL/glut.h>
#include<bits/stdc++.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape (int w, int h);

//Cada cor das faces do cubo
#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6

//Vertices do cubo
static GLfloat vertices[30]={
  0.0,  30.0, 30.0, /* 0 */
  20.0, 30.0, 30.0, /* 1 */
  30.0, 20.0, 30.0, /* 2 */
  30.0,  0.0, 30.0, /* 3 */
  0.0,   0.0, 30.0, /* 4 */
  0.0,  30.0,  0.0, /* 5 */
  30.0, 30.0,  0.0, /* 6 */
  30.0,  0.0,  0.0, /* 7 */
  0.0,   0.0,  0.0, /* 8 */
  30.0, 30.0, 20.0  /* 9 */
}; 

//Vertor de posições de cada um dos vertices do cubo
static GLubyte frenteIndices[]    = {0,4,3,2,1};
static GLubyte trasIndices[]      = {5,6,7,8};
static GLubyte esquerdaIndices[]  = {0,5,8,4};
static GLubyte direitaIndices[]   = {2,3,7,6,9};
static GLubyte topoIndices[]      = {0,1,9,6,5};
static GLubyte fundoIndices[]     = {3,4,8,7};
static GLubyte trianguloIndices[] = {1,2,9};
    
//Armazenar a rotação em torno do eixo y e x
static int eixoy, eixox;
//Armazena a altura e largura da tela de desenho
int largura, altura;

int main(int argc, char** argv){
  int i;
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glOrtho (-50, 50, -50, 50, -50 , 50);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE); 
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  largura=w; 
  altura=h;
}

void display(void){
  //Push pra trabalhar na matriz
  glPushMatrix();
  glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) eixox, 1.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  
  //Permite desenhar objetos utilizando índices para referenciar as coordenadas
  //dos seus vértices
  glEnableClientState(GL_VERTEX_ARRAY);
  //Com isso, os vertices do cubo são indexados através da chamada dessa função
  glVertexPointer(3, GL_FLOAT, 0, vertices);

  //Desenha cada face do cubo, de acordo com o array de posições
  glColor3f (AZUL); /* frente */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, frenteIndices);

  glColor3f (AMARELO); /* esquerda */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerdaIndices);

  glColor3f (VERMELHO); /* tras */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, trasIndices);

  glColor3f (VERDE); /* direita */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, direitaIndices);

  glColor3f (CYAN); /* topo */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, topoIndices);

  glColor3f (LARANJA); /* fundo */
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, fundoIndices);

  glColor3f (CINZA); /* triangulo */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, trianguloIndices);

  glDisableClientState (GL_VERTEX_ARRAY);

  //Pop na matriz, já que acabou de trabalhar com ela
  glPopMatrix();
  //Troca os buffers
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'a': //Printa as coordenadas no terminal
    printf("%d, %d\n",x,y);
    break;
  case 'y':
    eixoy = (eixoy + 5) % 360; //Rotaciona no eixo y
    glutPostRedisplay();
    break;
  case 'Y':
    eixoy = (eixoy - 5) % 360; //Rotaciona no eixo y
    glutPostRedisplay();
    break;
  case 'x':
    eixox = (eixox + 5) % 360; //Rotaciona no eixo x
    glutPostRedisplay();
    break;
  case 'X':
    eixox = (eixox - 5) % 360; //Rotaciona no eixo x
    glutPostRedisplay();
    break;
  case 'p':
    glLoadIdentity();
    //GluPerspective faz com que todas as chamadas de agora em diante sejam projeções de perspectiva
    //A parte que foi dado na aula
    //fovy, aspect, zNear, zFar (variação no eixo Z, tipo profundidade)
    //Fovy especifica o campo de visão em graus
    //Aspect define a relação de aspecto entre largura e altura
    //ZNear e ZFar especificam as distancias entre o observador e os planos de recorte mais proimo e distante
    //Lembrar da parte do ZNear e ZFar dado em aula
    gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 20.0, 120.0);
    //GluLookAt permite definir o ponto de observação, um ponto de referência, para onde o observador
    //está olhando e a direção do vetor que aponta para cima
    //eyex, eyez, centerx, centery, centerz, upx, upy, upz
    //Lembrar do exemplo da câmera dado em aula
    //Nesse caso, o obsrvador se encontra em z=-90, está olhando para a origem (0,0,0)
    //E o vetor aponta para (0,1,0) 
    gluLookAt(0, 0, -90, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
    break;
  case 'o':
    glLoadIdentity();
    glOrtho (-50, 50, -50, 50, -50 , 50);
    glutPostRedisplay();
    break;
  }
}
