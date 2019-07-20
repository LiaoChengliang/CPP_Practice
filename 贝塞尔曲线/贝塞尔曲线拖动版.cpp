#include<iostream>
using namespace std;
#include<graphics.h>
#define N 50  
//定义"点"结构体;
struct Point
{
	double x;
	double y;
};
Point point[N];
Point CurvePoint[1000];
int Length = 0;
void Curve(struct Point point[]);
void Plot();
void tran(double &x, double &y)
{
	y = 600-y;
}
void GetPoint(struct Point point[])
{
	int i = 0, num;
	printf("请输入数据组数：");
	scanf("%d", &num);
	printf("请输入数据：");
	while (1)
	{
		scanf("%lf", &point[i].x);
		scanf("%lf", &point[i].y);
		Length++;
		i++;
		num--;
		if (num == 0)
			break;
	}
}
void AlterPoint(int num,int x,int y)
{
	point[num - 1].x = x;
	point[num - 1].y = y;
}
void main()
{
	GetPoint(point);
	Curve(point);
	for (int i = 0; i < 1000; i++)
	{
		CurvePoint[i].x *= 100; 
		CurvePoint[i].y *= 100;
		tran(CurvePoint[i].x, CurvePoint[i].y);
	}
	initgraph(800, 600, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	MOUSEMSG msg;
	setlinecolor(RED);
	Plot();
	while (1)
	{
		int t = 0;
		while (1)
		{
			int k = 0;
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				for (int i=0; i < Length; i++)
				{
					cout<<"mas:" << msg.x<<"  "<<msg.y<<endl;
					cout <<"point"<<i<<" ："<< point[i].x*100 << "  " << 600-point[i].y *100<< endl;
					int tempx = msg.x;
					int tempy = msg.y;
					if (tempx >= (point[i].x * 100 - 10) && tempx <= (point[i].x * 100 + 10) && tempy >= (600 - point[i].y * 100 - 10) && tempy <= (600 - point[i].y * 100 + 10))
					{
						t = i;
					    k = 1;
					    break;
					}
				}
			}
			if (k==1)break;
		}
		while (1)
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				break;
			}
			if (msg.uMsg == WM_LBUTTONUP)
			{
				point[t].x = msg.x/100.0;
				point[t].y =(-msg.y+600)/100.0;
				Curve(point);
				for (int i = 0; i < 1000; i++)
				{
					CurvePoint[i].x *= 100;
					CurvePoint[i].y *= 100;
					tran(CurvePoint[i].x, CurvePoint[i].y);
				}
				cleardevice();
				Plot();
				break;
			}
		}
	}
	system("pause");
	closegraph();
}

void Plot()
{
	for (int i = 0; i < Length - 1; i++)
	{
		line(point[i].x * 100, -point[i].y * 100 + 600, point[i + 1].x * 100, -point[i + 1].y * 100 + 600);
	}
	for (int i = 0; i < 999; i++)
	{
		line(CurvePoint[i].x, CurvePoint[i].y, CurvePoint[i + 1].x, CurvePoint[i + 1].y);
	}
}
void Curve(struct Point point[])
{
	int i, j, k;
	double tt;
	struct Point temp[N];
	for (j = 0; j < 1000; j++)
	{
		for (i = 0; i < Length; i++)
		{
			temp[i].x = point[i].x;
			temp[i].y = point[i].y;
		}
		tt = ((double)j) / 1000;
		for (i = Length - 1; i > 0; i--)
			for (k = 0; k < i; k++)
			{
			temp[k].x = temp[k].x + tt*(temp[k + 1].x - temp[k].x);
			temp[k].y = temp[k].y + tt*(temp[k + 1].y - temp[k].y);
			}
		CurvePoint[j].x = temp[0].x;
		CurvePoint[j].y = temp[0].y;
	}
}