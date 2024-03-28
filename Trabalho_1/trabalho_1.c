#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/glut.h>

#define W_WIDTH 500
#define W_HEIGHT 500

void desenha();
void triangulo();
void quadrado();
void circulo();

void turbina();


int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W_WIDTH,W_HEIGHT);
    glutCreateWindow("Trabalho 1 - Game Side Scrolling");
    glClearColor(0.5,0.0,0.8,1.0);
    //glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(-20,20,-20,20);

    glutDisplayFunc(desenha);

    glutMainLoop();

    return 0;
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    
    glPushMatrix();
    turbina();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}

void triangulo(){
    glBegin(GL_POLYGON);
        glVertex2f(-1.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(0.0,1.0);
    glEnd();
}

void quadrado()
{
    glBegin(GL_POLYGON);
        glVertex2f(-1,1);
        glVertex2f(1,1);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();
}

void circulo(){
    for(int i=0;i<360;i++){
    glRotated(i,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(-1,1);
        glVertex2f(1,1);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();
    }
}


void turbina(){
    glColor3f(0.6,0.6,0.6);
    glPushMatrix();
        glScaled(0.2,10.0,0.0);
        triangulo();
    glPopMatrix();

    glColor3f(0.2,0.0,0.5);
    glPushMatrix();
        glTranslated(0.0,8.0,0.0);
        glRotated(10,0,0,1);//FrameNUMBER
        glPushMatrix();
            glScaled(0.3,0.3,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glScaled(0.2,6.0,0.0);
            triangulo();
        glPopMatrix();

        glPushMatrix();
            glRotated(120,0,0,1);
            glScaled(0.2,6.0,0.0);
            triangulo();
        glPopMatrix();

        glPushMatrix();
            glRotated(-120,0,0,1);
            glScaled(0.2,6.0,0.0);
            triangulo();
        glPopMatrix();
    glPopMatrix();
}