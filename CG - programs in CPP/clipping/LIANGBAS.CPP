#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>


int xmin,ymin,xmax,ymax;

typedef struct vertex
{
 float x,y;
};
typedef struct
{
 float p;
 float q;
 float u;
}lb;


void lb1(vertex a,vertex b,int xmin,int ymin,int xmax,int ymax)
{
  lb c[4];

  vertex a2,b2;
  float uone=0,utwo=1;
  int i;

  c[0].p=a.x-b.x; c[0].q=a.x-xmin;
  c[1].p=b.x-a.x; c[1].q=xmax-a.x;
  c[2].p=a.y-b.y; c[2].q=a.y-ymin;
  c[3].p=b.y-a.y; c[3].q=ymax-a.y;

  for(i=0;i<4;i++)
    if(c[i].p==0&&c[i].q<0)
    {
     getch();
      printf("line parallel to %d clipping boundary and not visible" ,i);
      return;
   }

  for(i=0;i<4;i++)
    c[i].u=c[i].q/c[i].p;




  for(i=0;i<4;i++)
    if((c[i].p<0)&&(uone<c[i].u))
      uone=c[i].u;

  for(i=0;i<4;i++)
    if((c[i].p>0)&&(utwo>c[i].u))
      utwo=c[i].u;

  if(uone>utwo)
    {
      getch();
      printf("line is not visible ");
      return;
    }



      a2.x=a.x+(uone*(b.x-a.x));
      a2.y=a.y+(uone*(b.y-a.y));
      b2.x=a.x+(utwo*(b.x-a.x));
      b2.y=a.y+(utwo*(b.y-a.y));

    line((int)320+a2.x,(int)240-a2.y,(int)320+b2.x,(int)240-b2.y);
    return;
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
	scanf("%f %f",&a.x,&a.y);

	printf("Enter X(2) & Y(2) :=");
	scanf("%f %f",&b.x,&b.y);


        clearviewport();
	show_quadrant();

	line (320+a.x,240-a.y,320+b.x,240-b.y);
        getch();

	
        cleardevice();
	show_quadrant();
			
        lb1(a,b,xmin,ymin,xmax,ymax);

	getch();

        closegraph();
}
