#include<stdio.h>
#include<stdlib.h>
struct mon
{
	char x;
	struct mon *next;
};
void main()
{
	struct mon *p, *q, *pr, *qr, *head_X, *head_Y, *head_XX;
	char a;

	//--------------------------------创建X链表，头节点为 head_X  ----------------------------------
	printf("请输入X链表字符串：");
	p = (struct mon*)malloc(sizeof(struct mon));
	head_X = q = p;
	head_X->x = getchar();
	while (1)
	{
		a = getchar();
		if (a != '\n')
		{
			p = (struct mon*)malloc(sizeof(struct mon));
			q->next = p;
			p->x = a;
			q = p;
		}
		else
			break;
	}
	p->next = NULL;


	//---------------------------------创建Y链表，头节点为 head_Y--------------------------------------
	printf("请输入Y链表字符串：");
	p = (struct mon*)malloc(sizeof(struct mon));
	head_Y = q = p;
	head_Y->x = getchar();
	while (1)
	{
		a = getchar();
		if (a != '\n')
		{
			p = (struct mon*)malloc(sizeof(struct mon));
			q->next = p;
			p->x = a;
			q = p;
		}
		else
			break;
	}
	p->next = NULL;


	//------------------------------遍历，比较---------------------------------------
	p = head_X;
	q = head_Y;
	pr = (struct mon*)malloc(sizeof(struct mon));//空白
	head_XX = pr;
	qr =(struct mon*)malloc(sizeof(struct mon));//栈顶
	qr->next = NULL;
	pr->next = p;//pr指向p的前一个节点
	int t = 0;
	for (p = head_X; p->next != NULL; pr = p, p = p->next)
	{
		for (q = head_Y; q->next != NULL; q = q->next)
		{
			if (p->x == q->x) t++;
		}
		if (p->x == q->x) t++;
		if (!t)
		{

			pr->next = p->next;
			p->next = qr;
			qr = p;
			p = pr;

		}
		t = 0;
	}

	for (q = head_Y; q->next != NULL; q = q->next)
	{
		if (p->x == q->x) t++;
	}
	if (p->x == q->x) t++;
	if (!t)
	{
		pr->next = NULL;
		p->next = qr;
		qr = p;
	}
	p = head_Y;
	while (1)
	{
		p = p->next;
		if (p->next == NULL)
		{
			p->next = qr;
			break;
		}

	}

	//-----------------------------输出新X,Y-------------------------------	
	printf("新X链表字符串：");
	p = head_XX->next;
	do
	{
		printf("%c", p->x);
		p = p->next;
	} while (p->next != NULL);
	printf("%c", p->x);
	printf("\n");

	printf("新Y链表字符串：");
	p = head_Y;
	do
	{
		printf("%c", p->x);
		p = p->next;
	} while (p->next != NULL);
	printf("%c", p->x);
	printf("\n");
	system("pause");
}
