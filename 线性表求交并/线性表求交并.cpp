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

	//--------------------------------����X����ͷ�ڵ�Ϊ head_X  ----------------------------------
	printf("������X�����ַ�����");
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


	//---------------------------------����Y����ͷ�ڵ�Ϊ head_Y--------------------------------------
	printf("������Y�����ַ�����");
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


	//------------------------------�������Ƚ�---------------------------------------
	p = head_X;
	q = head_Y;
	pr = (struct mon*)malloc(sizeof(struct mon));//�հ�
	head_XX = pr;
	qr =(struct mon*)malloc(sizeof(struct mon));//ջ��
	qr->next = NULL;
	pr->next = p;//prָ��p��ǰһ���ڵ�
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

	//-----------------------------�����X,Y-------------------------------	
	printf("��X�����ַ�����");
	p = head_XX->next;
	do
	{
		printf("%c", p->x);
		p = p->next;
	} while (p->next != NULL);
	printf("%c", p->x);
	printf("\n");

	printf("��Y�����ַ�����");
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
