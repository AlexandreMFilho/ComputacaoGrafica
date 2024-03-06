#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void desenha();
void teclado(GLubyte key, GLint x, GLint y);
void init();
void casa();
void janela();
void porta();

GLint   WIDTH = 500,
        HEIGHT = 500;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400 ,100);
    glutInitWindowSize(WIDTH,WIDTH);
    glutCreateWindow("Tarefa 1 - Questao 1");

    init();
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    casa(200,200);
    glFlush();
}

float regra3_256(int x){
    return x/256.0;
}

void casa(int x,int y){
    //Parede
    int x_casa=x,
         y_casa=y,
         comprimento_casa = 100,
         altura_casa = 100;
    glBegin(GL_QUADS);
        glColor3f(regra3_256(204), regra3_256(0), regra3_256(204));
        glVertex2i(x_casa, y_casa);
        glVertex2i(x_casa+comprimento_casa, y_casa);
        glVertex2i(x_casa+comprimento_casa, y_casa+altura_casa);
        glVertex2i(x_casa, y_casa+altura_casa);
    glEnd();
    //Telhado
    int x_tel = x_casa,
        y_tel = y_casa+100,
        comprimento_tel = 100,
        altura_tel = 50;
    glBegin(GL_TRIANGLES);
        glColor3f(regra3_256(256), regra3_256(0), regra3_256(0));
        glVertex2i(x_tel, y_tel);
        glVertex2i(x_tel+comprimento_tel, y_tel);
        glVertex2i(x_tel+(comprimento_tel/2), y_tel+altura_tel);
    glEnd();

    porta(x_casa+35,y_casa+1);
    janela(x_casa+70,y_casa+50);
    janela(x_casa+5,y_casa+50);

}

void porta(int x, int y){
 //Porta
    int x_porta = x,
        y_porta = y,
        comprimento_porta = 30,
        altura_porta = 70;
    glBegin(GL_QUADS);
        glColor3f(regra3_256(256), regra3_256(256), regra3_256(256));
        glVertex2i(x_porta, y_porta);
        glVertex2i(x_porta, y_porta+altura_porta);
        glVertex2i(x_porta+comprimento_porta, y_porta+altura_porta);
        glVertex2i(x_porta+comprimento_porta, y_porta);
    glEnd();
    
    
}

void janela(int x, int y){
    //Janela
    glBegin(GL_QUADS);
        int x_jal = x,
            y_jal = y,
            comprimento_jal = 25,
            altura_jal = 20;
        glColor3f(regra3_256(256), regra3_256(256), regra3_256(256));
        glVertex2i(x_jal,y_jal);
        glVertex2i(x_jal,y_jal+altura_jal);
        glVertex2i(x_jal+comprimento_jal,y_jal+altura_jal);
        glVertex2i(x_jal+comprimento_jal,y_jal);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(regra3_256(204), regra3_256(0), regra3_256(204));
        glVertex2i(x_jal,y_jal+(altura_jal/2));
        glVertex2i(x_jal+comprimento_jal,y_jal+(altura_jal/2));
        glVertex2i(x_jal+(comprimento_jal/2),y_jal+altura_jal);
        glVertex2i(x_jal+(comprimento_jal/2),y_jal);
    glEnd();
    
}

void teclado(GLubyte key, GLint x, GLint y){
  if((GLint) key == 32){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    desenha();
    glFlush();

  }else{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    desenha();
    glFlush();

  }

}

//gcc questao_1.c -o questao_1 -lglut -lGL -lGLU