#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define snakesize 10
int i;
int direct;
struct Coor
	{
		int x;
		int y;
	};
enum Direction
	{
		up = 72, down = 80, left = 75, right = 77
	}direction;

struct Snake
	{
		int n;
		struct Coor coor[200];
		//enum Direction directon; 
	};
struct Snake snake;
struct Coor food;

void changefood()
{
	food.x=(rand()%63)*10;
	food.y=(rand()%47)*10;
}

void drowfood()
{	
	rectangle(food.x,food.y,food.x+10,food.y+10);
}

void eatfood()
{
	snake.n+=1;
	snake.coor[snake.n-1]=snake.coor[snake.n-2];
}


void main()
{
	initgraph(640,480);
	mciSendString("play 甩葱歌.mp3 repeat",0,0,0);
    setbkcolor(BLACK);  //  设置背景颜色
    cleardevice();  //   清除设备,刷新屏幕
	snake.n=3;
	direct=down;
    snake.coor[0].x=0;
    snake.coor[0].y=20;
    snake.coor[1].x=0;
    snake.coor[1].y=10;
    snake.coor[2].x=0;
    snake.coor[2].y=0;
	changefood();
	for(i=0;i<snake.n;i++)
	{
		rectangle(snake.coor[i].x,snake.coor[i].y,snake.coor[i].x+snakesize,snake.coor[i].y+snakesize);
		drowfood();
	}
	int ifbreak=1;
	while(ifbreak)
	{
		
	if(!kbhit())
	{
		for(i=snake.n-1;i>0;i--)
	{
		snake.coor[i].y=snake.coor[i-1].y;
		snake.coor[i].x=snake.coor[i-1].x;
	}
	switch(direct)
	{
	case down:
		snake.coor[0].y+=snakesize;break;
	case up:	
		snake.coor[0].y-=snakesize;break;
	case left: 
		snake.coor[0].x-=snakesize;break;
	case right:
		snake.coor[0].x+=snakesize;break;
	}
	
	for(i=0;i<snake.n;i++)
	{
		rectangle(snake.coor[i].x,snake.coor[i].y,snake.coor[i].x+snakesize,snake.coor[i].y+snakesize);
		drowfood();
	}
	Sleep(150);
	}

	else                         //有键盘输入
	{
		switch(getch())
		{
		case up:
			if(direct!=down)
			direct=up;break;
		case down:
			if(direct!=up)
			direct=down;break;
		case right:
			if(direct!=left)
			direct=right;break;
		case left:
			if(direct!=right)
			direct=left;break;	
		}
	}	
	if(snake.coor[0].x==food.x&&snake.coor[0].y==food.y)
	{
		changefood();
		eatfood();
	}
	cleardevice();

	if(snake.coor[0].x==640||snake.coor[0].x<0||snake.coor[0].y<0||snake.coor[0].y==480)//如果撞墙，退出while循环
		ifbreak=0;
	for(i=1;i<snake.n;i++)//如果撞自己,退出while循环
	{
		if(snake.coor[0].x==snake.coor[i].x&&snake.coor[0].y==snake.coor[i].y)
			ifbreak=0;
	}
	
	}
	closegraph();
	
	MessageBox(NULL,"游戏失败","提示",MB_OK);

}

