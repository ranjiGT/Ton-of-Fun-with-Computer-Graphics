#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void draw_el(int rx,int ry,int p,int q)
{
  float x,y,z,w,m,l,f,j,n,v,h;
  float d1,d2;
  float dx,dy;

  x=0;
  y=ry;

  z=ry*ry;
  w=rx*rx;
  m=w*ry;
  l=0.25*w;

  d1=(z-m+l);
  dy=2*w*y;
  dx=2*z*x;

  while(dx<dy)
   {
    putpixel(x+320+p,y+240-q,2);
    putpixel(x+320+p,-y+240-q,2);
    putpixel(-x+320+p,y+240-q,2);
    putpixel(-x+320+p,-y+240-q,2);

    if(d1<0)
    {
     x=x+1;
     dx=dx+2*z;
     d1=d1+dx;
    }
    else
    {
     x=x+1;
     y=y-1;
     dx=dx+2*z;
     dy=dy-2*w;
     d1=d1+dx-dy+z;
    }
   }

  j=x+0.5;
  f=y-1;
  n=z*j*j;
  v=w*f*f;
  h=z*w;
  d2=n+v-h;

  while(y>0)
  {
    putpixel(x+320+p,y+240-q,2);
    putpixel(x+320+p,-y+240-q,2);
    putpixel(-x+320+p,y+240-q,2);
    putpixel(-x+320+p,-y+240-q,2);


   if(d2>0)
    {
     y=y-1;
     dy=dy-2*w;
     d2=d2-dy+w;
    }
   else
    {
     x=x+1;
     y=y-1;
     dy=dy-2*w;
     dx=dx+2*z;
     d2=d2+dx-dy+w;
    }
  }
}
void s_q()
{
  setcolor(2);
  cleardevice();
  line(320,0,320,480);
  line(0,240,640,240);
  outtextxy(310,230,"O");
  outtextxy(530,240,"X");
  outtextxy(320,450,"-Y");
  outtextxy(100,240,"-X");
  outtextxy(320,30,"Y");

}

void main()
{
 int rx,ry;
 int p,q;

 int gdriver = DETECT, gmode=1;

 initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

 printf("Enter the value of rx & ry:");
 scanf("%d %d",&rx,&ry);
 printf("\nEnter the shifted co-ord:");
 scanf("%d%d",&p,&q);

 cleardevice();

 s_q();
 draw_el(rx,ry,p,q);

 getch();
}