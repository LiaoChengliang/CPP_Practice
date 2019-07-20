#include<stdio.h>
void main()
{
	long a[2000];
	a[0]=2;
	long i,j=1,t=1,d=3;
	while(j<2000)
	{
		for(i=2;i<d;i++)
		{
			if(d%i==0)
				t=0;			
		}
		if(t==1)
		{
			a[j]=d;
			j++;
		}
		else t=1;
		d++;		
	}
	/*for(i=0;i<2000;i++)
	{
		printf("%-6d",a[i]);
		if((i+1)%25==0)
			printf("\n");
	}*/
	for(i=4;i<=17388;i+=2)
	{
		for(j=0;j<2000;j++)
		{
			for(d=0;d<2000;d++)
			{
				if(i==a[j]+a[d])
				{
					printf("%-6d",i);
					if((i/2-1)%20==0)
						printf("\n");
					break;
				}
			}
			if(i==a[j]+a[d])	
				break;
			
		}
	}
	getchar();

}
