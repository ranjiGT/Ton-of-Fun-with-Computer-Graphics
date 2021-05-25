/*-Bresenham algo. -*/
/*************************************************************/

#include<stdio.h>
#include <graphics.h>
#include <math.h>

void show_q()
{
     clrscr();
     cleardevice();
     setcolor(3);
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
	int k,dx,dy,p,x,y,x1,y1,x2,y2,xinc,yinc;
	int gdriver = DETECT, gmode ;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

	cleardevice();

	show_q();

	printf("\n\n\tEnter the co-ordinates of first point : ");
	scanf("%d %d",&x1,&y1);
	printf("\n\n\tEnter the co-ordinates of second point : ");
	scanf("%d %d",&x2,&y2);

	dx = (x2 - x1);
	dy = (y2 - y1);

	p = 2 * abs(dy) - abs(dx);

	x = x1;
	y = y1;

	putpixel(x,y,WHITE);

	for(k=0; k<=abs(dx); k++)
	{

		if(p < 0)
		    {
			xinc= dx/abs(dx);
			yinc=0;

			p = p + 2 * abs(dy);
		       }
		else
		{
			xinc= dx/abs(dx);
			yinc= dy/abs(dy);

			p = p + 2 * (abs(dy) - abs(dx));
		}

		x+=xinc;
		y+=yinc;
		putpixel(x+320,-y+240,WHITE);
	}

	getch();
	closegraph();

}/*-main()-*/
/***************************** 	BRESENHAM.C ****************************/

