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
 float x,y;
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

void su_co(vertex a,vertex b,int xmin,int ymin,int xmax,int ymax)
{
  vertex a2,b2;

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
      setcolor(4);
      line((int)320+a.x,(int)240-a.y,(int)320+b.x,(int)240-b.y);
      return;
    }

  if(and(a,b))
    {
     return;
    }



  float  m, m1=(b.y-a.y),m2=(b.x-a.x);
  float xn1=a.x,yn1=a.y,xn2=b.x,yn2=b.y;

  if(m1==0)
	m=0.001;
     else if(m2==0)
		m=1000;
	  else
	     m=m1/m2;

  if(a.t==1)
   {
     xn1=a.x+(ymax-a.y)/m;
     yn1=ymax;
   }
  if(a.b==1)
   {
    xn1=a.x+(ymin-a.y)/m;
    yn1=ymin;
    }
  if(a.r==1)
    {
     yn1=a.y+(xmax-a.x)*m;
     xn1=xmax;
    }
  if(a.l==1)
  {
   yn1=a.y+(xmin-a.x)*m;
   xn1=xmin;
  }
  if(b.t==1)
  {
   xn2=b.x+(ymax-b.y)/m;
   yn2=ymax;
  }
  if(b.b==1)
  {
   xn2=b.x+(ymin-b.y)/m;
   yn2=ymin;
  }
  if(b.r==1)
  {
   yn2=b.y+(xmax-b.x)*m;
   xn2=xmax;
  }
  if(b.l==1)
  {
   yn2=b.y+(xmin-b.x)*m;
   xn2=xmin;
  }

  a2.x=xn1;
  a2.y=yn1,
  b2.x=xn2;
  b2.y=yn2;

  su_co(a2,b2,xmin,ymin,xmax,ymax);
}
void show_quadrant()
{
  cleardevice();
  setcolor(5);
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
	scanf("%f %f",&a.x,&a.y);

	printf("Enter X(2) & Y(2) :=");
	scanf("%f %f",&b.x,&b.y);


	clearviewport();
	show_quadrant();

	setcolor(3);
	line ((int)320+a.x,(int)240-a.y,(int)320+b.x,(int)240-b.y);
	getch();


	cleardevice();
	show_quadrant();

	su_co(a,b,xmin,ymin,xmax,ymax);

	getch();

	closegraph();
}
