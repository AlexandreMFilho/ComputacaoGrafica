#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

void desenha();
void init();
void draw(char*,int(*)[2],int);
void carro();
void catavento();
void helice();
void pa();
void montanha();

void orientacao();

GLint   WIDTH = 500,
        HEIGHT = 500;

int quadrado[][2] = {
    {-1,-1},
    {1,-1},
    {1,1},
    {-1,1}
};

int triangulo[][2] = {
    {-1,0},
    {1,0},
    {0,1}
};

int chassi[][2] = {
    {0,0},
    {5,0},
    {5,2},
    {4,2},
    {3,3},
    {1,3},
    {1,2},
    {0,2},
};

int origem[][2]={
    {0,0}
};

int cartesiano[][2] = {
    {-100,0},
    {100,0},
    {0,100},
    {0,-100}
};

void orientacao(){
    glPopMatrix();
    glColor3f(0.0,0.0,1.0);
    draw("vertices",origem,1);
    glColor3f(0.0,0.0,0.0);
    draw("linhas",cartesiano,4);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400 ,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Exercicio - Castelo");

    init();
    glutDisplayFunc(desenha);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-10,10,-10,10);

}

void desenha(){

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    montanha();
    // carro();
    catavento();

    orientacao();
    glFlush();
}

void montanha(){
    glColor3f(0.0,0.6,0.3);
    glPushMatrix();
    // glTranslated(0.0,0.0,0.0);
    glScaled(8, 5, 1);
    draw("poligono",triangulo,3);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-6.0,0.0,0.0);
    glScaled(5, 4, 1);
    draw("poligono",triangulo,3);
    glPopMatrix();
    glPushMatrix();
    glTranslated(8.0,0.0,0.0);
    glScaled(7, 3, 1);
    draw("poligono",triangulo,3);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.0,-5.0,0.0);
    glScaled(10, 5, 1);
    draw("poligono",quadrado,4);
    glPopMatrix();   
    

}

void catavento(){

    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
    glTranslated(0.0,-3.0,0.0);
    glScaled(0.2, 4, 1);
    draw("poligono",quadrado,4);
    glPopMatrix();

    glPushMatrix();
    // glRotatef(10,0,0,1);
    helice();
    glPopMatrix();
}

void helice(){

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    draw("vertices",origem,1);
    glPopMatrix();

    glPushMatrix();
    // glRotatef(60,0,0,1);
    glTranslated(-1.0,2.0,0.0);
    pa();
    glPopMatrix();

    glPushMatrix();
    // glRotatef(0,0,0,1);
    glTranslated(-1.0,-4,0.0);
    pa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,0,1);
    glTranslated(-1.0,-4,0.0);
    pa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslated(-1.0,-4,0.0);
    pa();
    glPopMatrix();
}

void carro(){
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    draw("poligono",chassi,8);
    glPopMatrix();
}

void pa(){
    glPushMatrix();
    glTranslated(1,1,1);
    glScaled(0.2, 3, 1);
    draw("poligono",triangulo,3);
    glPopMatrix();
    glPushMatrix();
    glTranslated(1,1,1);
    glScaled(0.2, -3, 1);
    draw("poligono",triangulo,3);
    glPopMatrix();
}


void draw(char *tipo, int(*figura)[2], int n){

    if(!strcmp("vertices",tipo)){
        glPointSize(10);
        // glColor3f(1.0,0.0,0.0);
        glBegin(GL_POINTS);
            for(int i = 0; i < n; i++){
                glVertex2i(figura[i][0], figura[i][1]);
            }
        glEnd();
    }
    else if(!strcmp(tipo,"linhas")){
        glLineWidth(2);
        // glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
            for(int i = 0; i < n; i++){
                // printf("figura[i][0]: %d, figura[i][1]: %d\n", figura[i][0], figura[i][1]);
                glVertex2i(figura[i][0], figura[i][1]);
                if(i == n-1)glVertex2i(figura[0][0], figura[0][1]);
                else glVertex2i(figura[i+1][0], figura[i+1][1]);
            }
        glEnd();
    }
    else if(!strcmp(tipo,"poligono")){
        glPointSize(10);
        // glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        for(int i = 0; i < n; i++){
                glVertex2i(figura[i][0], figura[i][1]);
                // if(i == n-1)glVertex2i(figura[0][0], figura[0][1]);
                // else glVertex2i(figura[i+1][0], figura[i+1][1]);
        }
        glEnd();
    }

}
