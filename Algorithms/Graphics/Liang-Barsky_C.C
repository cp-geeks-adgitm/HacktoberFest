#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void dda(int x1,int y1,int x2,int y2)
{
	float steps,xinc,yinc;
	int i,dx,dy,x,y;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>=dy)
		steps=dx;
	else
		steps=dy;
	xinc=dx/steps;
	yinc=dy/steps;
	x=x1;
	y=y1;
	for(i=1;i<=steps;i++)
		{
			putpixel(ceil(x),ceil(y),10);
			x=x+xinc;
			y=y+yinc;
		}
}
void main()
{
	int rxmin,rymin,rxmax,rymax,ax,ay,bx,by,x1,x2,y1,y2,dx,dy,i,xx1,xx2,yy1,yy2;
	float t1=0.0,t2=1.0,p[4],q[4],qbp[4];
	int gd=DETECT,gm;
	clrscr();
	printf("Enter min co-ordinates of rectangle:\n");
	scanf("%d,%d",&rxmin,&rymin);
	printf("\nEnter mar co-ordinates of rectangle:\n");
	scanf("%d,%d",&rxmax,&rymax);
	printf("\nEnter first co-ordinate:\n");
	scanf("%d,%d",&x1,&y1);
	printf("\nEnter second co-ordinate:\n");
	scanf("%d,%d",&x2,&y2);
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	rectangle(rxmin,rymin,rxmax,rymax);
	dda(x1,y1,x2,y2);
	dx=x2-x1;
	dy=y2-y1;
	p[0]=dx*(-1);
	p[1]=dx;
	p[2]=dy*(-1);
	p[3]=dy;
	q[0]=x1-rxmin;
	q[1]=rxmax-x1;
	q[2]=y1-rymin;
	q[3]=rymax-y1;
	for(i=0;i<4;i++)
		qbp[i]=q[i]/p[i];
	for(i=0;i<4;i++)
	{
		if(p[i]<0)
		{
			if(qbp[i]>t1)
				t1=qbp[i];
		}
		else
		{
			if(qbp[i]<t2)
				t2=qbp[i];

		}
	}
	if(t1<t2)
	{
	xx1=x1+t1*dx;
	yy1=y1+t1*dy;
	xx2=x1+t2*dx;
	yy2=y1+t2*dy;
	line(xx1,yy1,xx2,yy2);
	}
	getch();
	closegraph();

}






























































































































































































































































































































































