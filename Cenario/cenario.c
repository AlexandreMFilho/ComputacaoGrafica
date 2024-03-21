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
void estrada();
void ceu();
void circulo(char*);
void sol();
void roda();

void orientacao();

int frameNumber = 0;
float pos = -20.0;

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

int unitario[][2]={
    {0,1}
};

int barra[][2]={
    {0,0},
    {0,1}
};

int cartesiano[][2] = {
    {-100,0},
    {100,0},
    {0,100},
    {0,-100}
};

int raio[][2] = {
    {0,1},
    {0,2}
};

void orientacao(){
    glColor3f(0.0,0.0,1.0);
    draw("vertices",origem,1);
    glColor3f(0.0,0.0,0.0);
    draw("linhas",cartesiano,4);
}

void doFrame(int v){

    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(20,doFrame,0);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(400 ,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Exercicio - Cenario Animacao");

    init();
    glutDisplayFunc(desenha);
    glutTimerFunc(20,doFrame,0);

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
        ceu();

        montanha();

        estrada();

        // // //Catavento 1
        glPushMatrix();
            glTranslated(-8.0,7.0,0.0);
            glScaled(0.5, 0.5, 1);
            catavento();
        glPopMatrix();

        // // //Catavento 2
        glPushMatrix();
            glTranslated(-3.5,5.0,0.0);
            glScaled(0.3, 0.3, 1);
            catavento();
        glPopMatrix();

        // // //Catavento 3
        glPushMatrix();
            glTranslated(1.5,6.5,0.0);
            glScaled(0.6, 0.6, 1);
            catavento();
        glPopMatrix();


        glPushMatrix();
            glTranslated(8.0,8.0,0.0);
            sol();
        glPopMatrix();

        glPushMatrix();
            glTranslated(pos,-5.5,0.0);
            pos+= 0.1;
            if(pos >= 10)pos = -20.0;
            carro();
        glPopMatrix();

    glPopMatrix();

    // orientacao();
    
    glFlush();

    glutSwapBuffers();

}

void sol(){

    glColor3f(1.0,1.0,0.0);
    circulo("fill");
    glColor3f(1.0,0.5,0.0);
    circulo("vertices");

    glPushMatrix();
        glRotatef(frameNumber,0,0,1);
        glPushMatrix();
            for(int i = 0; i < 12; i++){
                    glRotatef(360/12,0,0,1);
                    draw("linhas",raio,2);
                }
        glPopMatrix();
    glPopMatrix();

}
void roda(){

    glPushMatrix();
        glRotatef(frameNumber,0,0,1);

        glColor3f(0.3,0.3,0.3);
        circulo("fill");
        glColor3f(0.0,0.0,0.0);
        circulo("vertices");

        glPushMatrix();
            for(int i = 0; i < 12; i++){
                glRotatef(360/12,0,0,1);
                draw("linhas",barra,2);
            }
        glPopMatrix();

    glPopMatrix();

}

void circulo(char *tipo){

    int resolucao = 2000;
    float taxa = 360.0/resolucao;
    
    if(!strcmp("fill",tipo)){
        glLineWidth(1);
        glPushMatrix();
            for(int i = 0; i < resolucao; i++){
                    glRotatef(taxa,0,0,1);
                    draw("linhas",barra,2);
            }
        glPopMatrix();
    }else{
        glPointSize(1);
        glPushMatrix();
            for(int i = 0; i < resolucao; i++){
                glRotatef(taxa,0,0,1);
                draw("vertices",unitario,1);
            }
        glPopMatrix();
    }
}

void estrada(){
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
        glTranslated(0.0,-5.0,0.0);
        glScaled(10, 2, 1);
        draw("poligono",quadrado,4);
    glPopMatrix();

    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
        glTranslated(0.0,-5.0,0.0);
        glScaled(10, 0.2, 1);
        draw("poligono",quadrado,4);
    glPopMatrix();
}

void ceu(){
    glColor3f(0.1,0.6,1.0);
    glPushMatrix();
        glTranslated(0.0,5.0,0.0);
        glScaled(10, 5, 1);
        draw("poligono",quadrado,4);
    glPopMatrix();   
    

}


void montanha(){
    glColor3f(0.0,0.6,0.3);
    glPushMatrix();
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
        glTranslated(0.0,-6.0,0.0);
        glScaled(0.2, 6, 1);
        draw("poligono",quadrado,4);
    glPopMatrix();

    glPushMatrix();
        glRotatef(frameNumber,0,0,1);
        helice();
    glPopMatrix();
}

void helice(){

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
        glPointSize(10);
        draw("vertices",origem,1);
    glPopMatrix();

    glPushMatrix();
        // glRotatef(60,0,0,1);
        glTranslated(-1.0,1.8,0.0);
        pa();
    glPopMatrix();

    glPushMatrix();
        // glRotatef(0,0,0,1);
        glTranslated(-1.0,-3,0.0);
        pa();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90,0,0,1);
        glTranslated(-1.0,-3,0.0);
        pa();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-90,0,0,1);
        glTranslated(-1.0,-3,0.0);
        pa();
    glPopMatrix();
}

void carro(){

    glPushMatrix();
        glPushMatrix();
            glScaled(0.5,0.5,1.0);
            glTranslated(2.0,-0.5,0.0);
            roda();
        glPopMatrix();

        glPushMatrix();
            glScaled(0.5,0.5,1.0);
            glTranslated(8.0,-0.5,0.0);
            roda();
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        draw("poligono",chassi,8);
    glPopMatrix();
}

void pa(){
    glPushMatrix();
        glTranslated(1,1,1);
        glScaled(0.2, 2, 1);
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
        glPointSize(5);
        glBegin(GL_POINTS);
            for(int i = 0; i < n; i++){
                glVertex2i(figura[i][0], figura[i][1]);
            }
        glEnd();
    }
    else if(!strcmp(tipo,"linhas")){
        glLineWidth(2);
        glBegin(GL_LINES);
            for(int i = 0; i < n; i++){
                glVertex2i(figura[i][0], figura[i][1]);
                if(i == n-1)glVertex2i(figura[0][0], figura[0][1]);
                else glVertex2i(figura[i+1][0], figura[i+1][1]);
            }
        glEnd();
    }
    else if(!strcmp(tipo,"poligono")){
        glPointSize(10);
        glBegin(GL_POLYGON);
        for(int i = 0; i < n; i++){
                glVertex2i(figura[i][0], figura[i][1]);
        }
        glEnd();
    }

}
