#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<math.h>
//Drawing funciton

void drawinnertriangles(float x1,float y1,float x2,float y2,float x3,float y3,int ctr);

void gasket()
{

		int ctr=10;
	float X1=20.0,Y1=20.0,X2=70.0,Y2=20.0,X3=45,Y3=63.3;
  	
	drawinnertriangles(X1,Y1,X2,Y2,X3,Y3,ctr);
	glFlush();

}

void drawinnertriangles(float x1,float y1,float x2,float y2,float x3,float y3,int ctr)
{
		if(ctr==0)
		{
			return;
		}
		else{
			
			
			if(ctr==1)
			{glBegin(GL_POLYGON);
				glColor3f(1,1,1);	
				printf("android\n");
				glVertex2f(x1,y1);
			glVertex2f(x2,y2);
			glVertex2f(x3,y3);
				
			glEnd();
			}
			else
			{
				glBegin(GL_POLYGON);
				glColor3f(0,0,0);
				printf("naughet\n");	
				glVertex2f(x1,y1);
			glVertex2f(x2,y2);
			glVertex2f(x3,y3);
				
			glEnd();
			}
		
			
			float mx1=(x1+x3)/2;
			float my1=(y1+y3)/2;
			float nx1=(x1+x2)/2;
			float ny1=(y1+y2)/2;
			float px1=(x2+x3)/2;
			float py1=(y2+y3)/2;

			printf("%f %f %f %f %f %f \n",x1,x2,x3,mx1,nx1,px1);
			printf("%f %f %f %f %f %f \n",y1,y2,y3,my1,ny1,py1);
			drawinnertriangles(x1,y1,nx1,ny1,mx1,my1,ctr-1);
			drawinnertriangles(mx1,my1,x3,y3,px1,py1,ctr-1);
			drawinnertriangles(nx1,ny1,px1,py1,x2,y2,ctr-1);


		}


}

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
