#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

typedef struct {
    int x;
    int y;
}ponto;

void desenha();
void init();
void draw(char*,ponto*,int);

GLint   WIDTH = 500,
        HEIGHT = 500;

ponto A,B,C,D,Z,X,Y;

ponto quad[4];
ponto tri[3];

// ponto triangulo[3] = {A,B,C};
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400 ,100);
    glutInitWindowSize(WIDTH,WIDTH);
    glutCreateWindow("Exercicio - Castelo");

    init();
    glutDisplayFunc(desenha);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-2,2,-2,2);

    //Coordenadas do quad
    A.x = -1;
    A.y = -1;
    B.x = 1;
    B.y = -1;
    C.x = 1;
    C.y = 1;
    D.x = -1;
    D.y = 1;
    quad[0] = A;
    quad[1] = B;
    quad[2] = C;
    quad[3] = D;

    //Coordenadas do triangulo
    Z.x = -1;
    Z.y = 0;
    X.x = 1;
    X.y = 0;
    Y.x = 0;
    Y.y = 1;
    tri[0] = Z;
    tri[1] = X;
    tri[2] = Y;
    

}

void desenha(){

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    draw("vertices",quad,4);
    draw("linhas",quad,4);
    draw("vertices",tri,3);
    draw("linhas",tri,3);
    glFlush();
}

void draw(char *tipo, ponto *figura, int n){

    // char aux[100];
    // strcpy(tipo,aux);
    if(!strcmp("vertices",tipo)){
        glPointSize(10);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POINTS);
            for(int i = 0; i < n; i++){
                glVertex2i(figura[i].x, figura[i].y);
            }
        glEnd();
    }
    else if(!strcmp(tipo,"linhas")){
        glLineWidth(2);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
            for(int i = 0; i < n; i++){
                printf("figura[i].x: %d, figura[i].y: %d\n", figura[i].x, figura[i].y);
                glVertex2i(figura[i].x, figura[i].y);
                if(i == n-1)glVertex2i(figura[0].x, figura[0].y);
                else glVertex2i(figura[i+1].x, figura[i+1].y);
            }
        glEnd();
    }

}