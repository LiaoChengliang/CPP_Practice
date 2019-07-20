//遗传算法
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
long a[4],a1[4],a2[4],a3[4];
long b[4],b1[4],b2[4],b3[4];
long c[4];
long d[4];
long e[4]={0};
long p=0,q=0,t=1,pr;
long max,x,y;
long inter(long sp,long sq);
long fun(long v1,long v2);
void main()
{
    long i,j;
	long m;
	long k=0,w;
	srand(time(NULL));
	for(i=0;i<4;i++)
	{	
		a[i]=rand()%7+1;
		b[i]=rand()%7+1;
	}
	while(t<=500)
	{
		printf("\n%d\n",t);
	k=0;
	for(i=0;i<4;i++)
	{
	    c[i]=fun(a[i],b[i]);
		k+=c[i];
		d[i]=k;
	}
	for(i=0;i<4;i++)
		e[i]=0;
	for(i=0;i<4;i++)
	{
		m=rand()%k+1;
		if(m<=d[0])
			e[0]++;
		else if(m<=d[1])
			e[1]++;
		else if(m<=d[2])
			e[2]++;
		else if(m<=d[3])
			e[3]++;	
	}
    p=0,q=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<e[i];j++)
		{
			a1[p]=a[i],p++;
			b1[q]=b[i],q++;
		}	
	}
	m=rand()%3;//  ------------------------------------------------ 随机配对,交叉
	p=inter(a1[3]*2*2*2+b1[3],a1[m]*2*2*2+b1[m]);
	a2[3]=p/(long)pow(2,3);
	b2[3]=p%(long)pow(2,3);
	p=inter(a1[m]*2*2*2+b1[m],a1[3]*2*2*2+b1[3]);
	a2[m]=p/(long)pow(2,3);
	b2[m]=p%(long)pow(2,3);
		
	for(i=0;i<3;i++)
	{
		if(i!=m)
		{
			k=i;
			break;
		}
	}
	for(i=0;i<3;i++)
	{
		if(i!=m&&i!=k)
		{
			w=i;
			break;
		}
	}
	p=inter(a1[k]*2*2*2+b1[k],a1[w]*2*2*2+b1[w]);
	a2[k]=p/(long)pow(2,3);
	b2[k]=p%(long)pow(2,3);
	p=inter(a1[w]*2*2*2+b1[w],a1[k]*2*2*2+b1[k]);
	a2[w]=p/(long)pow(2,3);
	b2[w]=p%(long)pow(2,3);

	
//-------------------------------------------------------------------------------------------
	//---------------------------------------------变异----------------------------------------------
	for(i=0;i<4;i++)
	{
		a3[i]=a2[i];
		b3[i]=b2[i];
	}	
	
	for(i=0;i<4;i++)
	{ 
		pr=rand()%40;
		if(pr<6)
		{
		p=a2[i];
		q=b2[i];
		p=p*2*2*2;
		p=p+q;
		q=p;
		p=p>>pr;printf("%-5d%-5d\n\n\n",pr,p);
		if(p%2==1)
		p=p/2*2;
		else
		p=p/2*2+1;
		p=p<<pr;
		p=p+q%(long)pow(2,pr);
		a3[i]=p/(long)pow(2,3);
		b3[i]=p%(long)pow(2,3);	
		}
	}
	for(i=0;i<4;i++)
	{
		if(max<fun(a3[i],b3[i]))
		{
			max=fun(a3[i],b3[i]);
			x=a3[i];
			y=b3[i];
		}
	}
	for(i=0;i<4;i++)
	{
		printf("%-5d%-5d%-5d%-5d%-5d%-5d%-5d%-5d%-5d%-5d%-5d\n",a[i],b[i],c[i],d[i],e[i],a1[i],b1[i],a2[i],b2[i],b3[i],b[i]);
	}
	for(i=0;i<4;i++)
	{
		a[i]=a3[i];
		b[i]=b3[i];
	}
	t++;
	}
	printf("\n\n%-5d%-5d%-5d\n",x,y,max);


}

long fun(long v1,long v2)
{
	return long(-pow(v1,2)+8*v1+v2);
}

long inter(long sp,long sq)
{	
	long Ra=rand()%6+1;
	return ((31*(long)pow(2,Ra))&sp)+sq%(long)pow(2,Ra);
}



