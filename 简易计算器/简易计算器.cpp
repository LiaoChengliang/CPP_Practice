#include<stdio.h>
#include<stdlib.h>
struct con
{
	char x;//������š�+ - * /��
	int y;//��
	struct con *next;
};
int fun(char c)
{
	int b = int(c - '0');
	return b;
}
void main()
{
	struct con *p, *q, *head;
	char a;
	int num1 = 0;
	int num = 0;
	//--------------------------------������ʽ����ͷ�ڵ�Ϊ head ----------------------------------
	printf("��������ʽ��");
	p = (struct con*)malloc(sizeof(struct con));
	head = q = p;
	head->x = getchar();
	while (1)
	{
		a = getchar();
		if (a != '\n')
		{
			p = (struct con*)malloc(sizeof(struct con));
			q->next = p;
			p->x = a;
			q = p;
		}
		else
			break;
	}
	p->next = NULL;
	p = head;
	//------------------------------------------------������-------------------------------------
	num1 = fun(p->x);
	if (p->next != NULL)
	{
		while (p->next->x <= '9'&&p->next->x >= '0')
		{
			p = p->next;
			num1 = num1 * 10 + fun(p->x);
			if (p->next == NULL)break;
		}
	}	
	head->y = num1;
	head->x = '+';
	if (p->next != NULL)
	{
		head->next = p->next;
		q = p = head;
		while (1)
		{
			if (p->next != NULL)
			{
				q->next = p->next;
				q = p = p->next;
				p = p->next;
				num1 = fun(p->x);
				if (p->next != NULL)
				{
					while (p->next->x <= '9'&&p->next->x >= '0')
					{
						p = p->next;
						num1 = num1 * 10 + fun(p->x);
						if (p->next == NULL)break;
					}
				}
				q->y = num1;
			}
			else
			{
				q->next = NULL;
				break;
			}
		}
		//------------------------------------------------����˳�----------------------------------------
		q = p = head;
		do
		{
			q = p;
			p = p->next;

			switch (p->x)
			{
			case'*':
				q->y = q->y*p->y;
				if (p->next != NULL)
				{
					q->next = p->next;
					p = q;
				}
				else
					q->next = NULL;
				break;
			case'/':
				q->y = q->y / p->y;
				if (p->next != NULL)
				{
					q->next = p->next;
					p = q;
				}
				else
					q->next = NULL;
				break;
			default:break;
			}
		} while (p->next != NULL);
		//------------------------------------------------����Ӽ�----------------------------------------
		p = head;
		num = head->y;
		if(p->next!=NULL)
		do
		{
			p = p->next;
			switch (p->x)
			{
			case '+':num = num + p->y; break;
			case '-':num = num - p->y; break;
			default:break;
			}
		} while (p->next != NULL);

	}
	else
		num = head->y;
	printf("%d", num);






	//-----------------------------------------------------------ѭ������-------------------------------
	while (1)
	{

		head->y = num;
		q = head;
		p = (struct con*)malloc(sizeof(struct con));
		q->next = p;
		q = p;
		p->x = getchar();
		while (1)
		{
			a = getchar();
			if (a != '\n')
			{
				p = (struct con*)malloc(sizeof(struct con));
				q->next = p;
				p->x = a;
				q = p;
			}
			else
				break;
		}
		p->next = NULL;
		q = p = head;
		//-----------------------------������----------------

		while (1)
		{
			if (p->next != NULL)
			{
				q->next = p->next;
				q = p = p->next;
				p = p->next;
				num1 = fun(p->x);
				if (p->next != NULL)
				{
					while (p->next->x <= '9'&&p->next->x >= '0')
					{
						p = p->next;
						num1 = num1 * 10 + fun(p->x);
						if (p->next == NULL)break;
					}
				}
				q->y = num1;
			}
			else
			{
				q->next = NULL;
				break;
			}
		}


//--------------------------����˳�-------------------------------
		q = p = head;
		do
		{
			q = p;
			p = p->next;

			switch (p->x)
			{
			case'*':
				q->y = q->y*p->y;
				if (p->next != NULL)
				{
					q->next = p->next;
					p = q;
				}
				else
					q->next = NULL;
				break;
			case'/':
				q->y = q->y / p->y;
				if (p->next != NULL)
				{
					q->next = p->next;
					p = q;
				}
				else
					q->next = NULL;
				break;
			default:break;
			}
		} while (p->next != NULL);
		//------------------------------------------------����Ӽ�----------------------------------------
		p = head;
		num = head->y;
		if(p->next!=NULL)
		do
		{
			p = p->next;
			switch (p->x)
			{
			case '+':num = num + p->y; break;
			case '-':num = num - p->y; break;
			default:break;
			}
		} while (p->next != NULL);
		printf("%d", num);
	}		
}