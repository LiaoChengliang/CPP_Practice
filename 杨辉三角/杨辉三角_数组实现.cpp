#include <stdio.h>
int main()
{
	int n,i,j;
	int a[34][34];
	printf("请请输入一个数（1-34）:");
	do
	{
		scanf("%d",&n);
		if(n<1||n>34)
			printf("请重新输入:");
	}while(n<1||n>34);

	for(i=0;i<=n-1;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	i=0;
	while(i<n)
	{
	   	printf("%d ",a[i][0]);
	   	for(j=1;j<=i-1;j++)
		{			
		    a[i][j]=a[i-1][j-1]+a[i-1][j];
		   	printf("%d ",a[i][j]);
		}
		if(i!=0)
	        printf("%d",a[i][i]);
		printf("\n");
	   	i++;
	}		
	return 0;
}
