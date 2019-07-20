#include<stdio.h>
void main()
{
	int a[101];
	int n,i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	if(a[n]!=9)
	{ 
		a[n] += 1;
		for (i = 1; i <= n; i++)
			printf("%d ", a[i]);
	}
	else
	{
		for (j = n; j >= 1; j--)
		{
			if (a[j] == 9)
			{
				a[j] = 0;
			}
			else
				break;
		}
		a[j] += 1;
		if(a[0]==1)
			printf("%d ", a[i]);
		for (i =1; i <= n; i++)
			printf("%d ", a[i]);
	}
	
	
}