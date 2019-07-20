#include<stdio.h>
void main()
{
	int a[501];
	int n,i,j,t=1;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	i = 1;
	while (i<n)
	{	
		if(a[i]==0)
		{
			t=0;
			for(j=1;j<i;j++)
			{
				if(a[j]+j>i)
				{			
					t++;
				}
			}
			if(t==0)
			{
				printf("false");
				break;
			}
		}
		i++;
	}
	if(t)
	{
		printf("true");
	}
}