// 扫雷.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<tchar.h>

TCHAR s[2];
int i, k;
class Grid
{
public:
	int x;
	int y;
	int n;
	bool flag;
	bool mine;
	bool ifopen;
	void open()
	{
		setfillcolor(RGB(255,255,255));
		fillrectangle(x-10,y-10,x+10,y+10);
		RECT r = { x - 10, y - 10, x + 10, y + 10 };
		_stprintf(s, _T("%d"), n);
		setbkmode(RGB(255, 255, 255));
		settextcolor(BLACK);
		drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		if (n == 0)
		{
			setfillcolor(RGB(255,255, 255));
		    fillrectangle(x - 10, y - 10, x + 10, y + 10);
		}	
	    ifopen = true;
	};
	void  burst()
	{
		setfillcolor(RGB(255, 0,0));
		fillrectangle(x - 10, y - 10, x + 10, y + 10);
		setfillcolor(BLACK);
		fillcircle(x, y, 10);
		ifopen = true;
	};
	void hide()
	{
		setfillcolor(RGB(0, 200, 100));
		fillrectangle(x - 10, y - 10, x + 10, y + 10);
	};
	void mark()
	{
		setfillcolor(RGB(255, 0, 0));
		POINT pts[] = { { x+3, y-9 }, { x-6, y }, { x+3, y } };
		fillpolygon(pts, 3);
	};
};
Grid a[900];
void op(int t);
void initmap();
void Infer();
int _tmain(int argc, _TCHAR* argv[])
{
	initgraph(600,600);
	/*HWND hWnd = GetHWnd();
	WINDOWPLACEMENT Wpm;
	Wpm.length = sizeof(WINDOWPLACEMENT);
	Wpm.flags = 0;
	Wpm.showCmd = SW_SHOWNORMAL;
	Wpm.rcNormalPosition = RECT{450,50,1050,650};
	SetWindowPlacement(hWnd,&Wpm);*/
	setlinecolor(RGB(0,100,200));
	initmap();
	for (i = 0; i < 900; i++)
	{
		a[i].hide();
	}
	MOUSEMSG msg;
	while (1)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			if (msg.x % 20 != 0 && msg.y % 20 != 0)
			{		
				i = msg.y / 20 * 30 + msg.x / 20;
				if (a[i].ifopen == false&&a[i].flag==false)
				{
					
					if (a[i].mine == true)
					{
						for (i = 0; i < 900; i++)
						{
							if (a[i].mine == true)
							a[i].burst();
						}
							
						break;
					}
						
					if (a[i].n != 0 && a[i].mine ==false)
						a[i].open();
					else if (a[i].n==0)
					{
						op(i);
					}				
				}	
			}
		}
		if (msg.uMsg == WM_RBUTTONDOWN)
		{
			if (msg.x % 20 != 0 && msg.y % 20 != 0)
			{
				i = msg.y / 20 * 30 + msg.x / 20;
				if (a[i].ifopen == false)
				{
					switch(a[i].flag)
				   {
				      case false:
					          a[i].mark();
					          a[i].flag = true;
					          break;
				      case true:	
					          a[i].hide();
					          a[i].flag =false;
					           break;
					};
				}
				
			}
		}

		if (msg.uMsg == WM_LBUTTONDBLCLK)
		{
			if (msg.x % 20 != 0 && msg.y % 20 != 0)
			{
				i = msg.y / 20 * 30 + msg.x / 20;
				if (a[i].ifopen == true)
				{
					Infer();
				}

			}
		}

	}
	system("pause");
	return 0;
}
void initmap()
{
	srand((unsigned)time(NULL));
	for (i = 0; i < 900; i++)
	{
		a[i].x = (i % 30) * 20 + 10;
		a[i].y = (i / 30) * 20 + 10;
		k = rand() % 9;
		if (k < 7)
			a[i].mine = false;
		else
			a[i].mine = true;
		a[i].n = 0;
		a[i].flag = false;
		a[i].ifopen = false;
	}
	for (i = 1; i < 900; i++)
	{
		if ((i - 31) >= 0)
		if (a[i].x>a[i-31].x)
		if (a[i - 31].mine == true)
			a[i ].n++;
		if ((i - 30) >= 0)
		if (a[i - 30].mine == true)
			a[i ].n++;
		if ((i - 29) >= 0)
		if (a[i].x<a[i - 29].x)
		if (a[i - 29].mine == true)
			a[i ].n++;
		if ((i - 1) >= 0)
		if (a[i].x>a[i - 1].x)
		if (a[i - 1].mine == true)
			a[i].n++;
		if ((i + 1) <900)
		if (a[i].x<a[i+1].x)
		if (a[i + 1].mine == true)
			a[i].n++;
		if ((i + 29) <900)
		if (a[i].x>a[i +29].x)
		if (a[i + 29].mine == true)
			a[i ].n++;
		if ((i + 30) <900)
		if (a[i + 30].mine == true)
			a[i ].n++;
		if ((i + 31) <900)
		if (a[i].x<a[i +31].x)
		if (a[i + 31].mine == true)
			a[i ].n++;
	}
}
void op(int t)
{
	if (a[t].n == 0&&a[t].ifopen==false&&a[t].mine==false)
		a[t].open();
	else 
	{
		a[t].open();
		return;
	}
		
	if ((t - 31) >= 0)
	if (a[t].x>a[t - 31].x)
		op(t-31);
	if ((t - 30) >= 0)
		op(t - 30);
	if ((t - 29) >= 0)
	if (a[t].x<a[t - 29].x)
		op(t - 29);
	if ((t - 1) >= 0)
	if (a[t].x>a[t - 1].x)
		op(t - 1);
	if ((t + 1) <900)
	if (a[t].x<a[t +1].x)
		op(t+1);
	if ((t + 29) <900)
	if (a[t].x>a[t +29].x)
		op(t +29);
	if ((t + 30) <900)
		op(t +30);
	if ((t + 31) <900)
	if (a[t].x<a[t + 31].x)
		op(t +31);
	return;
};
void Infer()
{
	k = 1;
	if ((i - 31) >= 0)
	if (a[i].x>a[i - 31].x)
	if (a[i - 31].flag != a[i-31].mine)
		k = 0;
	if ((i - 30) >= 0)
	if (a[i - 30].flag != a[i-30].mine)
		k = 0;
	if ((i - 29) >= 0)
	if (a[i].x<a[i - 29].x)
	if (a[i - 29].flag != a[i-29].mine)
		k = 0;
	if ((i - 1) >= 0)
	if (a[i].x>a[i - 1].x)
	if (a[i - 1].flag != a[i-1].mine)
		k = 0;
	if ((i + 1) <900)
	if (a[i].x<a[i + 1].x)
	if (a[i +1].flag != a[i+1].mine)
		k = 0;
	if ((i + 29) <900)
	if (a[i].x>a[i + 29].x)
	if (a[i+29].flag != a[i+29].mine)
		k = 0;
	if ((i + 30) <900)
	if (a[i + 30].flag != a[i + 30].mine)
		k = 0;
	if ((i + 31) <900)
	if (a[i].x<a[i + 31].x)
	if (a[i + 31].flag != a[i + 31].mine)
		k = 0;

	if (k == 1)
	{
		if ((i - 31) >= 0)if (a[i].x>a[i - 31].x)if (a[i - 31].mine == false && a[i - 31].ifopen == false)
			a[i - 31].open();
		if ((i - 30) >= 0)if (a[i - 30].mine == false && a[i - 30].ifopen == false)
			a[i - 30].open();
		if ((i - 29) >= 0)if (a[i].x<a[i - 29].x)if (a[i - 29].mine == false && a[i - 29].ifopen == false)
			a[i - 29].open();
		if ((i - 1) >= 0)if (a[i].x>a[i - 1].x)if (a[i - 1].mine == false && a[i - 1].ifopen == false)
			a[i -1].open();
		if ((i + 1) <900)if (a[i].x<a[i + 1].x)if (a[i + 1].mine == false && a[i + 1].ifopen == false)
			a[i +1].open();
		if ((i + 29) <900)if (a[i].x>a[i + 29].x)if (a[i + 29].mine == false && a[i + 29].ifopen == false)
			a[i +29].open();
		if ((i + 30) <900)if (a[i +30].mine == false && a[i +30].ifopen == false)
			a[i +30].open();
		if ((i + 31) <900)if (a[i].x<a[i + 31].x)if (a[i + 31].mine == false && a[i + 31].ifopen == false)
			a[i + 31].open();

	}
}
