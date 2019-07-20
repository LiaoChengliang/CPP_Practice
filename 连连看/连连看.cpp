#include<graphics.h>
#include<time.h>
#include<stdio.h>
#define WIDTH 420
#define HEIGHT 420
int i,j,k;
int a1,a2,b1,b2,sum;
int a[8][8] = {0}; 
MOUSEMSG m;
void chk();
void remove();
RECT r = { 0, 0, WIDTH, HEIGHT / 16 };

int main()
{

	initgraph(WIDTH, HEIGHT);
	settextstyle(HEIGHT / 16, 0, _T("宋体"));
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 6; j++)
			a[i][j] = i;
	}
	srand((unsigned)time(NULL));
	for (k = 1; k <= 100; k++)
	{
		a1=(rand()%6)+ 1;
		a2=(rand()%6)+ 1;
		b1=(rand()%6)+ 1;
		b2=(rand()%6)+ 1;
		if (!(a1 == b1&&a2 == b2))// 两数交换位置   防止自己和自己 运算
		{
			a[a1][a2] = (a[a1][a2] + a[b1][b2]);
		    a[b1][b2] = (a[a1][a2] - a[b1][b2]);
		    a[a1][a2] = (a[a1][a2] - a[b1][b2]);
		}
	}
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			switch (a[i][j])
			{
			case 1:
				setfillcolor(BLUE); 
				fillrectangle(30 * (2 * j - 1), 30 * (2 * i - 1), 30 * (2 * j - 1) + 60, 30 * (2 * i - 1) + 60);
				break;

			case 2:
				setfillcolor(CYAN);
				fillrectangle(30 * (2 * j - 1), 30 * (2 * i - 1), 30 * (2 * j - 1) + 60, 30 * (2 * i - 1) + 60);
				break;

			case 3:
				setfillcolor(YELLOW); 
				fillrectangle(30 * (2 * j - 1), 30 * (2 * i - 1), 30 * (2 * j - 1) + 60, 30 * (2 * i - 1) + 60);
				break;

			case 4:
				setfillcolor(RED); 
				fillrectangle(30 * (2 * j - 1), 30 * (2 * i - 1), 30 * (2 * j - 1) + 60, 30 * (2 * i - 1) + 60);
				break;

			case 5:
				setfillcolor(GREEN); 
				fillrectangle(30 * (2 * j - 1), 30 * (2 * i - 1), 30 * (2 * j - 1) + 60, 30 * (2 * i - 1) + 60);
				break;

			case 6:
				setfillcolor(BROWN);
				fillrectangle(30 * (2 * j - 1), 30 * (2 * i - 1), 30 * (2 * j - 1) + 60, 30 * (2 * i - 1) + 60);
				break;
			}
		}		
	}
	while (1)
	{
		while (1)
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			if (m.x<390 && m.x>30 && m.y<390 && m.y>30 && (m.x - 30) % 60 != 0 && (m.y - 30) % 60 != 0)
			{
				a1 = (m.y - 30) / 60 + 1;
				a2 = (m.x - 30) / 60 + 1;
				break;
			}
		}
		while (1)
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			if (m.x<390 && m.x>30 && m.y<390 && m.y>30 && (m.x - 30) % 60 != 0 && (m.y - 30) % 60 != 0)
			{
				b1 = (m.y - 30) / 60 + 1;
				b2 = (m.x - 30) / 60 + 1;		
				break;
			}
		}
		if (a1 != b1||a2 != b2)
			chk();
		sum = 0;
		for (i = 1; i <= 6; i++)
		{
			for (j = 1; j <= 6; j++)
				sum += a[i][j];
		}
		if (sum == 0)
		{
			drawtext(_T("胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;
		}	
	}
	system("pause");
	return 0;
}
void chk()
{
	if (a[a1][a2] != a[b1][b2])return;
	//--------------------------------------------------------------横向
	for (i =0; i <= 7; i++)
	{ 

		  k = 0;
		//判断直线通路
			for (j = a2; j <= b2; j++)
			{
				if (a[i][j]!=a[a1][a2])
				if (a[i][j] != 0)
					k = 1;
			}
			for (j = b2; j <= a2; j++)
			{
				if (a[i][j] != a[b1][b2])
				if (a[i][j] != 0)
					k = 1;
			}
			if (k == 1)
				continue;

       //判断连接通路
			for (j = i + 1; j <= a1 - 1; j++)
			{
				if (a[j][a2] != 0)
					k = 1;
			}
			for (j = a1 + 1; j <= i - 1; j++)
			{
				if (a[j][a2] != 0)
					k = 1;
			}
			for (j = i + 1; j <= b1- 1; j++)
			{
				if (a[j][b2] != 0)
					k = 1;
			}
			for (j = b1 + 1; j <=i - 1; j++)
			{
				if (a[j][b2] != 0)
					k = 1;
			}
			if (k == 0)
			{
				remove();
				return;
			}
	}
	//------------------------------------------------------------------------
	//-------------------------------------------------------------------纵向
	for (j =0; j <= 7; j++)
	{

		k = 0;
		//判断直线通路
		for (i = a1; i <= b1; i++)
		{
			if (a[i][j] != a[a1][a2])
			if (a[i][j] != 0)
				k = 1;
		}
		for (i = b1; i <= a1; i++)
		{
			if (a[i][j] != a[b1][b2])
			if (a[i][j] != 0)
				k = 1;
		}
		if (k == 1)
			continue;

		//判断连接通路
		for (i = j + 1; i <=a2 - 1; i++)
		{
			if (a[a1][i] != 0)
				k = 1;
		}
		for (i = a2 + 1; i <=j - 1; i++)
		{
			if (a[a1][i] != 0)
				k = 1;
		}

		for (i = j + 1; i <= b2 - 1; i++)
		{
			if (a[b1][i] != 0)
				k = 1;
		}
		for (i = b2 + 1; i <= j - 1; i++)
		{
			if (a[b1][i] != 0)
				k = 1;
		}
		if (k == 0)
		{
			remove();
			return;
		}
	}
}
void remove()
{
	setfillcolor(BLACK);
	fillrectangle(30 * (2 * a2- 1), 30 * (2 * a1 - 1), 30 * (2 * a2 - 1) + 60, 30 * (2 * a1 - 1) + 60);
	fillrectangle(30 * (2 * b2 - 1), 30 * (2 * b1 - 1), 30 * (2 * b2 - 1) + 60, 30 * (2 * b1 - 1) + 60);
	a[a1][a2] = 0;
	a[b1][b2] = 0;
}




