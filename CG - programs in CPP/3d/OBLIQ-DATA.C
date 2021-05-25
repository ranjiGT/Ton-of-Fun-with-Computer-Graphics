/*- Oblique projection of 3D object ( Cube )  --*/
/*************************************************************/


#include<math.h>
#include<stdio.h>
#include<graphics.h>

main()
{

	int 	x1,y1,x2,y2,gd,gm;
	int 	ymax,a[4][8];
	float 	par[4][4],b[4][8];
	int 	i,j,k,m,n,p;
	double 	L1,phi;


	a[0][0] = 100; a[1][0] = 100; a[2][0] = 100;
	a[0][1] = 200; a[1][1] = 100; a[2][1] = 100;

	a[0][2] = 200; a[1][2] = 200; a[2][2] = 100;
	a[0][3] = 100; a[1][3] = 200; a[2][3] = 100;

	a[0][4] = 100; a[1][4] = 100; a[2][4] = 200;
	a[0][5] = 200; a[1][5] = 100; a[2][5] = 200;

	a[0][6] = 200; a[1][6] = 200; a[2][6] = 200;
	a[0][7] = 100; a[1][7] = 200; a[2][7] = 200;

	phi = (double) (3.14*45.0)/180 ;
	L1 = 0.5;

	par[0][0] = 1; 		   par[0][1] = 0;
	par[0][2] = L1*cos(phi);   par[0][3] = 0;

	par[1][0] = 0; 		   par[1][1] = 1;
	par[1][2] = L1*sin(phi);   par[1][3] = 0;

	par[2][0] = 0; 		   par[2][1] = 0;
	par[2][2] = 0;  	   par[2][3] = 0;

	par[3][0] = 0; 		   par[3][1] = 0;
	par[3][2] = 0;  	   par[3][3] = 1;

	m=4; n=4; p=8;


	for(i=0; i<m; i++)
	for(k=0; k<p; k++)
	   b[i][k] = 0;

	for(i=0; i<m; i++)
	for(k=0; k<p; k++)
	for(j=0; j<n; j++)
	   b[i][k] += (float)par[i][j] * a[j][k];

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm, " ");

	ymax = getmaxy();

	/*- front plane display -*/

	for(j=0;j<3;j++)
	{
	   x1=(int) b[0][j];    y1=(int) b[1][j];
	   x2=(int) b[0][j+1];  y2=(int) b[1][j+1];
	   line( x1,ymax-y1,x2,ymax-y2);

	}
	   x1=(int) b[0][3];    y1=(int) b[1][3];
	   x2=(int) b[0][0];    y2=(int) b[1][0];
	   line( x1,ymax-y1,x2,ymax-y2);

	/*- back plane display -*/

	setcolor(11);
	for(j=4;j<7;j++)
	{
	   x1=(int) b[0][j];    y1=(int) b[1][j];
	   x2=(int) b[0][j+1];  y2=(int) b[1][j+1];
	   line( x1,ymax-y1,x2,ymax-y2);

	}
	   x1=(int) b[0][7];    y1=(int) b[1][7];
	   x2=(int) b[0][4];    y2=(int) b[1][4];
	   line( x1,ymax-y1,x2,ymax-y2);

	   setcolor(13);
	for(i=0;i<4;i++)
	{
	   x1=(int) b[0][i];      y1=(int) b[1][i];
	   x2=(int) b[0][4+i];    y2=(int) b[1][4+i];
	   line( x1,ymax-y1,x2,ymax-y2);
	}


	getch(); getch();

}
/*-----------------------------------------------------*/