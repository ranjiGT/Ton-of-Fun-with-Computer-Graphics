/*TO IMPLEMENT HIDDEN SURFACE ELIMINATION ALGORITHM
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
struct node
{
int x1;int y1;int x2;int y2;int star; 
};
struct node n[10],n2[10],tempo,tempo1;
float dx,dx1,dy,dy1,m[10],m1[10],x_int[10],x_int1[10],inter_x[10],inter_x1[10];
int intensity1,intensity2,depth1,depth2;
int x[10],xa[10],y[10],ya[10],ymax=0,ymax1=0,ymin=480,ymin1=0,yy,temp; 
void main()
{
int gd=DETECT,gm;
int na,na2,i,j,k;
clrscr();
printf("Enter the no of vertices of fig 1:");
scanf("%d",&na);
for(i=0;i<na;i++)
{
printf("Enter vertex %d(x,y):",i+1); 
scanf("%d%d",&x[i],&y[i]);
if(y[i]>ymax)
ymax=y[i];
if(y[i]<ymin)
ymin=y[i];
n[i].x1=x[i];
n[i].y1=y[i];
}
printf("Enter intensity:");
scanf("%d",&intensity1); 
printf("Enter depth:");
scanf("%d",&depth1);
printf("Enter the no of vertices of figure 2:");
scanf("%d",&na2);
for(i=0;i<na2;i++)
{
printf("Enter vertex %d(x,y):",i+1); 
scanf("%d%d",&xa[i],&ya[i]);
if(ya[i]>ymax1)
ymax1=ya[i];
if(ya[i]<ymin1)
ymin1=ya[i];
n2[i].x1=xa[i];
n2[i].y1=ya[i];
}
printf("Enter intensity:");
scanf("%d",&intensity2); 
printf("Enter depth:");
scanf("%d",&depth2);
initgraph(&gd,&gm,"c:\\tc\\bgi");
if(depth1<depth2)
{
//one
jp2:for(i=0;i<na-1;i++)
{
n[i].x2=n[i+1].x1;
n[i].y2=n[i+1].y1;
n[i].star=0;
}
n[i].x2=n[0].x1;
n[i].y2=n[0].y1;
n[i].star=0;
for(i=0;i<na;i++)
{
if(n[i].y1<n[i].y2)
{
temp=n[i].x1;
n[i].x1=n[i].x2;
n[i].x2=temp;
temp=n[i].y1;
n[i].y1=n[i].y2;
n[i].y2=temp;
}
}
for(i=0;i<na;i++)
{
line(n[i].x1,n[i].y1,n[i].x2,n[i].y2);
}
for(i=0;i<na-1;i++)
{
for(j=0;j<na-1;j++)
{
if(n[j].y1<n[j+1].y1)
{
tempo=n[j];
n[j]=n[j+1];
n[j+1]=tempo;
}
if(n[j].y1==n[j+1].y1)
{
if(n[j].y2<n[j+1].y2)
{
tempo=n[j]; 
n[j]=n[j+1];
n[j+1]=tempo;
}
if(n[j].y2==n[j+1].y2)
{
if(n[j].x1<n[j+1].x1)
{
tempo=n[j];
n[j]=n[j+1];
n[j+1]=tempo;
} } } }  }
for(i=0;i<na;i++)
{
dx=n[i].x2-n[i].x1;
dy=n[i].y2-n[i].y1;
if(dy==0)
{
m[i]=0;
}
else
{
m[i]=dx/dy;
}
inter_x[i]=n[i].x1;
}
yy=ymax;
while(yy>ymin)
{
for(i=0;i<na;i++) 
{
if((yy>n[i].y2)&&(yy<=n[i].y1))
{
n[i].star=1;
}
else
{
n[i].star=0;
}
}
j=0;
for(i=0;i<na;i++)
{
 if(n[i].star==1)
{
if(yy==n[i].y1)
{
x_int[j]=n[i].x1; 
j++;
if((n[i-1].y1==yy)&&(n[i-1].y1<yy))
{
x_int[j]=n[i].x1;
j++;
if((n[i+1].y1==yy)&&(n[i+1].y1<yy))
{
x_int[j]=n[i].x1;
j++;
} }  }
else
{
x_int[j]=inter_x[i]+(-m[i]); 
inter_x[i]=x_int[j];
j++;
} } }
for(i=0;i<j;i++)
{
for(k=0;k<j-1;k++)
{
if(x_int[k]>x_int[k+1])
{
temp=x_int[k];
x_int[k]=x_int[k+1];
x_int[k+1]=temp;
} } }
setcolor(intensity1);
for(i=0;i<j;i=i+2)
{ 
line(x_int[i],yy,x_int[i+1],yy);
}
yy--;
}
outtextxy(50,80,"object with less depth");
if(depth2<depth1)
{
goto jp3;
}
delay(3000);
//two
setcolor(WHITE);
jp1:for(i=0;i<na2-1;i++) 
{
n2[i].x2=n2[i+1].x1;
n2[i].y2=n2[i+1].y1;
n2[i].star=0;
}
n2[i].x2=n2[0].x1;
n2[i].y2=n2[0].y1;
n2[i].star=0;
for(i=0;i<na2;i++)
{
if(n2[i].y1<n2[i].y2)
{
temp=n2[i].x1;
n2[i].x1=n2[i].x2;
n2[i].x2=temp;
temp=n2[i].y1;
n2[i].y1=n2[i].y2;
n2[i].y2=temp;
} }
for(i=0;i<na2;i++)
{
line(n2[i].x1,n2[i].y1,n2[i].x2,n2[i].y2);
}
for(i=0;i<na2-1;i++)
{
for(j=0;j<na2-1;j++)
{
if(n2[j].y1<n2[j+1].y1)
{
tempo1=n2[j];
n2[j]=n2[j+1];
n2[j+1]=tempo1;
}
if(n2[j].y1==n2[j+1].y1)
{
if(n2[j].y2<n2[j+1].y2)
{
tempo1=n2[j];
n2[j]=n2[j+1];
n2[j+1]=tempo1;
}
if(n2[j].y2==n2[j+1].y2)
{
if(n2[j].x1<n2[j+1].x1)
{
tempo1=n2[j]; 
n2[j]=n2[j+1];
n2[j+1]=tempo1;
} } } } }
for(i=0;i<na2;i++)
{
dx1=n2[i].x2-n2[i].x1;
dy1=n2[i].y2-n2[i].y1;
if(dy1==0)
{
m1[i]=0;
}
else
{
m1[i]=dx1/dy1;
}
inter_x1[i]=n2[i].x1;
}
yy=ymax1;
while(yy>ymin1) 
{
for(i=0;i<na2;i++)
{
if((yy>n2[i].y2)&&(yy<=n2[i].y1))
{
n2[i].star=1;
}
else
{
n2[i].star=0;
}
}
j=0;
for(i=0;i<na2;i++)
{
 if(n2[i].star==1)
{
if(yy==n2[i].y1)
{
x_int1[j]=n2[i].x1;
j++;
if((n2[i-1].y1==yy)&&(n2[i-1].y1<yy))
{
x_int1[j]=n2[i].x1;
j++;
if((n2[i+1].y1==yy)&&(n2[i+1].y1<yy))
{
x_int1[j]=n2[i].x1;
j++;
} } }
else
{
x_int1[j]=inter_x1[i]+(-m1[i]);
inter_x1[i]=x_int1[j];
j++;
} }  }
for(i=0;i<j;i++)
{
for(k=0;k<j-1;k++)
{
if(x_int1[k]>x_int1[k+1])
{
temp=x_int1[k];
x_int1[k]=x_int1[k+1];
x_int1[k+1]=temp;
} } }
setcolor(intensity2);
for(i=0;i<j;i=i+2) 
{
line(x_int1[i],yy,x_int1[i+1],yy);
}
yy--;
}
outtextxy(50,50,"object with more depth");
if(depth2<depth1)
{
goto jp2;
}
}
else
{
goto jp1;
}
jp3:getch();
}
