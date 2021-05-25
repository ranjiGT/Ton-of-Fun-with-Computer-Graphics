/*- Modified DDA algo -*/
/****************************************************************/

#include<math.h>
#include<stdio.h>
#include<graphics.h>

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

void  main()
{

	float xi,yi,x,y;
	int   x1,y1,x2,y2,dx,dy,steps,k;
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

	if(abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xi = (float)dx/steps;
	yi = (float)dy/steps;

	x = x1;
	y = y1;

	for(k=0;k<=steps;k++)
	{
	   putpixel(x+320,-y+240,WHITE);
	   x = x + xi;
	   y = y + yi;
	}

	getch();
	closegraph();

}

/***************************** 	DDAline ****************************/

