/*-  Test Program

flood fill algo. using user defined function  -*/

/******************************************************/

	#include<stdio.h>
	#include<graphics.h>
	#include<dos.h>

	void fill_right(x,y)
	int x , y ;
	{
	   if(getpixel(x,y) == 0)
	   {
		putpixel(x,y,RED);
		fill_right(++x,y);
		x = x - 1 ;
		fill_right(x,y-1);
		fill_right(x,y+1);

	   }
	}

	void fill_left(x,y)
	int x , y ;
	{
	   if(getpixel(x,y) == 0)
	   {
		putpixel(x,y,RED);

		fill_left(--x,y);
		x = x + 1 ;
		fill_left(x,y-1);
		fill_left(x,y+1);

	   }
	}
/*------------------------------------------------------*/

	void main()
	{
		int x , y ,a[10][10];
		int gd, gm ,n,i;

		detectgraph(&gd,&gm);
		initgraph(&gd,&gm," ");


		     /*- draw object -*/

       line( 100 , 100, 400 , 100);
       line(400, 100, 400, 200);
       line ( 400, 200, 200, 220);
       line (200,220, 250 , 250);
       line (250, 250, 400, 240);

       line( 400, 240, 400 , 400);
       line( 400, 400, 300 , 360);
       line( 300, 360, 300 , 300);
       line( 300, 300, 200 , 300);
       line( 200, 300, 230 , 430);
       line( 230, 430, 100 , 400);
       line( 100, 400, 100 , 100);

     /*- set seed point  -*/
       x = 310;  y = 110;


	setfillstyle(SOLID_FILL, RED);
	floodfill(++x,++y,WHITE);


		getch();
	}

/*******************************************************/