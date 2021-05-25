#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

typedef struct
{
 long double x,y;
}vertex;

int round(long double a)
{
  long double i=(a+0.5);
  int j=(int)i;
  return j;
}

long int fact(int n)
{
 if(n==0)
      return 1;
 if(n==1)
      return 1;
 return(n*fact(n-1));
}
long double cnk (int n,int k)
{
   return(fact(n)/(fact(k)*fact(n-k)));
}

void bezier(vertex c[],int n)
{
  int i,j;
  long double u;
  long double x,y;
  for(u=0;u<=1;u+=0.01)
   {
    x=0;y=0;
    for(i=0;i<=n;i++)
      {
       x+=(c[i].x*(cnk(n,i)*pow(u,i)*pow((1-u),n-i)));
       y+=(c[i].y*(cnk(n,i)*pow(u,i)*pow((1-u),n-i)));
      }
   putpixel(320+round(x),240-round(y),3);
   delay(20);
   }
}
void s_q()
{
  setcolor(2);
  cleardevice();
  line(320,0,320,480);
  line(0,240,640,240);
  outtextxy(310,230,"O");
  outtextxy(530,240,"X");
  outtextxy(320,450,"-Y");
  outtextxy(100,240,"-X");
  outtextxy(320,30,"Y");

}

void display(vertex v[],int n) // display
{
  int i;
  setcolor(4);
  for(i=0;i<n;i++)
      line(round(v[i].x+320),round(-v[i].y+240),round(v[(i+1)].x+320),round(-v[(i+1)].y+240));
}


void main()
{
  vertex c[10];
  int gdriver = DETECT, gmode,i,n;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

  int x,y;
  clrscr();
  cleardevice();

  printf("Enter the degree n");
  scanf("%d",&n);

  printf("\nEnter %d control points",n+1);
  for(i=0;i<=n;i++)
     {
       printf("\nEnter X(%d) & Y(%d) :=",i,i);
       scanf("%d %d",&x,&y);
       c[i].x=x;
       c[i].y=y;
     }

  clrscr();
  cleardevice();
  s_q();
  display(c,n);
  bezier(c,n);
  getch();

}
