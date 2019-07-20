#include<stdio.h>
#include<stdlib.h>
struct mon
{
	int x;
	struct mon *next;
};
void main()
{
	struct mon *p,*q,*a,*b,*head;
	int m,n,s,i;
	printf("请输入总数： ");
	scanf("%d",&m);
	printf("请输入间隔数： ");
	scanf("%d",&n);
	printf("从第几个开始：  ");
	scanf("%d",&s);
	//循环链表
	head=p=q=(struct mon*)malloc(sizeof(struct mon));
	head->x=1;
	for(i=2;i<=m;i++)
	{
		p=(struct mon*)malloc(sizeof(struct mon));
		q->next=p;
                q=p;
		p->x=i;
		
	}
	p->next=head;
    
	for(i=1;i<=s;i++)
	{
		q=p;
		p=p->next;
	}
	b=(struct mon*)malloc(sizeof(struct mon));
	while(1)
	{
		for(i=1;i<n;i++)
		{
			q=p;
			p=p->next;
		}
		    
			a=(struct mon*)malloc(sizeof(struct mon));
			a->next=b;
			a->x=p->x;
			b=a;

		q->next=p->next;
		p=q->next;
		if(p==q)
			break;
	}
    printf("大王是第%d个\n",p->x);
	for(i=1;i<m;i++)
	{
		printf("%d  ",a->x);
		a=a->next;
	}
    printf("\n");
		
}