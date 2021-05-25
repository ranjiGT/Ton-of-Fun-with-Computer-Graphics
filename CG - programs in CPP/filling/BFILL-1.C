/*- Boundary fill algo. using user defined function  -*/

/******************************************************/

	#include<stdio.h>
	#include<graphics.h>
	#include<dos.h>



	void fill_right(x,y)
	int x , y ;
	{
	   if((getpixel(x,y) != WHITE)&&(getpixel(x,y) != RED))
	   {
		putpixel(x,y,RED);
		delay(2);
		fill_right(++x,y);
		x = x - 1 ;
		fill_right(x,y-1);
		fill_right(x,y+1);

	   }
	}

	void fill_left(x,y)
	int x , y ;
	{
	   if((getpixel(x,y) != WHITE)&&(getpixel(x,y) != RED))
	   {
		putpixel(x,y,RED);
		delay(2);
		fill_left(--x,y);
		x = x + 1 ;
		fill_left(x,y-1);
		fill_left(x,y+1);

	   }
	}

	void main()
	{
		int x , y ,a[10][10],n,i;

		int gdriver = DETECT , gmode ;

		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");


		printf("\n\n\tEnter the no. of edges of polygon :  ");
		scanf("%d",&n);
		printf("\n\n\tEnter the cordinates  of  polygon :\n\n\n ");

		for(i=0;i<n;i++)
		{
			printf("\tX%d  Y%d  :  ",i,i);
			scanf("%d %d",&a[i][0],&a[i][1]);
		}

		a[n][0]=a[0][0];
		a[n][1]=a[0][1];

		printf("\n\n\tEnter the seed pt. : ");
		scanf("%d%d",&x,&y);


		cleardevice();
		setcolor(WHITE);

		for(i=0;i<n;i++)  /*- draw poly -*/
		{
		     line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
		}

		fill_right(x,y);
		fill_left(x-1,y);

		getch();
	}

/*********************************************************************/