
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

matrix fg(3,3);

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
matrix rot(float o) // returns rotation matrix
{
  matrix r(3,3);
  r.a[0][0]=cos(o);r.a[0][1]= -sin(o); r.a[1][0]=sin(o); r.a[1][1]=cos(o); r.a[2][2]=1;
  return r;
}
matrix rota(matrix p,float o) // basic rotation
{
  matrix o1;
  matrix r(3,3);
  r = rot(o);
  o1.mul_mat(r,p);
  return(o1);
}
matrix scal(float sx ,float sy) // returns scaling matrix
{
  matrix s(3,3);
  s.a[0][0]=sx; s.a[1][1]=sy; s.a[2][2]=1;
  return s;
}
matrix scalin(matrix p,float sx,float sy) // basic scaling
{
  matrix o1;
  matrix s(3,3);
  s = scal(sx,sy);
  o1.mul_mat(s,p);
  return(o1);
}
matrix ref(int axis) // returns reflection matrix
{
  matrix r(3,3);

  switch(axis)
   {
     case 1 :
	     r.a[0][0]=1; r.a[1][1]=-1; r.a[2][2]=1;
	     break;
     case 2 :
	     r.a[0][0]=-1; r.a[1][1]=1; r.a[2][2]=1;
	     break ;
     case 3 :
	     r.a[0][1]=1; r.a[1][0]=1; r.a[2][2]=1;
	     break;
  }
  return r;
}
matrix refl(matrix p,int axis) // basic reflection
{
  matrix o1;
  matrix r(3,3);
  r = ref(axis);
  o1.mul_mat(r,p);
  return(o1);
}

matrix shea(float shx ,float shy) // returns shear matrix
{
  matrix s(3,3);
  s.a[0][0]=1; s.a[1][1]=1; s.a[2][2]=1; s.a[1][0]=shy;s.a[0][1]=shx;
  return s;
}
matrix shear(matrix p,float shx,float shy) // basic shear
{
  matrix o1;
  matrix s(3,3);
  s = shea(shx,shy);
  o1.mul_mat(s,p);
  return(o1);
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
void main()
{
  clrscr();
  int xa,ya,yb,xb,tx,ty,axis;
  float shy,shx,sx,sy,o;
  int choice=1;
  matrix a,b;
  int gdriver = DETECT, gmode ;

  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  while(choice!=6)
      {
       show_q();
       printf("enter \n1->basic translation \n2->basic rotation \n3->basic reflection \n4->basic scaling \n5->basic shear \n6->exit ");
       printf("\nenter choice : ");
       scanf("%d",&choice);
       if(choice==6) break;
       printf("enter point a: ");
       scanf("%f %f",&a.a[0][0],&a.a[1][0]);
       printf("enter point b: ");
       scanf("%f %f",&b.a[0][0],&b.a[1][0]);

       setcolor(5);
       line(a.a[0][0]+320,-a.a[1][0]+240,b.a[0][0]+320,-b.a[1][0]+240);

       getch();

       switch(choice)
	  {
	     case 1 :
		      printf("enter point tx ty: ");
		      scanf("%d %d",&tx,&ty);

		      a.a[2][0]=1;
		      a=tran(a,tx,ty);
		      xa=a.a[0][0];ya=a.a[1][0];

		      b.a[2][0]=1;
		      b=tran(b,tx,ty);
		      xb=b.a[0][0];yb=b.a[1][0];
		      break;

	     case 2 :
		      printf("enter o: ");
		      scanf("%f",&o);
		      o=(o*22/180/7);
		      a.a[2][0]=1;
		      a=rota(a,o);
		      xa=a.a[0][0];ya=a.a[1][0];

		      b.a[2][0]=1;
		      b=rota(b,o);
		      xb=b.a[0][0];yb=b.a[1][0];
		      break;

	    case 3 :
		      printf("enter axis\n1->x=0 \n2->y=0 \n3->y=x \n");
		      scanf("%d",&axis);

		      a.a[2][0]=1;
		      a=refl(a,axis);
		      xa=a.a[0][0];ya=a.a[1][0];

		      b.a[2][0]=1;
		      b=refl(b,axis);
		      xb=b.a[0][0];yb=b.a[1][0];
		      break;

	   case 4 :
		      printf("enter sx & sy:");
		      scanf("%f %f",&sx,&sy);

		      a.a[2][0]=1;
		      a=scalin(a,sx,sy);
		      xa=a.a[0][0];ya=a.a[1][0];

		      b.a[2][0]=1;
		      b=scalin(b,sx,sy);
		      xb=b.a[0][0];yb=b.a[1][0];
		      break;
	   case 5 :
		      printf("enter axis\n1->for x shear \n2->for y shear \n");
		      scanf("%d",&axis);

		      if(axis==1)
			 {
			    printf("enter shx : ");
			    scanf("%f",&shx);
			    shy=0;
			 }
		      else
			 {
			    printf("enter shy: ");
			    scanf("%f",&shy);
			    shx=0;
			 }

		      a.a[2][0]=1;
		      a=shear(a,shx,shy);
		      xa=a.a[0][0];ya=a.a[1][0];

		      b.a[2][0]=1;
		      b=shear(b,shx,shy);
		      xb=b.a[0][0];yb=b.a[1][0];
		      break;
	   case 6 :
		      choice=6;
	  }
       setcolor(4);
       line(xa+320,-ya+240,xb+320,-yb+240);
       getch();


     }

}
