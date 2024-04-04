#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/glut.h>

#define W_WIDTH 1500
#define W_HEIGHT 300

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
void nuvem_3();
void montanha();
void casa();
void telhado();
void cenario();
void dot();

int dot_ = 0;

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W_WIDTH,W_HEIGHT);
    glutCreateWindow("Trabalho 1 - Game Side Scrolling");
    glClearColor(0.5,0.0,0.8,1.0);
    // glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(-100,100,-20,20);

    glutDisplayFunc(desenha);

    glutMainLoop();

    return 0;
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    cenario();
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

void dot(){
    if(dot_){
        glPushMatrix();
            glColor3f(0.0,0.0,0.0);
            glScaled(0.3,0.3,0.0);
            circulo();
        glPopMatrix();
    }
}

void cenario(){

    //chao
    glPushMatrix();
    glColor3f(0.0,0.8,0.0);
        glTranslated(-50.0,-20.0,0.0);
        glScaled(300.0,5.0,0.0);
        quadrado();
    glPopMatrix();

    //Montanha
    glPushMatrix();
        glTranslated(-50.0,0.0,0.0);
        glPushMatrix();
            glTranslated(20.0,-15.0,0.0);
            glScaled(2.0,2.0,0.0);
            montanha();

            glTranslated(-30.0,0.0,0.0);
            glScaled(0.8,0.8,0.0);
            montanha();

            glTranslated(15.0,0.0,0.0);
            glScaled(0.8,0.8,0.0);
            montanha();
        glPopMatrix();

        glTranslated(100.0,0.0,0.0);
        glPushMatrix();
            glTranslated(20.0,-15.0,0.0);
            glScaled(2.0,2.0,0.0);
            montanha();

            glTranslated(-30.0,0.0,0.0);
            glScaled(0.8,0.8,0.0);
            montanha();

            glTranslated(15.0,0.0,0.0);
            glScaled(0.8,0.8,0.0);
            montanha();
        glPopMatrix();
    glPopMatrix();

    //Morro
    glPushMatrix();
        glColor3f(0.0,0.8,0.0);
        glTranslated(-65.0,-20.0,0.0);
        glScaled(15.0,6.0,0.0);
        circulo();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.0,0.8,0.0);
        glTranslated(0.0,-15.0,0.0);
        glScaled(15.0,6.0,0.0);
        circulo();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0,0.8,0.0);
        glTranslated(65.0,-20.0,0.0);
        glScaled(15.0,6.0,0.0);
        circulo();
    glPopMatrix();

    //Arvores
    glPushMatrix();
        glTranslated(-80.0,-15.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();

        glTranslated(5.0,3.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();

        glTranslated(8.0,-1.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();

        glTranslated(4.0,2.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();
    glPopMatrix();

        glPushMatrix();
        glTranslated(-10.0,-10.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();

        glTranslated(5.0,3.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();

        glTranslated(8.0,-1.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();

        glTranslated(4.0,2.0,0.0);
        glScaled(1.0,1.0,0.0);
        arvore_1();
    glPopMatrix();



    //Nuvens
    glPushMatrix();
        glTranslated(0.0,0.0,0.0);//frame
        glPushMatrix();
            glTranslated(-35.0,15.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_1();

            glTranslated(15.0,-3.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_2();

            glTranslated(20.0,-2.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_3();
        glPopMatrix();
        
        glPushMatrix();
            glTranslated(35.0,15.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_1();

            glTranslated(15.0,-3.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_2();

            glTranslated(20.0,-2.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_3();
        glPopMatrix();



            glPushMatrix();
            glTranslated(-50.0,18.0,0.0);
            glScaled(-1.0,1.0,0.0);
            nuvem_1();

            glTranslated(15.0,-3.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_2();

            glTranslated(20.0,-2.0,0.0);
            glScaled(1.0,1.0,0.0);
            nuvem_3();
        glPopMatrix();
    glPopMatrix();

    //Casas
    glPushMatrix();
        glTranslated(20.0,-15.0,0.0);
        glScaled(0.5,0.5,0.0);
        casa();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-30.0,-15.0,0.0);
        glScaled(0.5,0.5,0.0);
        casa();
    glPopMatrix();

    //Cataventos
    glPushMatrix();
        glTranslated(-60.0,-15.0,0.0);
        glScaled(1.5,1.5,0.0);
        turbina();

        glTranslated(35.0,0.0,0.0);
        glScaled(1.3,1.3,0.0);
        turbina();

        glTranslated(40.0,0.0,0.0);
        glScaled(0.9,0.9,0.0);
        turbina();

    
}

void casa(){
    glPushMatrix();

        glTranslated(3.0,3.0,0.0);
        glPushMatrix();

            glTranslated(-8.5,-1.0,0.0);
            glColor3f(0.8,0.0,0.0);
            glPushMatrix();
                glTranslated(0.0,3.0,0.0);
                glScaled(3.0,2.0,0.0);
                quadrado();
            glPopMatrix();

            glPushMatrix();
                glTranslated(-3.0,2.0,0.0);
                glScaled(1.0,3.0,0.0);
                triangulo();
            glPopMatrix();

            glColor3f(0.5,0.2,0.5);
            glPushMatrix();
                glScaled(3.0,2.0,0.0);
                quadrado();
            glPopMatrix();

            glColor3f(0.0,0.0,0.8);
            glPushMatrix();
                glTranslated(0.0,-1.0,0.0);
                glScaled(2.0,1.0,0.0);
                quadrado();
            glPopMatrix();

        glPopMatrix();

        glPushMatrix();
        glColor3f(0.1,0.8,0.5);
            glTranslated(0.0,0.0,0.0);
            glScaled(5.5,3.0,0.0);
            quadrado();
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.5,0.5,0.5);
            glTranslated(1.0,-1.0,0.0);
            glScaled(1.0,2.0,0.0);
            quadrado();
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.5,0.0,0.5);
            glTranslated(4.0,0.0,0.0);
            glScaled(1.0,1.0,0.0);
            quadrado();
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.5,0.0,0.5);
            glTranslated(-1.5,0.0,0.0);
            glScaled(1.0,1.0,0.0);
            quadrado();
            glTranslated(-2.5,0.0,0.0);
            glScaled(1.0,1.0,0.0);
            quadrado();
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.8,0.0,0.0);
            glTranslated(0.0,3.0,0.0);
            glScaled(3.0,2.0,0.0);
            telhado();
        glPopMatrix();

    dot();

    glPopMatrix();
    }

    void telhado(){
        glColor3f(0.8,0.0,0.0);
        glPushMatrix();
            glBegin(GL_POLYGON);
                glVertex2f(-2.0,0.0);
                glVertex2f(-2.0,2.0);
                glVertex2f(2.0,1.0);
                glVertex2f(2.0,0.0);
            glEnd();
            glPopMatrix();
    glPopMatrix();
}

void montanha(){

    glColor3f(0.4,0.5,0.4);
    glPushMatrix();
        glScaled(10.0,10.0,0.0);
        triangulo();
    glPopMatrix();

    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
        glTranslated(0.0,7.,0.0);
        glScaled(3.0,3.0,0.0);
        triangulo();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-1.6,7.0,0.0);
        glRotated(45,0,0,1);
        glScaled(1.0,1.0,0.0);
        quadrado();
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.5,7.0,0.0);
        glRotated(45,0,0,1);
        glScaled(1.0,1.0,0.0);
        quadrado();
    glPopMatrix();

    dot();




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

    dot();
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

    dot();

}

void nuvem_3(){
    glColor3f(0.9,0.9,0.9);

    glPushMatrix();
        glColor3f(0.9,0.9,0.9);
        glPushMatrix();
            glTranslated(0.0,4.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,3.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,-1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(4.0,1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,-1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();
        
        glPushMatrix();
            glTranslated(0.0,1.0,0.0);
            glScaled(1.0,1.0,0.0);
            circulo();
        glPopMatrix();
    glPopMatrix();

glPushMatrix();
        glScaled(-1.0,1.0,0.0);
        glColor3f(0.9,0.9,0.9);

        glPushMatrix();
            glTranslated(2.0,3.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,-1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(4.0,1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,-1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,1.0,0.0);
            glScaled(2.0,2.0,0.0);
            circulo();
        glPopMatrix();
        
        glPushMatrix();
            glTranslated(0.0,1.0,0.0);
            glScaled(1.0,1.0,0.0);
            circulo();
        glPopMatrix();
    glPopMatrix();


    dot();
    
}

void arvore_1(){
    glColor3f(0.4,0.3,0.0);
    glPushMatrix();
        glScaled(0.2,1.5,0.0);
        quadrado();
    glPopMatrix();

    glColor3f(0.4,0.8,0.0);
    glPushMatrix();
        glScaled(1.0,3.0,0.0);
        triangulo();
    glPopMatrix();

    dot();
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

    dot();

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
    dot();

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

    dot();
}