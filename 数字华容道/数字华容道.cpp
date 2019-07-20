// 数字华容道.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int a[5][5];
int i, j, k, p, q;
enum Direction
{
	Up = 72, Down = 80, Left = 75, Right = 77
}direction;
RECT r;
TCHAR s[5];
void drownumber();
void up();
void down();
void left();
void right();
void chk();
int _tmain(int argc, _TCHAR* argv[])
{
	initgraph(480,480);
	setbkcolor(RED);
	cleardevice();
	setfillcolor(GREEN);
	setbkmode(GREEN);
	settextcolor(BLACK);
	settextstyle(50, 30, _T("楷体"));
	for (i = 1; i <= 4;i++)
	for (j = 1; j <= 4; j++)
	{
		a[i][j] = 4 * (i - 1) + j;
	}
	p = 4, q = 4;
	for (i = 1; i <= 4; i++)
	{
		down();down();down();
		right();right();right();
		up();up();up();
	    left();left();left();    
	}
	srand(time(NULL));
	for (i = 1; i <= 500; i++)
	{
		switch (rand() % 4)
		{
		case 0:
			if (p != 4)
			{
				up();
			}
			break;

		case 1:
			if (p != 1)
			{
				down();
	
			}
			break;

		case 2:
			if (q != 4)
			{
				left();
			
			}

			break;

		case 3:
			if (q != 1)
			{
				right();
			
			}
			break;
		}
	}
	drownumber();
	
	while (1)
	{
		switch (getch())
		{
		case Up:
			if (p != 4)
			{
				up();
			    drownumber();
			}	
			break;

		case Down:
			if (p != 1)
			{
				down();
			    drownumber();
			}
			break;

		case Left:
			if (q != 4)
			{
				left();
			    drownumber();
			}
			
			break;

		case Right:
			if (q != 1)
			{
				right();
			   drownumber();
			}
			break;
		}
		chk();
		if (k == 16)
			break;
	}
	r = {190,0,280,40};
	settextcolor(WHITE);
	settextstyle(40, 20, _T("宋体"));
	drawtext(_T("胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	system("pause");
	return 0;
}
void drownumber()
{
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (a[i][j] != 16)
			{
				setfillcolor(GREEN);
				fillrectangle((j - 1) * 100 + 40, (i - 1) * 100 + 40, (j - 1) * 100 + 140, (i - 1) * 100 + 140);
				r = { (j - 1) * 100 + 40, (i - 1) * 100 + 40, (j - 1) * 100 + 140, (i - 1) * 100 + 140 };
				_stprintf(s, _T("%d"), a[i][j]);        
				drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	
			}
			else
			{
				setfillcolor(RED);
				fillrectangle((j-1)*100+40,(i-1)*100+40,(j-1)*100+140,(i-1)*100+140);
			}
			
		}
	}

}
void up()
{
	a[p][q] = a[p + 1][q];
	a[p + 1][q] = 16;
	p = p + 1;	
}
void down()
{
	a[p][q] = a[p - 1][q];
	a[p - 1][q] = 16;
	p = p - 1;
}
void left()
{
	a[p][q] = a[p][q+1];
	a[p][q+1] = 16;
	q=q+1;
}
void right()
{
	a[p][q] = a[p][q -1];
	a[p][q - 1] = 16;
	q = q - 1;
}
void chk()
{
	k = 0;
	for (i = 1; i <= 4; i++)
	for (j = 1; j <= 4; j++)
	{
		if (a[i][j] == 4 * (i - 1) + j)
		k++;
	}	
}

