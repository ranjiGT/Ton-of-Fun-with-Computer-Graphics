/*-Thick line drawing- 2  -*/
/*************************************************************/




#include<math.h>
#include<stdio.h>
#include<graphics.h>

main()
{

	int i,gd,gm,w;
	int x,y, x1,y1,x2,y2;
	int xa,ya,xb,yb,xc,yc,xd,yd;
	double theta,m1,m;
	float tx,ty;

	clrscr();

	printf("Enter the co-ordinates of first point (x1 y1) : ");
	scanf("%d %d",&x1,&y1);
	printf("Enter the co-ordinates of second point (x2 y2): ");
	scanf("%d %d",&x2,&y2);

	printf("Enter width of line : ");
	scanf("%d",&w);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\tc\\bgi ");


	m = (double)(y2-y1)/(x2-x1);
	m1 = -(1.0/m);

	theta = atan(abs(m1));
	tx = (w/2)* cos(theta);
	ty = (w/2)* sin(theta);

	xa = x1 - tx;       ya = y1 + ty;
	xb = x1 + tx;       yb = y1 - ty;
	xc = x2 - tx;       yc = y2 + ty;
	xd = x2 + tx;       yd = y2 - ty;


	line( xa, ya, xb, yb );
	line( xc, yc, xd, yd );
	line( xa, ya, xc, yc );
	line( xb, yb, xd, yd );

	x = x1+2;
	y = y1+2;

	floodfill( x, y );
	

	getch();
	closegraph();

 }





