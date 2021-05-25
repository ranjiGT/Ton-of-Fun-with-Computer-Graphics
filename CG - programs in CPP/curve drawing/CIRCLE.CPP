#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void draw_circle(int r,int p,int q)
{
 int d=(1.25-r),x,y;
 x=0;
 y=r;

 while(x<y)
 {
  putpixel (x+320+p,y+240-q,WHITE);
  putpixel (x+320+p,-y+240-q,WHITE);
  putpixel (-x+320+p,y+240-q,WHITE);
  putpixel (-x+320+p,-y+240-q,WHITE);
  putpixel (y+320+p,x+240-q,WHITE);
  putpixel (y+320+p,-x+240-q,WHITE);
  putpixel (-y+320+p,x+240-q,WHITE);
  putpixel (-y+320+p,-x+240-q,WHITE);

  if (d<0)
  {
   x=x+1;
   y=y;
   d=d+(2*x)+1;
  }
  else
  {
   x=x+1;
   y=y-1;
   d=d+(2*x)-(2*y)+1;
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
  int r,x,y,i,j;
  int gdriver = DETECT, gmode, errorcode;

  clrscr();

  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  s_q();

  printf("enter radius & center(x,y)");
  scanf("%d%d%d",&r,&x,&y);
  putpixel(x+320,-y+240,WHITE);

  draw_circle(r,x,y);

  getch();
}
