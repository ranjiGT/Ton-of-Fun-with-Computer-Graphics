#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>


int xmin,ymin,xmax,ymax;

class vertex
{
 public :
 int x,y;
 int l,r,t,b;
 vertex()
 {
   l=r=t=b=0;
 }
 void vert()
 {
   l=r=t=b=0;
 }
};                  

int and(vertex a,vertex b)
{
   if(a.r*b.r)
     return 1;
   if(a.t*b.t)
     return 1;
   if(a.l*b.l)
     return 1;
   if(a.b*b.b)
     return 1;
   return 0;
}


void su_mi(vertex a,vertex b,int xmin,int ymin,int xmax,int ymax)
{
  a.vert();
  b.vert();

  if(a.y>ymax)
	 a.t=1;
  if(a.y<ymin)
	 a.b=1;
  if(a.x>xmax)
	 a.r=1;
  if(a.x<xmin)
	 a.l=1;

  if(b.y>ymax)
	 b.t=1;
  if(b.y<ymin)
	 b.b=1;
  if(b.x>xmax)
	 b.r=1;
  if(b.x<xmin)
	 b.l=1;


  if(a.t==0&&a.r==0&&a.b==0&&a.l==0&&b.t==0&&b.r==0&&b.b==0&&b.l==0)
    {
      line(320+a.x,240-a.y,320+b.x,240-b.y);
      return;
    }

  if(and(a,b))
    {
     return;
    }

  vertex n,p;
  n.x=(a.x+b.x)/2,n.y=(a.y+b.y)/2;
  p.x=abs(a.x-b.x),p.y=abs(a.y-b.y);

  if(p.x<=1||p.y<=1)
   return;
  su_mi(a,n,xmin, ymin,xmax,ymax);
  su_mi(n,b,xmin,ymin,xmax,ymax);
}
void show_quadrant()
{
  cleardevice();
  line(320,0,320,480);
  rectangle(0,240,640,240);

  line(320+xmin,240-ymin,320+xmin,240-ymax);
  line(320+xmin,240-ymax,320+xmax,240-ymax);
  line(320+xmax,240-ymax,320+xmax,240-ymin);
  line(320+xmax,240-ymin,320+xmin,240-ymin);
  outtextxy(310,230,"O");
  outtextxy(530,240,"X");
  outtextxy(320,450,"-Y");
  outtextxy(100,240,"-X");
  outtextxy(320,30,"Y");
}


void main()
{
	clrscr();
	
        int gd=DETECT,gm;
	
	vertex a,b;  
 
        initgraph(&gd,&gm,"c:\\tc\\bgi");  
 
        printf("\nEnter The Co-Ordinates Of The Clipping Window.");
	printf("\nEnter X(min) & Y(min) :=");
	scanf("%d %d", &xmin,&ymin);
	printf("Enter X(max) & Y(max) :=");
	scanf("%d %d", &xmax,&ymax);
	printf("\nEnter The Co-Ordinates Of The Line.");
	printf("\nEnter X(1) & Y(1) :=");
	scanf("%d %d",&a.x,&a.y);

	printf("Enter X(2) & Y(2) :=");
	scanf("%d %d",&b.x,&b.y); 


        clearviewport();
	show_quadrant();

	line (320+a.x,240-a.y,320+b.x,240-b.y);
        getch();

	
        cleardevice();
	show_quadrant();
			
        su_mi(a,b,xmin,ymin,xmax,ymax);

	getch();

        closegraph();
}
