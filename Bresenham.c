#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void drawline(int x0, int y0,int x1,int y1)
{
int x,y,i,dx,dy,p;
   dx=x1-x0;
   dy=y1-y0;
   x=x0;
   y=y0;
   p=2*dy-dx;
   while (x<x1)
   { if(p>=0)
     { putpixel(x,y,GREEN);
     y=y+1;
     p=p+2*dy-2*dx;
     }
     else
     { putpixel(x,y,GREEN);
     p=p+2*dy;
     }
     x=x+1;
    }
   }
   int main()
   { int gdriver = DETECT,gmode,x0,y0,x1,y1;
   clrscr();
   initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
  printf("Enter co-ordinate of first point: ");
   scanf("%d\n%d",&x0,&y0);
 printf("Enter co-ordinates of second point: ");
   scanf("%d\n%d",&x1,&y1);
 drawline(x0,y0,x1,y1);
 getch();
   return 0;
   }
