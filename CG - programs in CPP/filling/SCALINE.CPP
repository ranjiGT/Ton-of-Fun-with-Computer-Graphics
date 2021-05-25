#include<alloc.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

typedef struct tedge
{
 int yupper;
 float xintersect,dxperscan;
 struct tedge* next;
}Edge;
typedef struct
{
 int x,y;
}dcpt;

int bc;

void insertedge(Edge* list,Edge* edge)
{
 Edge*p ,*q=list;

 p=q->next;
 while(p != NULL)
  {
   if(edge->xintersect < p->xintersect)
     p=NULL;
   else
     {
      q=p;
      p=p->next;
     }
   }
 edge->next=q->next;
 q->next=edge;
}
int ynext(int k,int cnt,dcpt* pts)
{
 int j;

 if((k+1)>(cnt-1))
   j=0;
 else
   j=k+1;

 while(pts[k].y==pts[j].y)
  { if((j+1)>(cnt-1))
    j=0;
   else
    j++;
  }
 return(pts[j].y);
}

void makeedgerec(dcpt lower,dcpt upper,int ycomp,Edge* edge,Edge* edges[])
{
 float m1=(upper.x-lower.x);
 float m2=(upper.y-lower.y);
 float m=m1/m2;
 edge->dxperscan =m ;
 edge->xintersect=lower.x;
 if(upper.y<ycomp)
   edge->yupper=upper.y-1;
 else
   edge->yupper=upper.y;
 insertedge(edges[lower.y],edge);
}
void buildedgelist(int cnt,dcpt pts[],Edge* edges [])
{
 Edge *edge;
 dcpt v1,v2;
 int i, yprev=pts[cnt-2].y;

 v1=pts[cnt-1];
 for(i=0;i<cnt;i++)
  {
   v2=pts[i];
   if(v1.y != v2.y)
     {
      edge=(Edge *)malloc(sizeof (Edge));
      if(v1.y <v2.y)
	 makeedgerec(v1,v2,ynext(i,cnt,pts),edge,edges);
      else
	 makeedgerec(v2,v1,yprev,edge,edges);
     }
   yprev=v1.y;
   v1=v2;
  }
}

void buildactivelist(int scan,Edge* active,Edge* edges[])
{
 Edge *p,*q;

 p=edges[scan]->next;
 while(p)
  {
    q=p->next;
    insertedge(active,p);
    p=q;
  }
}
void fillscan(int scan,Edge* active,int fc)
{
 Edge* p1, * p2;
 int i;

 p1=active->next;
 while(p1)
  {
   p2=p1->next;
   for(i=p1->xintersect+1;i<p2->xintersect;i++)
     if((getpixel(scan,int(i))==bc))
	;
     else
	  putpixel((int)i,scan,fc);

   p1=p2->next;
  }
}

void deleteafter(Edge* q)
{
 Edge* p=q->next;

 q->next=p->next;
 free(p);
}

void updateactivelist(int scan,Edge* active)
{
 Edge* q= active;
 Edge* p=active->next;

 while(p)
  if(scan >= p->yupper)
  {
    p=p->next;
    deleteafter(q);
  }
  else
  {
   p->xintersect=p->xintersect+p->dxperscan;
   q=p;
   p=p->next;
  }
}
void resortactivelist(Edge *active)
{
 Edge *q ,*p=active->next;

 active->next=NULL;
 while(p)
 {
  q=p->next;
  insertedge(active,p);
  p=q;
 }
}

void scanfill(int cnt, dcpt pts[],int fc)
{
 Edge* edges[480],*active;
 int i,scan;

 for(i=0;i<480;i++)
 {
   edges[i]=(Edge *)malloc(sizeof(Edge));
   edges[i]->next=NULL;
 }
 buildedgelist(cnt,pts,edges);
 active=(Edge *)malloc(sizeof(Edge));
 active->next=NULL;

 for(scan=0;scan<480;scan++)
 {
   buildactivelist(scan,active,edges);
  if(active->next)
  {
   fillscan(scan,active,fc);
   updateactivelist(scan,active);
   resortactivelist(active);
  }
 }
}

void disp(dcpt a[],int cnt,int bc) // display polygon
{
  int i;
  setcolor(bc);
  for(i=0;i<cnt-1;i++)
      line(a[i].x,a[i].y,a[(i+1)].x,a[(i+1)].y);
  line(a[cnt-1].x,a[cnt-1].y,a[0].x,a[0].y);
}


void main()
{
  int cnt,fc,i;
  dcpt a[10];

  int gdriver = DETECT , gmode ;

  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

  cleardevice();

  printf("Enter No Of Vertices :");
  scanf("%d",&cnt);
  printf("Enter Boundary Color :");
  scanf("%d",&bc);
  printf("Enter Fill Color :");
  scanf("%d",&fc);
  printf("\n");

  for(i=0;i<cnt;i++)
     {
       printf("Enter X(%d) & Y(%d) :=",i+1,i+1);
       scanf("%d %d",&a[i].x,&a[i].y);
     }

  disp(a,cnt,bc);
  getch();

  scanfill(cnt,a,fc);
  getch();
}