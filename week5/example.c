#include <graphics.h>
 #include<stdio.h>
#include <math.h> 
int drawline(int x1,int y1,int x2,int y2)
{
    float slope=(y2-y1)/(x2-x1);
    int x=(x1<x2)?x1:x2;
    while(x<=x2)
    {
      int y2=ceil(slope*x)+y1;
       putpixel(x, y2, RED);
      int y=floor(slope*x)+y1;
        if(y2!=y)
       putpixel(x, y, BLUE);
      x+=1;
    }

}
int bresengham(int x1,int y1,int x2,int y2)
{
    float slope=(float)(y2-y1)/(x2-x1);
    int yprev=slope*x1/2+y1;;
     float x=(x1<x2)?x1:x2;
      while(x<=x2)
    {
      float ytemp=slope*x/2+y1;
      float d1=abs(ytemp-yprev);
      float d2=abs(ytemp-yprev-1);
      if(d1<d2)
      {
        putpixel(x,yprev,RED);
      }
    else if(d1>=d2)
      {
        putpixel(x,yprev+1,BLUE);
        yprev=yprev+1;
      }
      x+=1;
    }
}
int main()
{ 
   int gd = DETECT, gm;
   int x = 320, y = 240, radius;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
 // drawline(20,20,500,500);
bresengham(20,20,500,500);
int d;
 scanf("%d",&d);
   getch();
   closegraph();
   return 0;
}
