#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<math.h>
//Drawing funciton

void Init(){
  //Background color(r,g,b,a) a is for transparancy
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT );

  glMatrixMode(GL_PROJECTION);//used for next function
  gluOrtho2D(0,1000,0,1000);//gluOrthod xmin xmax,ymin ymax
}
int wx=1000,wy=1000;
int r=0,g=0,b=0;
int temp=5,flag=0;
void display(int x1,int y1)
{
	if(flag==0)
	{
		glBegin(GL_POLYGON);
		glColor3f(r,g,b);
		 glVertex2f(x1-temp,y1-temp);
		 glVertex2f(x1-temp,y1+temp);
		 glVertex2f(x1+temp,y1+temp);
		 glVertex2f(x1+temp,y1-temp);
		//printf("test");
		glEnd();
		glFlush();
				

	}
	else if(flag==1)
	{
		glBegin(GL_POLYGON);
		glColor3f(r,g,b);
		 glVertex2f(x1-temp,y1-temp);
		 glVertex2f(x1-temp,y1+temp);
		 glVertex2f(x1+temp,y1+temp);
		
		printf("test");
		glEnd();
		glFlush();
	}

}
void mousefunction(int button, int state, int x, int y)
{
	int x1=x;
	int y1=wy-y;
	
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
		{
			display(x1,y1);
			
		}
}
void keyboardtest(unsigned char key, int x, int y){
	//printf("handy");
	if(key=='r')	
	{
		r=1;
		 g=0;
		b=0;
	}
	else if(key=='g')
	{
		r=0;
		 g=1;
		b=0;
	}
	else if(key=='b')
	{
		r=0;
		 g=0;
		b=1;
	}
	else if(key=='+')
	{
		temp++;
	}
	else if(key=='-')
	{
		temp--;
	}
	else if(key=='t')
	{
		flag=1;
	}
	else if(key=='s')
	{
		flag=0;
	}
	else if(key=='q')
	{
		exit(0);
	}

}
void displayfunct(){


glFlush();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
 
  glutInitWindowSize(1000,1000);
   glutInitWindowPosition(100,10);
  glutCreateWindow("test!");
  //Call to the drawing function
  Init();
  glutDisplayFunc(displayfunct);
  glutKeyboardFunc(keyboardtest);
  glutMouseFunc(mousefunction); 

 glutMainLoop();
  return 0;
}
