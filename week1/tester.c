#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
//Drawing funciton

void Init(){
  //Background color(r,g,b,a) a is for transparancy
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT );

  glMatrixMode(GL_PROJECTION);//used for next function
  gluOrtho2D(0,100,0,100);//gluOrthod xmin xmax,ymin ymax
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
 
  glutInitWindowSize(1000,1000);
   glutInitWindowPosition(100,10);
  glutCreateWindow("My First Computer Graphics Program!");
  //Call to the drawing function
  Init();
  glutDisplayFunc(gasket);
  glutMainLoop();
  return 0;
}
