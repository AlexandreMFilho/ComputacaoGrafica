
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//TODO colocar cores  
static int shoulder = 0, elbow = 0,shoulderx = 0,shouldery = 0,
rd1 ,rd2,rd3;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);

  glPushMatrix();


    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) shouldery, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) shoulderx, 1.0, 0.0, 0.0);


    glPushMatrix();
      glScalef (2.0, 0.4, 1.0);
      glutWireCube (1.0);
    glPopMatrix();

    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);

    glPushMatrix();
      glTranslatef (1.0, 0.0, 0.0);
      glScalef (2.0, 0.4, 1.0);
      glutWireCube (1.0);
    glPopMatrix();

    glTranslatef (2.0, 0.2, 0.0);
    glPushMatrix();
      glRotated((GLfloat) rd1,0.0,0.0,1.0);
      
      glPushMatrix();
        glTranslatef(0.25, 0.0, 0.0);
        glScaled(0.5,0.2,0.2);
        glutWireCube(1.0);
      glPopMatrix();
    glPopMatrix();

    glTranslatef (0.0, -0.4, 0.2);
    glPushMatrix();
      glRotated((GLfloat) rd2,0.0,0.0,1.0);
      
      glPushMatrix();
        glTranslatef(0.25, 0.0, 0.0);
        glScaled(0.5,0.2,0.2);
        glutWireCube(1.0);
      glPopMatrix();
    glPopMatrix();


    glTranslatef (0.0, 0.0, -0.4);
    glPushMatrix();
      glRotated((GLfloat) rd3,0.0,0.0,1.0);
      
      glPushMatrix();
        glTranslatef(0.25, 0.0, 0.0);
        glScaled(0.5,0.2,0.2);
        glutWireCube(1.0);
      glPopMatrix();
    glPopMatrix();


  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(85, (GLfloat) w/(GLfloat) h, 0.1, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0,0,5,0,0,0,0,1,0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'a':
    shouldery = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'd':
    shouldery = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  case 'P':
    rd1 = (rd1 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    rd1 = (rd1 - 5) % 360;
    glutPostRedisplay();
    break;  
  case 'i':
    rd2 = (rd2 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'I':
    rd2 = (rd2 - 5) % 360;
    glutPostRedisplay();
    break;  
  case 'm':
    rd3 = (rd3 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'M':
    rd3 = (rd3 - 5) % 360;
    glutPostRedisplay();
    break;  
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

