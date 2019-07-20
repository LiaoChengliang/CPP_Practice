#include <stdio.h>
int fun(int a,int b);
int main()
{
	int n,i,j;
	printf("请请输入一个数（1-34）:");
	do
	{
		scanf("%d",&n);
		if(n<1||n>34)
			printf("请重新输入:");
	}while(n<1||n>34);

	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d ",fun(i,j));
		}
		printf("\n");
	}
	return 0;
}
int fun(int a,int b)
{
	
	if(b==0||a==b)
		return 1;
	else
		return (fun(a-1,b-1)+fun(a-1,b));
}
