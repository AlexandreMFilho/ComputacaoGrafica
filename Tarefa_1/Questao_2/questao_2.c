#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void desenha();
void mouse(GLint button, GLint action, GLint x, GLint y);
void init();
void criaponto();

typedef struct{
    GLint x;
    GLint y;
}ponto;

ponto P[1000];
int total = 0,
    flag =0;

GLint   WIDTH = 800,
        HEIGHT = 600,
        gx = 0,
        gy = 0;

void adicionarponto(GLint x, GLint y){
    P[total].x = x;
    P[total].y = y;
    total++;
}

void esvaziar(){
    total = 0;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400 ,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Tarefa 1 - Questao 1");

    init();
    glutDisplayFunc(desenha);
    glutMouseFunc(mouse);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void init(){
    gluOrtho2D(0, WIDTH, HEIGHT,0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}


void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(flag == 1){
        glPointSize(50);
        glBegin(GL_POINTS);
        for(int i = 0; i < total; i++){
            glColor3f(0.0, 0.0, 0.0);
            glVertex2i(P[i].x, P[i].y);
        }
        glEnd();
    }
    glFlush();
}

void mouse(GLint button, GLint action, GLint x, GLint y)
{
    switch(button){
        case GLUT_LEFT_BUTTON:
            flag = 1;
            gx = x;
            gy = y;
            adicionarponto(x,y);
            break;
        case GLUT_RIGHT_BUTTON:
            flag = 0;
            esvaziar();
            break;
    }
    desenha();
    glutPostRedisplay();
    
}

//gcc questao_2.c -o questao_2 -lglut -lGL -lGLU