
/* Polygon filling Algo. using floodfill inbuilt function  */
/******************************************************************/

#include <stdio.h>
#include <graphics.h>

main()
{

	int 	n,i,j,k,gd,gm,dy,dx;
	int 	x,y,temp;
	int  	a[20][2],xi[20];
	float   slope[20];


	clrscr();
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

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");

	drawpoly(n+1,a);

	printf("\n\n\tEnter the co-ordinates of interior point : ");
	scanf("%d %d",&x, &y);

	setfillstyle(SOLID_FILL, RED);
	floodfill(++x,++y,WHITE);

	getch();



}/*-main()-*/
/**--------------------------------------------------------------**/