#include<stdio.h>
void main()
{
	int a[101];
	int n, i, j,dt=0,num=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	i = n;
	while (i!=1)
	{
		for (j =1; j <i; j++)
		{
			if (a[j] + j >= i)
			{
				dt = i - j;
				i=i-dt;	
				num++;	
				break;
			}
		}
	
	}
	printf("%d",num);	
}