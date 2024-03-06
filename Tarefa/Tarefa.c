#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

desenha();

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(200,200);
    glutCreateWindow("Tarefa 1 - Questão 1");

    glutDisplayFunc(desenha);


    glutMainLoop();

    return EXIT_SUCCESS;
}