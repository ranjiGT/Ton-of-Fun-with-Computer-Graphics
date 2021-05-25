#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>


class matrix
{
  public:

  float a[3][3];
  int m,n;

  matrix()
  {

   this->m=3;
   this->n=1;

   for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	  this->a[i][j]=0;
  }
  matrix(int m,int n)
  {
   int i,j;
   this->m=m;
   this->n=n;
   for( i=0;i<m;i++)
	for( j=0;j<n;j++)
	    a[i][j]=0;
 }
  void mul_mat(matrix,matrix);
  void d() ;
};


void matrix::d()
{
 printf("Matrix Elements:\n");
 int i, j;
 for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	  printf(" %0.f ", a[i][j]);
	  printf("\n");
    }

}

void matrix :: mul_mat(matrix m1,matrix m2)
{
 int i,j,k;
 if(m1.n!=m2.m)
    printf("matrix multiplication is not possible ");
 else
    {
      for( i=0;i<m1.m;i++)
	 {
	  for( j=0;j<m2.n;j++)
	     {
	      for( k=0;k<m1.n;k++)
		   this->a[i][j]= (this->a[i][j]+(m1.a[i][k]*m2.a[k][j]));

	      }
    }     }
 this->m=m1.m;
 this->n=m2.n;
}

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

matrix tl(int tx,int ty) // returns translatin matrix
{
  matrix t(3,3);
  t.a[0][0]=1;t.a[1][1]=1;t.a[2][2]=1;t.a[0][2]=tx;t.a[1][2]=ty;
  return t;
}
matrix tran(matrix o,int tx,int ty) // basic translation
{
  matrix o1;
  matrix t(3,3);
  t=tl(tx,ty);
  o1.mul_mat(t,o);
  return(o1);
}

void main()
{

   int tx,ty; 
   int gdriver = DETECT, gmode ;
   matrix a,b; 
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");  

   printf("enter point a: ");
   scanf("%f %f",&a.a[0][0],&a.a[1][0]);
   printf("enter point b: ");
   scanf("%f %f",&b.a[0][0],&b.a[1][0]);
   setcolor(5);
   line(a.a[0][0]+320,-a.a[1][0]+240,b.a[0][0]+320,-b.a[1][0]+240); 

   printf("enter point tx ty: ");
   scanf("%d %d",&tx,&ty);

   a.a[2][0]=1;
   a=tran(a,tx,ty);
   xa=a.a[0][0];ya=a.a[1][0];

   b.a[2][0]=1;
   b=tran(b,tx,ty);
   xb=b.a[0][0];yb=b.a[1][0];
		       
   setcolor(4);
   line(xa+320,-ya+240,xb+320,-yb+240);
   getch();

}
