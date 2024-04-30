#include <GL/glut.h>

void mesa(){

    glNormal3f(0,0,1);
  //Tabua
  glPushMatrix();
  //glTranslatef(1, 0.0, -3.0);
  glScaled(15.0, 1.0, 10.0);
  glutSolidCube(1.0);
  glPopMatrix();

  //Pernas
  glPushMatrix();
  glTranslatef(5.0, -3.5, -3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix(); 
  glTranslatef(5.0, -3.5, +3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5.0, -3.5, -3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5.0, -3.5, +3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

}

void cadeira(){
    
  //Tabua
  glPushMatrix();
  //glTranslatef(1, 0.0, -3.0);
  glScaled(4.0, 0.5, 4.0);
  glutSolidCube(1.0);
  glPopMatrix();

  //Pernas
  glPushMatrix();
  glTranslatef(5.0, -3.5, -3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 4.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix(); 
  glTranslatef(5.0, -3.5, +3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5.0, -3.5, -3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5.0, -3.5, +3.0);
  glRotated(30, 0.0, 1.0, 0.0);
  glScaled(1.0, 6.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();

} 

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  
  glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
  
  glPushMatrix();
    glTranslatef(0.0,0.0,1.0);
    glRotated(30, 1.0, 1.0, 0.0);
    glColor3f(0.0,1.0,0.0);    
    mesa();
  glPopMatrix();
	
	glDisable(GL_LIGHTING);  
  glFlush();
}







void init() {


int BRASS         =  0;
int BRONZE        =  1;
int CHROME        =  2;
int COPPER        =  3;
int GOLD          =  4;
int PEWTER        =  5;
int SILVER        =  6;
int JADE          =  7;
int OBSIDIAN      =  8;
int PEARL         =  9;
int RUBY          = 10;
int TURQUOISE     = 11;
int BLACK_PLASTIC = 12;
int BLACK_RUBBER  = 13;

int LAST_MATERIAL = 14;

int material = -1;



float SPECULAR_EXPONENTS[] =
{
   27.897400, // BRASS
   25.600000, // BRONZE
   76.800003, // CHROME
   12.800000, // COPPER
   51.200001, // GOLD
   09.846150, // PEWTER
   51.200001, // SILVER
   76.800003, // EMERALD
   12.800000, // JADE
   38.400002, // OBSIDIAN
   11.264000, // PEARL
   76.800003, // RUBY
   12.800000, // TURQUOISE
   32.000000, // BLACK_PLASTIC
   10.000000  // BLACK_RUBBER
};


float MATERIAL_COLORS[][3][4] =
{
   // BRASS 0
   {
      {0.329412, 0.223529, 0.027451, 1.000000}, // Ambient RGBA
      {0.780392, 0.568627, 0.113725, 1.000000}, // Diffuse RGBA
      {0.992157, 0.941176, 0.807843, 1.000000}  // Specular RGBA
   },

   // BRONZE 1
   {
      {0.212500, 0.127500, 0.054000, 1.000000},
      {0.714000, 0.428400, 0.181440, 1.000000},
      {0.393548, 0.271906, 0.166721, 1.000000}
   },

   // CHROME 2
   {
      {0.250000, 0.250000, 0.250000, 1.000000},
      {0.400000, 0.400000, 0.400000, 1.000000},
      {0.774597, 0.774597, 0.774597, 1.000000}
   },

   // COPPER 3
   {
      {0.191250, 0.073500, 0.022500, 1.000000},
      {0.703800, 0.270480, 0.082800, 1.000000},
      {0.256777, 0.137622, 0.086014, 1.000000}
   },

   // GOLD 4
   {
      {0.247250, 0.199500, 0.074500, 1.000000},
      {0.751640, 0.606480, 0.226480, 1.000000},
      {0.628281, 0.555802, 0.366065, 1.000000}
   },

   // PEWTER 5
   {
      {0.105882, 0.058824, 0.113725, 1.000000},
      {0.427451, 0.470588, 0.541176, 1.000000},
      {0.333333, 0.333333, 0.521569, 1.000000}
   },

   // SILVER 6
   {
      {0.192250, 0.192250, 0.192250, 1.000000},
      {0.507540, 0.507540, 0.507540, 1.000000},
      {0.508273, 0.508273, 0.508273, 1.000000}
   },

   // EMERALD 7
   {
      {0.021500, 0.174500, 0.021500, 0.550000},
      {0.075680, 0.614240, 0.075680, 0.550000},
      {0.633000, 0.727811, 0.633000, 0.550000}
   },

   // JADE 8
   {
      {0.135000, 0.222500, 0.157500, 0.950000},
      {0.540000, 0.890000, 0.630000, 0.950000},
      {0.316228, 0.316228, 0.316228, 0.950000}
   },

   // OBSIDIAN 9
   {
      {0.053750, 0.050000, 0.066250, 0.820000},
      {0.182750, 0.170000, 0.225250, 0.820000},
      {0.332741, 0.328634, 0.346435, 0.820000}
   },

   // PEARL 10
   {
      {0.250000, 0.207250, 0.207250, 0.922000},
      {1.000000, 0.829000, 0.829000, 0.922000},
      {0.296648, 0.296648, 0.296648, 0.922000}
   },

   // RUBY 11
   {
      {0.174500, 0.011750, 0.011750, 0.550000},
      {0.614240, 0.041360, 0.041360, 0.550000},
      {0.727811, 0.626959, 0.626959, 0.550000}
   },

   // TURQUOISE 12
   {
      {0.100000, 0.187250, 0.174500, 0.800000},
      {0.396000, 0.741510, 0.691020, 0.800000},
      {0.297254, 0.308290, 0.306678, 0.800000}
   },

   // BLACK_PLASTIC 13
   {
      {0.000000, 0.000000, 0.000000, 1.000000},
      {0.010000, 0.010000, 0.010000, 1.000000},
      {0.500000, 0.500000, 0.500000, 1.000000}
   },

   // BLACK_RUBBER 14
   {
      {0.020000, 0.020000, 0.020000, 1.000000},
      {0.010000, 0.010000, 0.010000, 1.000000},
      {0.400000, 0.400000, 0.400000, 1.000000}
   }
};



  glLoadIdentity();
  glOrtho(-10.0, 10.0, -10.0, 10.0 , 10.0 , -10.0);

  // GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat black[] = { 0.0, 15.0, 15.0, 1.0 };
  GLfloat pink[] = { 1.0, 0.5, 1.0, 1.0 };
  GLfloat pink2[] = { 0.5, 1.0, 0.5, 1.0 };
  // GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
  GLfloat yellow[] = { 0.0, -15.0, 15.0, 1.0 };
  GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
  GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat direction[] = { 0.0, 0.0, 1.0, 1.0 };
  GLfloat direction1[] = { 0.0,0.0, 1.0, 1.0 };


  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, white);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
  glMaterialf(GL_FRONT, GL_SHININESS, 50);
  
  //	---- Definindo o vetor normal
  //glNormal3f(0,0,1);
  //float normalArray[3] = {0.577,0.577,0.577};
  //glNormal3fv(normalArray);



  glLightfv(GL_LIGHT0, GL_AMBIENT, black);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
  // glLightfv(GL_LIGHT0, GL_SPECULAR, white);
  // glLightfv(GL_LIGHT0, GL_POSITION, direction);

  // glLightfv(GL_LIGHT1, GL_AMBIENT, black);
  // glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
  // glLightfv(GL_LIGHT1, GL_SPECULAR, white);
  // glLightfv(GL_LIGHT1, GL_POSITION, direction1);

  glEnable(GL_LIGHTING);                // so the renderer considers light
  glEnable(GL_LIGHT0);                  // turn LIGHT0 on
  // glEnable(GL_LIGHT1);
  glEnable(GL_DEPTH_TEST);              // so the renderer considers depth


}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Mesa");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
