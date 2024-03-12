
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
void draw(char*,int(*)[2],int);

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
//	glLoadIdentity();

	//SOL
	glPushMatrix();
	glTranslated(6.0,6.0,0);
    draw("linhas",quadrado,4);
    glRotatef(45, 0,0,1);
    draw("linhas",quadrado,4);
    glPopMatrix();
   
	//Porta
	glPushMatrix();
    glTranslated(0,0,0);
    glScaled(0.8, 1.2, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();

	//muro    
	glPushMatrix();
    glTranslated(0,0.6,0);
    glScaled(2.4, 1.8, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();

    //muroEsquerdo
	glPushMatrix();
    glTranslated(3.4,1,0);
    glScaled(1, 2.2, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();

    //muroDireito
	glPushMatrix();
    glTranslated(-3.4,1,0);
    glScaled(1, 2.2, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();

	//Torre
	glPushMatrix();
    glTranslated(0,3.6,0);
    glScaled(1, 1.2, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();

    //TelhadoCentral
	glPushMatrix();
    glTranslated(0,4.8,0);
    glScaled(1,1.6,0);
    draw("linhas",triangulo,3); 
	glPopMatrix();


    //TelhadoEsquerdo
	glPushMatrix();
    glTranslated(3.4,3.2,0);
    glScaled(1,1.6,0);
    draw("linhas",triangulo,3); 
	glPopMatrix();

    //TelhadoDireito
	glPushMatrix();
    glTranslated(-3.4,3.2,0);
    glScaled(1,1.6,0);
    draw("linhas",triangulo,3); 
	glPopMatrix();

	//janelacentral
	glPushMatrix();
    glTranslated(0,4,0);
    glScaled(0.2, 0.4, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();

    //janelaesquerda
	glPushMatrix();
    glTranslated(3.6,2.4,0);
    glScaled(0.2, 0.4, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();

    //janeladireita
    glPushMatrix();
    glTranslated(-3.6,2.4,0);
    glScaled(0.2, 0.4, 1);
    draw("linhas",quadrado,4); 
	glPopMatrix();



//    draw("vertices",quadrado,4); 
//    draw("vertices",triangulo,3);
//    draw("linhas",triangulo,3);
    glPopMatrix();
    glFlush();
}

void draw(char *tipo, int(*figura)[2], int n){

    if(!strcmp("vertices",tipo)){
        glPointSize(10);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POINTS);
            for(int i = 0; i < n; i++){
                glVertex2i(figura[i][0], figura[i][1]);
            }
        glEnd();
    }
    else if(!strcmp(tipo,"linhas")){
        glLineWidth(2);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
            for(int i = 0; i < n; i++){
                // printf("figura[i][0]: %d, figura[i][1]: %d\n", figura[i][0], figura[i][1]);
                glVertex2i(figura[i][0], figura[i][1]);
                if(i == n-1)glVertex2i(figura[0][0], figura[0][1]);
                else glVertex2i(figura[i+1][0], figura[i+1][1]);
            }
        glEnd();
    }

}
