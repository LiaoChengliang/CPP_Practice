// 2048.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<tchar.h>
enum Direction
{
	up = 72, down = 80, left = 75, right = 77
}direction;
int i, j, t, k, g,chk;
int a[4][4];
int *p;
TCHAR s[8];
RECT n;

void getnumber();
void drownumber();
int _tmain(int argc, _TCHAR* argv[])
{
	initgraph(480, 480);
	setbkcolor(RGB(100,100,200));
	cleardevice();
	setfillcolor(GREEN);
	settextcolor(RGB(0,0,0));
	settextstyle(50, 22,_T("楷体"));
	setbkmode(TRANSPARENT);

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i <= 3; i++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 40; i <= 440; i += 100)
	{
		line(40, i, 440, i);
		line(i, 40, i, 440);
	}
	srand((unsigned)time(NULL));
	getnumber();
	getnumber();
	drownumber();


	while (1)
	{
		switch (_getch())
		{

		case up:
			chk = 0;
			for (j = 0; j < 4; j++)
			{
				for (i = 0; i < 3; i++)
				{
					for (k = i + 1; k < 4; k++)
					{
						if (a[k][j] == 0)continue;
						if (a[i][j] == a[k][j])
						{
							a[i][j] = 2 * a[k][j];
							if (a[i][j]>0)
								chk++;
							a[k][j] = 0;
							break;
						}
						else
							break;
					}
				}
			}
			for (j = 0; j < 4; j++)
			{
				k = 0;
				for (i = 0; i <= 3; i++)
				if (a[i][j] != 0)
				{
					g = a[i][j];
					a[i][j] = 0;
					a[k][j] = g;
					if (i != k)
						chk++;
					k++;
				}
			}
			if (chk)
			{
				drownumber();
				getnumber();
				Sleep(100);
				drownumber();
			}

			break;

		case down:

			chk = 0;
			for (j = 0; j < 4; j++)
			{
				for (i = 3; i >0; i--)
				{
					for (k = i - 1; k >= 0; k--)
					{
						if (a[k][j] == 0)continue;
						if (a[i][j] == a[k][j])
						{
							a[i][j] = 2 * a[k][j];
							if (a[i][j] != 0)
								chk++;
							a[k][j] = 0;
							break;
						}
						else
							break;
					}
				}
			}
			for (j = 0; j < 4; j++)
			{
				k = 3, g = 0;
				for (i = 3; i >= 0; i--)
				{
					if (a[i][j] != 0)
					{
						g = a[i][j];
						a[i][j] = 0;
						a[k][j] = g;
						if (i != k)
							chk++;
						k--;
					}
				}
			}
			if (chk)
			{
				drownumber();
				Sleep(100);
				getnumber();
				drownumber();
			}

			break;


		case left:
			chk = 0;
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j <3; j++)
				{
					for (k = j + 1; k < 4; k++)
					{
						if (a[i][k] == 0)continue;
						if (a[i][j] == a[i][k])
						{
							a[i][j] = 2 * a[i][k];
							if (a[i][j] != 0)
								chk++;
							a[i][k] = 0;
							break;
						}
						else
							break;
					}
				}
			}
			for (i = 0; i < 4; i++)
			{
				k = 0, g = 0;
				for (j = 0; j <= 3; j++)
				{
					if (a[i][j] != 0)
					{
						g = a[i][j];
						a[i][j] = 0;
						a[i][k] = g;
						if (j != k)
							chk++;
						k++;
					}
				}
			}
			if (chk)
			{
				drownumber();
				Sleep(100);
				getnumber();
				drownumber();
			}

			break;


		case right:
			chk = 0;
			for (i = 0; i< 4; i++)
			{
				for (j = 3; j >0; j--)
				{
					for (k = j - 1; k >= 0; k--)
					{
						if (a[i][k] == 0)continue;
						if (a[i][j] == a[i][k])
						{
							a[i][j] = 2 * a[i][k];
							if (a[i][j] != 0)
								chk++;
							a[i][k] = 0;
							break;
						}
						else
							break;
					}
				}
			}
			for (i = 0; i < 4; i++)
			{
				k = 3, g = 0;
				for (j = 3; j >= 0; j--)
				{
					if (a[i][j] != 0)
					{
						g = a[i][j];
						a[i][j] = 0;
						a[i][k] = g;
						if (k != j)
							chk++;
						k--;
					}
				}
			}
			if (chk)
			{
				drownumber();
				Sleep(100);
				getnumber();
				drownumber();
			}

			break;

		}

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (a[i][j] >= 2048)
				{
					n = {190,0,290,40};
					drawtext(_T("胜利"), &n, DT_CENTER | DT_VCENTER | DT_SINGLELINE);		
				}
					
			}
		}
	}

	system("pause");
	return 0;
}
void getnumber()
{
	t = 0;
	for (i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
	if (a[i][j] == 0)
	{
		t++;
	}
	if (t == 0)
	{
		return;
	}
	t = rand() % t + 1;
	i = 0;
	p = &a[0][0];
	while (1)
	{
		if (*p == 0)
			i++;
		if (i == t)
			break;
		p++;
	}
	*p = rand() % 10;
	if (*p < 9)
		*p = 2;
	else
		*p = 4;

}
void drownumber()
{
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)
			{
				fillrectangle(j * 100 + 40, i * 100 + 40, j * 100 + 140, i * 100 + 140);
			}
			else
			{
				n = { j * 100 + 40, i * 100 + 40, j * 100 + 140, i * 100 + 140 };
				_stprintf(s, _T("%d"), a[i][j]);
				fillrectangle(j * 100 + 40, i * 100 + 40, j * 100 + 140, i * 100 + 140);
				drawtext(s, &n, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
		}
	}
}



