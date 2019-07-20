#include<stdio.h>
#include<graphics.h>
//��������������
#define N 50  
//����"��"�ṹ��;
struct Point
{
	double x;
	double y;
}point[N];
//�洢 ����������1000��������
struct Point CurvePoint[1000];
//��ʼ������������
int Length=0;
//�����������ֵ
double MaxPointX, MaxPointY, MinPointX, MinPointY;
//��ȡ����
void GetPoint(struct Point point[]);
//��ӵ���
void AddPoint(struct Point point[],int length);
//���㱴��������
void Curve(struct Point point[]);
//����ͼ��
void Plot(struct Point point[]);
//�޸�ĳ��
void AlterPoint(struct Point point[]);
//�Ե�������
void Sort(struct Point point[],int length);
//ѡ�������ʾ˵��
void operate();
int main()
{
	GetPoint(point);//��ȡ��ʼ����
	Sort(point,Length);//�Գ�ʼ��������
	while (1){
		operate();
		int Option;
		scanf("%d",&Option);
		//ѡ�����
		switch (Option)
		{
		case 1:AlterPoint(point); Sort(point,Length); break;
		case 2:AddPoint(point, Length); Sort(point,Length); break;
		case 3:Plot(point); break;
		case 4:return 0; break;
		default:printf("���ݲ��Ϸ������������룡\n"); break;
		}
	    printf("\n");
	}
	return 0;
}
void operate()
{
	printf("------------����˵��-------------\n");
	printf("----------1.�滻����-------------\n");
	printf("----------2.�������-------------\n");
	printf("----------3.����ͼ��-------------\n");
	printf("----------4.�˳�����-------------\n");
	printf("�����������");
}
void GetPoint(struct Point point[])
{
	int i=0,num;
	printf("����������������");
	scanf("%d", &num);
	printf("���������ݣ�");
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
	printf("��������Ҫ�޸ĵ�λ�ã�");
	scanf("%d", &num);
	printf("��Ҫ�޸�Ϊ��");
	scanf("%lf", &point[num - 1].x);
	scanf("%lf", &point[num - 1].y);
}

void AddPoint(struct Point point[],int length)
{
	int i=length;
	int num;
	printf("���������");
	scanf("%d",&num);
	printf("���������ݣ�");
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
	//��0��ӵ���Χ��
	if (0.0<MinPointY)MinPointY = 0.0;
	if (0.0<MinPointX)MinPointX = 0.0;
	if (0.0>MaxPointY)MaxPointY = 0.0;
	if (0.0>MaxPointX)MaxPointX = 0.0;
	//��ȡ�����߶�
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
	
