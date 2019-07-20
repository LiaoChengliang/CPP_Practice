#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define W 600
#define H 600
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
struct enemy
{
	int x;
	int y;
	int t;
	struct enemy *next;
};
struct plane
{
	int x;
	int y;
};
struct zidan
{
	int x;
	int y;
	struct zidan *next;
};
int r=0;
RECT rr = {500, 0, 600, 30};
enum Direction
{
    up = 72, down = 80, left = 75, right = 77
}direct;
void CreatEnemy();
void createzidan();
void showenemy(struct enemy *penemy);
void moveenemy(struct enemy *penemy);
void showzidan();
void movezidan();
void destroy();
int chk();
IMAGE img1,img2,img3,img;
int w1,h1,w2,h2,h,w,h3,w3;
struct enemy *pEnemy=NULL;
struct zidan *pzidan=NULL;
struct plane* ple;
char mark[20];
int markk=0;
void main()
{
	
	ple=(struct plane*)malloc(sizeof(struct plane));
	ple->x=275;
	ple->y=450;
	initgraph(W,H);
	mciSendString("play Era.mp3 repeat",0,0,0);
	loadimage(NULL,"MAP_600X600.bmp");
	loadimage(&img1, _T("321.bmp"));
	loadimage(&img2, _T("DIJI_100X37.bmp"));
	loadimage(&img, _T("ZIJI600X300.bmp"));
	loadimage(&img3, _T("ZIDAN_120X25.bmp"));
    w1 = img1.getwidth();
    h1 = img1.getheight();
	w2 = img2.getwidth();
    h2 = img2.getheight();
	w3 = img3.getwidth();
    h3 = img3.getheight();
	w = img.getwidth();
    h = img.getheight();
	settextcolor(RED);
	settextstyle(16, 0, _T("ËÎÌו"));
	while(1)
	{			
		while(kbhit())
		{		
		switch(getch())
		{
		case up:
			if(ple->y-20>0)
			ple->y-=20;break;
		case down:
			if(ple->y+57<600)
			ple->y+=20;break;
		case right:
			if(ple->x+95<600)
			ple->x+=20;break;
		case left:
			if(ple->x-20>0)
			ple->x-=20;break;	
		}	
		}
		if(r%20==0)
		{
		CreatEnemy(); 
		moveenemy(pEnemy);	
		}
		if(r%10==0)
		{
		createzidan();
		movezidan();
		}
		r++;
		if(r==1000)
			r=0;
		loadimage(NULL,"MAP_600X600.bmp");
		showenemy(pEnemy);	
		putimage(ple->x,ple->y,w/2,h,&img,w/2,0,SRCCOPY);	
		showzidan();
		 drawtext(_T(mark), &rr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Sleep(30);
		
		destroy();
	}
	system("pause");
	closegraph();	
}
void CreatEnemy()
{
	struct enemy *pnew;
	pnew=(struct enemy*)malloc(sizeof(struct enemy));
	pnew->x=rand()%550;
	pnew->y=0;
	pnew->t=rand()%2;
	pnew->next=NULL;	
	if(pEnemy==NULL)
		pEnemy=pnew;
	else
	{
		pnew->next=pEnemy;
	    pEnemy=pnew;
	}
}
void showenemy(struct enemy *penemy)
{
	struct enemy *p=penemy;	
	while(p!=NULL)
	{
		if(p->t==1)
		    putimage(p->x,p->y,w1/2,h1,&img1,w1/2,0,SRCCOPY);
		else
			putimage(p->x,p->y,w2/2,h2,&img2,w2/2,0,SRCCOPY);
		p=p->next;
	}
}
void moveenemy(struct enemy *penemy)
{
	struct enemy *p=penemy;	
	while(p!=NULL)
	{
		p->y=p->y+37;
		p=p->next;
	}
}
void createzidan()
{
	struct zidan *pnew;
	pnew=(struct zidan*)malloc(sizeof(struct zidan));
	pnew->x=ple->x;
	pnew->y=ple->y-20;
	pnew->next=NULL;	
	if(pzidan==NULL)
		pzidan=pnew;
	else
	{
		pnew->next=pzidan;
	    pzidan=pnew;
	}
}
void showzidan()
{
	struct zidan *q=pzidan;
	while(q!=NULL)
	{
	    putimage(q->x,q->y,w3/2,h3,&img3,0,0,SRCCOPY);
		q=q->next;
	}
}
void movezidan()
{
	struct zidan *p=pzidan;	
	while(p!=NULL)
	{
		p->y=p->y-30;
		p=p->next;
	}
}
void destroy()
{
	struct enemy *a,*b;
	struct zidan *c,*d;
	a=b=pEnemy;
	while(a!=NULL)
	{
		c=d=pzidan;
		while(c!=NULL)
		{
			if(c->x<(a->x+50)&&c->x>(a->x-75)&&c->y<(a->y+37)&&c->y>(a->y-30))	
			{
				d->next=c->next;
				if (c!=pzidan)
				free(c);
				c=d;
				b->next=a->next;
				if (a != pEnemy)
				free(a);
				a=b;
				markk++;
				itoa(markk,mark,10);
			}
			d=c;
			c=c->next;
		}
		b=a;
		if (a!=NULL)
		a=a->next;
	}
	a = b = pEnemy;
	while (a != NULL)
	{
		if (a->y > 600)
		{
			b->next = a->next;
			if (a != pEnemy)
			free(a);
			a = b;
		}
		b = a;
		a = a->next;
	}
	c = d = pzidan;
	while (c != NULL)
	{
		if (c->y > 600)
		{
			d->next = c->next;
			if (c != pzidan)
				free(c);
			c = d;
		}
		d = c;
		c = d->next;
	}
}













