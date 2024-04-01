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
void arvore_1();
void arvore_2();
void arvore_3();
void nuvem_1();
void nuvem_2();


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
    //turbina();
    //arvore_1();
    //arvore_2();
    //arvore_3();
    //nuvem_1();
    nuvem_2();
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

void nuvem_1(){
    glColor3f(0.9,0.9,0.9);
    
    glPushMatrix();
        circulo();
    glPopMatrix();
    
    glPushMatrix();
        glTranslated(-1.6,-0.3,0.0);
        glScaled(0.7,0.7,0.0);
        circulo();
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.6,-0.3,0.0);
        glScaled(0.7,0.7,0.0);
        circulo();
    glPopMatrix();
}

void nuvem_2(){
    glColor3f(0.9,0.9,0.9);
    
    glPushMatrix();
        glScaled(2.0,2.0,0.0);
        circulo();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.9,-1.0,0.0);
        glScaled(1.3,1.3,0.0);
        circulo();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-4.8,-1.4,0.0);
        glScaled(1.0,1.0,0.0);
        circulo();
    glPopMatrix();

    glPushMatrix();
        glTranslated(3.2,-1.0,0.0);
        glScaled(1.3,1.3,0.0);
        circulo();
    glPopMatrix();


    glPushMatrix();
        glTranslated(-0.4,-1.8,0.0);
        glScaled(4.0,1.0,0.0);
        quadrado();
    glPopMatrix();

}

void arvore_1(){
    glColor3f(0.4,0.3,0.0);
    glPushMatrix();
        glScaled(0.2,1.5,0.0);
        quadrado();
    glPopMatrix();

    glColor3f(0.0,0.8,0.0);
    glPushMatrix();
        glScaled(1.0,3.0,0.0);
        triangulo();
    glPopMatrix();
}

void arvore_2(){
    glColor3f(0.0,0.8,0.0);
    glPushMatrix();
        glTranslated(0.0,3.8,0.0);
        circulo();
        glTranslated(0.0,1.5,0.0);
        circulo();
    glPopMatrix();

    glColor3f(0.4,0.3,0.0);
    glPushMatrix();
        glScaled(0.2,1.5,0.0);
        quadrado();
    glPopMatrix();

}

void arvore_3(){
    glColor3f(0.0,0.8,0.0);
    glPushMatrix();
        glTranslated(-1.0,2.0,0.0);
        circulo();
        glTranslated(-2.0,0.0,0.0);
        circulo();
        glTranslated(-1.0,1.5,0.0);
        circulo();
    glPopMatrix();

    glColor3f(0.4,0.3,0.0);
    glPushMatrix();
        glScaled(0.2,1.5,0.0);
        quadrado();
    glPopMatrix();

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