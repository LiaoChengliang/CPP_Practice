#include<stdio.h>
#include<graphics.h>
//设置最大点组容量
#define N 50  
//定义"点"结构体;
struct Point
{
	double x;
	double y;
}point[N];
//存储 贝塞尔曲线1000个点坐标
struct Point CurvePoint[1000];
//初始化输入点的数量
int Length=0;
//点组坐标最大值
double MaxPointX, MaxPointY, MinPointX, MinPointY;
//获取点组
void GetPoint(struct Point point[]);
//添加点组
void AddPoint(struct Point point[],int length);
//计算贝塞尔曲线
void Curve(struct Point point[]);
//绘制图像
void Plot(struct Point point[]);
//修改某点
void AlterPoint(struct Point point[]);
//对点组排序
void Sort(struct Point point[],int length);
//选择操作提示说明
void operate();
int main()
{
	GetPoint(point);//获取初始数据
	Sort(point,Length);//对初始数据排序
	while (1){
		operate();
		int Option;
		scanf("%d",&Option);
		//选择操作
		switch (Option)
		{
		case 1:AlterPoint(point); Sort(point,Length); break;
		case 2:AddPoint(point, Length); Sort(point,Length); break;
		case 3:Plot(point); break;
		case 4:return 0; break;
		default:printf("数据不合法，请重新输入！\n"); break;
		}
	    printf("\n");
	}
	return 0;
}
void operate()
{
	printf("------------操作说明-------------\n");
	printf("----------1.替换数据-------------\n");
	printf("----------2.添加数据-------------\n");
	printf("----------3.绘制图形-------------\n");
	printf("----------4.退出程序-------------\n");
	printf("请输入操作：");
}
void GetPoint(struct Point point[])
{
	int i=0,num;
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

void AlterPoint(struct Point point[])
{
	int num;
	printf("请输入需要修改的位置：");
	scanf("%d", &num);
	printf("需要修改为：");
	scanf("%lf", &point[num - 1].x);
	scanf("%lf", &point[num - 1].y);
}

void AddPoint(struct Point point[],int length)
{
	int i=length;
	int num;
	printf("添加组数：");
	scanf("%d",&num);
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
void Sort(struct Point point[], int length)
{
	int i = 0, j = 0;
	MaxPointY = point[0].y;
	MinPointY = point[0].y;
	for (i = 0; i < length - 1; i++)
	{ 
		for (j = i + 1; j < length; j++)
		{
		if (point[i].x>point[j].x)
		{
			point[i].x += point[j].x;
			point[i].y += point[j].y;
			point[j].x = point[i].x - point[j].x;
			point[j].y = point[i].y - point[j].y;
			point[i].x = point[i].x - point[j].x;
			point[i].y = point[i].y - point[j].y;
		}
		}
		if (point[i].y > MaxPointY)MaxPointY = point[i].y;
		if (point[i].y < MinPointY)MinPointY = point[i].y;
	}
	if (point[length - 1].y > MaxPointY)MaxPointY = point[length - 1].y;
	if (point[length - 1].y < MinPointY)MinPointY = point[length - 1].y;
	MaxPointX = point[length - 1].x;
	MinPointX = point[0].x;
}

void Curve(struct Point point[])
{
	int i, j,k;
	double t;
	struct Point temp[N];
	for (j = 0; j < 1000; j++)
	{

		for (i = 0; i < Length; i++)
		{
			temp[i].x = point[i].x;
			temp[i].y = point[i].y;
		}
		t = ((double)j )/ 1000;
		for (i = Length - 1; i > 0;i--)
		for(k = 0; k < i; k++)
		{
			temp[k].x = temp[k].x + t*(temp[k + 1].x - temp[k].x);
			temp[k].y = temp[k].y + t*(temp[k + 1].y - temp[k].y);
		}
		CurvePoint[j].x = temp[0].x;
		CurvePoint[j].y = temp[0].y;	
	}
}

void Plot(struct Point point[])
{
	Curve(point);
	initgraph(800, 600, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setorigin(100, 500);
	setaspectratio(1, -1);
	setlinestyle(PS_SOLID, 2);
	//将0添加到范围内
	if (0.0<MinPointY)MinPointY = 0.0;
	if (0.0<MinPointX)MinPointX = 0.0;
	if (0.0>MaxPointY)MaxPointY = 0.0;
	if (0.0>MaxPointX)MaxPointX = 0.0;
	//获取比例尺度
	double ratioX = ((double)600.0 / (MaxPointX - MinPointX));
	double ratioY = ((double)480.0 / (MaxPointY - MinPointY));
	setlinecolor(RED);
	for (int i = 0; i <Length-1;i++)
	{
		line((point[i].x - MinPointX)*ratioX, (point[i].y - MinPointY)*ratioY, (point[i + 1].x - MinPointX)*ratioX, (point[i + 1].y - MinPointY)*ratioY);
	}
	setlinecolor(GREEN);
	for (int i = 0; i <999; i++)
	{
		line((CurvePoint[i].x - MinPointX)*ratioX, (CurvePoint[i].y - MinPointY)*ratioY, (CurvePoint[i + 1].x - MinPointX)*ratioX, (CurvePoint[i + 1].y - MinPointY)*ratioY);	
	}
	setlinecolor(BLACK);
	setlinestyle(PS_DASH, 1);
	line(-800, (0-MinPointY)*ratioY, 800, (0 - MinPointY)*ratioY);
	line((0 - MinPointX)*ratioX, -600, (0 - MinPointX)*ratioX,600);
}
	
