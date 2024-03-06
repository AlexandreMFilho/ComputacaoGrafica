#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void desenha();
void mouse(GLint button, GLint action, GLint x, GLint y);
void init();

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
    glutMouseFunc(mouse);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void mouse(GLint button, GLint action, GLint x, GLint y)
{
   if( button == GLUT_LEFT_BUTTON){
        //TODO Desenha ponto tamanho 50    
    }
    
}