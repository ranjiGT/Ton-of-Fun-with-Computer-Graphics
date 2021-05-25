#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>

void main()
{
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
 int x=51,y=51,dx=1,dy=1;

 while (!kbhit())
 {
   if(x==50)
     dx=1;

   if(x==590)
     dx=-1;

   if(y==50)
     dy=1;

   if(y==430)
     dy=-1;

   x+=dx;
   y+=dy;

   setcolor(random(1000)%7+1)  ;
   circle(x,y,50);
   delay(1) ;
  }
}