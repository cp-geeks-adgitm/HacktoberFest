#include<graphics.h>
#include<conio.h>
#include<math.h>
int sign(int a)
{
	if(a>0)
		return 1;
	else if (a<0)
		return -1;
	else
		return 0;
}
void bresham(int x1,int y1,int x2,int y2)
{
	int i,x,dx,y,dy,pk,flag,s1,s2,temp,inc1,inc2;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	pk=2*dy-dx;
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	if(dx>dy)
		{
			temp=dx;
			dx=dy;
			dy=temp;
			flag=1;
		}
	else
		flag=0;

	inc1=2*dy;
	inc2=2*(dy-dx);
	x=x1;
	y=y1;
	for(i=1;i<=dx;i++)
	{
		if(pk<0)
			{
				if(flag==1)
					y=y+s2;
				else
					x=x+s1;
				pk=pk+inc1;
			}
		else
			{
				x=x+s1;
				y=y+s2;
				pk=pk+inc2;
			}
		putpixel(x,y,7);
	}
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	bresham(75,375,175,375);
	bresham(75,425,100,425);
	bresham(100,575,100,425);
	bresham(100,575,150,575);
	bresham(150,575,150,425);
	bresham(150,425,175,425);
	bresham(175,375,175,375);
	bresham(175,375,150,375);
	bresham(150,75,150,375);
	bresham(150,75,125,25);
	bresham(100,75,100,375);
	bresham(100,75,125,25);
	getch();
	closegraph();
}
