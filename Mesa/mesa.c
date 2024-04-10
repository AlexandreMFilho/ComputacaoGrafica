#include <GL/glut.h>


void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();



  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);


  glRotated(30, 1.0, 1.0, 0.0);
  //Tabua
  glPushMatrix();
  //glTranslatef(1, 0.0, -3.0);
  glScaled(15.0, 1.0, 10.0);
  glutWireCube(1.0);
  glPopMatrix();

  //Pernas
  glPushMatrix();
  glTranslatef(5.0, -3.5, -3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5.0, -3.5, +3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5.0, -3.5, -3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5.0, -3.5, +3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutWireCube(1.0);
  glPopMatrix();


  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHT1);



  glFlush();
}





void init() {

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);


  GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat pink[] = { 1.0, 0.5, 1.0, 1.0 };
  GLfloat pink2[] = { 0.5, 1.0, 0.5, 1.0 };
  GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
  GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
  GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat direction[] = { 0.0, 0.0, 1.0, 1.0 };
  GLfloat direction1[] = { 0.0,0.0, 1.0, 1.0 };

  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);
  glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  glMaterialf(GL_FRONT, GL_SHININESS, 50);



  glLightfv(GL_LIGHT0, GL_AMBIENT, black);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
  glLightfv(GL_LIGHT0, GL_SPECULAR, white);
  glLightfv(GL_LIGHT0, GL_POSITION, direction);

  glLightfv(GL_LIGHT1, GL_AMBIENT, black);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
  glLightfv(GL_LIGHT1, GL_SPECULAR, white);
  glLightfv(GL_LIGHT1, GL_POSITION, direction1);

  glEnable(GL_LIGHTING);                // so the renderer considers light
  glEnable(GL_LIGHT0);                  // turn LIGHT0 on
  glEnable(GL_LIGHT1);
  glEnable(GL_DEPTH_TEST);              // so the renderer considers depth


}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Mesa");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}