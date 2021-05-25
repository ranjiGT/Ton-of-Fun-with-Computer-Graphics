#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

typedef struct
{


 float x,y;
 int l,r,t,b;

}vertex;


int round(float a)
{
  int i=(a+0.5);
  return i;
}

int n;
float xmin,ymin,xmax,ymax;

void verte(vertex v[],int i)
{
  v[i].l=v[i].r=v[i].t=v[i].b=0;
}

void set(vertex v[],int i)
{
  if(v[i].y>ymax)
	 v[i].t=1;
  if(v[i].y<ymin)
	 v[i].b=1;
  if(v[i].x>xmax)
	 v[i].r=1;
  if(v[i].x<xmin)
	 v[i].l=1;
}

void bc(vertex v[])
{
  int n1=0,i,m3;
  vertex v1[10];
  float m,m1,m2;

  for(i=0;i<n;i++)
    {
     m1=v[i+1].y-v[i].y;
     m2=v[i+1].x-v[i].x;
     if(m1==0)
	m=0.001;
     else if(m2==0)
		m=1000;
	  else
	     m=m1/m2;

     if(v[i].b==1&&v[i+1].b==0)
       {
	v1[n1].x=v[i+1].x+(ymin-v[i+1].y)/m;
	v1[n1].y=ymin;
	n1++;

	v1[n1]=v[i+1];
	n1++;
	}
     if(v[i].b==0&&v[i+1].b==0)
       {
	v1[n1]=v[i+1];
	n1++;
       }
      if(v[i].b==0&&v[i+1].b==1)
       {
	v1[n1].x=v[i].x+(ymin-v[i].y)/m;
	v1[n1].y=ymin;
	n1++;
       }
    }

   v1[n1].x=v1[0].x;
   v1[n1].y=v1[0].y;

   n=n1;
   for(i=0;i<=n;i++)
   {
     v[i].x=v1[i].x;
     v[i].y=v1[i].y;
   }
  for(i=0;i<=n;i++)
  {
    verte(v,i);
    set(v,i);
  }
}
void disp(vertex v[]) // display polygon
{
  int i;
  for(i=0;i<n;i++)
      line(round(v[i].x+320),round(-v[i].y+240),round(v[(i+1)].x+320),round(-v[(i+1)].y+240));
}

void s_q()
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
  setcolor(4);
  rectangle((int)xmin+320,(int)-ymin+240,(int)xmax+320,(int)-ymax+240);
}

void main()
{
  float x,y;
  vertex v[10];
  int gdriver = DETECT, gmode,i ;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

  cleardevice();
  printf("\nEnter The Co-Ordinates Of The Clipping Window.");
  printf("\nEnter X(min) & Y(min) :=");
  scanf("%f %f",&xmin,&ymin);
  printf("Enter X(max) & Y(max) :=");
  scanf("%f %f",&xmax,&ymax);
  printf("Enter No Of Vertices");
  scanf("%d",&n);


  for(i=0;i<n;i++)
     {
       printf("Enter X(%d) & Y(%d) :=",i+1,i+1);
       scanf("%f %f",&x,&y);
       v[i].x =x;v[i].y=y;
       verte(v,i);
       set(v,i);
     }

  v[n].x=v[0].x;
  v[n].y=v[0].y;
  i=n;
  set(v,i);

  s_q();
  setcolor(5);
  disp(v);
  getch();

  bc(v);
  s_q();

  setcolor(6);
  disp(v);

  printf("polygon is bottom clipped");
  getch();


}