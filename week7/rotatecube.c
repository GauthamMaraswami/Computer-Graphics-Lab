#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
#define RAD (3.142/180.0)
 GLfloat xRotated, yRotated, zRotated;
int x=1,y,z;
static GLfloat vert[][4]={
{ 1.0f, 1.0f, 1.0f},
{-1.0f, 1.0f, 1.0f},
{-1.0f, -1.0f, 1.0f},
{ 1.0f, -1.0f, 1.0f},
{ 1.0f, 1.0f, -1.0f},
{-1.0f, 1.0f, -1.0f},
{-1.0f, -1.0f, -1.0f},
{ 1.0f, -1.0f, -1.0f},
};


void Init(){
  
glClearColor(0,0,0,0);
  int x=50;
int y=50;
  glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  
}

void DrawCube(void)
{

     glMatrixMode(GL_MODELVIEW);
  
    glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
        glTranslatef(0.0,0.0,-10.5);
if(x==1)
{
    glRotatef(xRotated,1.0,0.0,0.0);
}
else if(y==1)
    glRotatef(yRotated,0.0,1.0,0.0);
else if(z==1)
    glRotatef(zRotated,0.0,0.0,1.0);
  glBegin(GL_QUADS);       
    glColor3f(0.0f,1.0f,0.0f);    
    glVertex3f( 1.0f, 1.0f, 1.0f);   
    glVertex3f( -1.0f, 1.0f, 1.0f); 
     glVertex3f( -1.0f, -1.0f, 1.0f); 
     glVertex3f( 1.0f, -1.0f, 1.0f); 
    glColor3f(1.0f,0.5f,0.0f);    
     glVertex3f( 1.0f, 1.0f, -1.0f); 
    glVertex3f( -1.0f, 1.0f, -1.0f); 
     glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f( 1.0f, -1.0f, -1.0f); 
    glColor3f(1.0f,0.0f,0.0f);   
    glVertex3f( 1.0f, 1.0f, 1.0f); 
 glVertex3f( -1.0f, 1.0f, 1.0f); 
 glVertex3f( -1.0f, 1.0f, -1.0f); 
 glVertex3f( 1.0f, 1.0f, -1.0f); 
    glColor3f(1.0f,1.0f,0.0f);   
      glVertex3f( -1.0f, -1.0f, 1.0f); 
 glVertex3f( 1.0f, -1.0f, 1.0f); 
 glVertex3f( 1.0f, -1.0f, -1.0f); 
 glVertex3f( -1.0f, -1.0f, -1.0f); 
    glColor3f(0.0f,0.0f,1.0f);    
        glVertex3f( 1.0f, -1.0f, 1.0f); 
 glVertex3f(1.0f, 1.0f, 1.0f); 
 glVertex3f( 1.0f, 1.0f, -1.0f); 
 glVertex3f( 1.0f, -1.0f, -1.0f); 
    glColor3f(1.0f,0.0f,1.0f);    
       glVertex3f( -1.0f, 1.0f, 1.0f); 
 glVertex3f( -1.0f, -1.0f, 1.0f); 
 glVertex3f(-1.0f, -1.0f, -1.0f); 
 glVertex3f( -1.0f, 1.0f, -1.0f); 
  glEnd();           
glFlush();
}



void idle()
{
 
     yRotated += 0.01;
     xRotated += 0.02;
    DrawCube();
}

void keyboardtest(unsigned char key, int x, int y){
	//printf("handy");
	if(key=='x')	
	{
		x=1;
    y=0;
    z=0;
  DrawCube();
	}
if(key=='y')	
	{
		x=0;
    y=1;
    z=0;
  DrawCube();	
}
if(key=='z')	
	{
		x=0;
    y=0;
    z=1;
	}
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutCreateWindow(argv[0]);
Init();
glutKeyboardFunc(keyboardtest);
glutDisplayFunc(DrawCube);

glutIdleFunc(idle);
glutMainLoop();
return 0;

}
