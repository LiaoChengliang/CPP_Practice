#include<graphics.h>
#define WIDTH 480
#define HEIGHT 480
MOUSEMSG m;
int a[16][16]={0};
int b[16][16];
int i,j,u,v,success=0,t=1;
int p,q;
int max[3]={0};
void chk();
int add();
void VALUE();
long qixing;
void value();
void choose();
int huoqi=1;
void main()
{
	
	initgraph(WIDTH,HEIGHT);
	loadimage(NULL,"bk.jpg");
	j=0;
	for(i=1;i<=15;i++)
	{
		j+=WIDTH/16;
		setlinecolor(BLACK);
		line(WIDTH/16,j,WIDTH*15/16,j);
		line(j,WIDTH/16,j,WIDTH*15/16);
	}	
	while(success<5)
	{
	while(t==1)
	{
	   m=GetMouseMsg();
	   if(m.uMsg==WM_LBUTTONDOWN)
	   {	
		if(m.x>=WIDTH/24&&m.x<=WIDTH*23/24&&m.y>=WIDTH/24&&m.y<=WIDTH*23/24
		  &&(m.x%(WIDTH/16)<=(WIDTH/48)||m.x%(WIDTH/16)>=(WIDTH/24))
		  &&(m.y%(WIDTH/16)<=(WIDTH/48)||m.y%(WIDTH/16)>=(WIDTH/24)))
		{
			if(m.x%(WIDTH/16)<=(WIDTH/48)) p=m.x/(WIDTH/16)*WIDTH/16;
			else p=m.x/(WIDTH/16)*WIDTH/16+WIDTH/16;
			if(m.y%(WIDTH/16)<=(WIDTH/48)) q=m.y/(WIDTH/16)*WIDTH/16;
			else q=m.y/(WIDTH/16)*WIDTH/16+WIDTH/16;
			if(a[q*16/WIDTH][p*16/WIDTH]==0)
			{
			  setfillcolor(BLACK);
		      fillcircle(p,q,WIDTH/48);
			  a[q*16/WIDTH][p*16/WIDTH]=1;
			  chk();	  
			  t=2;
			}
					
		}
	   }
	}   
	    if(success>=5)break;
	    Sleep(300);
	    value();	
		if(huoqi==1)
		{
	       choose();
		   
		}
		else
			huoqi=1;
        setfillcolor(WHITE);
	    fillcircle(max[2]*WIDTH/16,max[1]*WIDTH/16,WIDTH/48);
		a[max[1]][max[2]]=2;
		q=max[1]*WIDTH/16;
		p=max[2]*WIDTH/16;
		chk();	
	    t=1;
		if(success>=5)break;			
	}
	    RECT n = {0, 0, WIDTH, HEIGHT/16};
		settextstyle( HEIGHT/16, 0, _T("宋体"));
		if(t==2)
		{
	        drawtext(_T("黑方胜利"), &n, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	
		}
		if(t==1)
		{
	        drawtext(_T("白方胜利"), &n, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		system("pause");
	    closegraph();
}
void chk()
{
	//---------------------左右------------------------------
	success=0;
	for(j=p*16/WIDTH-4;j<=p*16/WIDTH+4;j++)
	{
		if(j<1||j>15)
			continue;
		if(a[q*16/WIDTH][j]==t)
			success++;
		else
			success=0;
		if(success>=5)
			return;
	}
	success=0;
	//----------------------上下-----------------------------------
	for(i=q*16/WIDTH-4;i<=q*16/WIDTH+4;i++)
	{
		if(i<1||i>15)
			continue;
		if(a[i][p*16/WIDTH]==t)
			success++;
		else
			success=0;
		if(success>=5)
			return;
	}
	success=0;
	//-----------------------左上到右下-------------------------
	for(i=q*16/WIDTH-4,j=p*16/WIDTH-4;i<=q*16/WIDTH+4&&j<=p*16/WIDTH+4;i++,j++)
	{
		if(i<1||i>15||j<1||j>15)
			continue;
		if(a[i][j]==t)
			success++;
		else
			success=0;
		if(success>=5)
			return;
	}
	success=0;
	//------------------------左下到右上--------------------------------
	for(i=q*16/WIDTH+4,j=p*16/WIDTH-4;i>=q*16/WIDTH-4&&j<=p*16/WIDTH+4;i--,j++)
	{
		if(i<1||i>15||j<1||j>15)
			continue;
		if(a[i][j]==t)
			success++;
		else
			success=0;
		if(success>=5)
			return;
	}

}


int add(int kkk)
{
	if(kkk>=5)
		return 20000;
	else if(kkk>=4)
		return 10000;
	else if(kkk>=3)
		return 2000;
	else if(kkk<3)
		return 50;
}

void value()
{

	for(i=1;i<=15;i++)
		for(j=1;j<=15;j++)
			b[i][j]=0;
	int r,s,mark,k;
	for(i=1;i<=15;i++)
	 for(j=1;j<=15;j++)
		{
			if(a[i][j]==0)
			{

	//---------------------左右------------------------------
	mark=k=0;
    a[i][j]=1;
	for(s=j-4;s<=j+4;s++)
	{
		if(s<1||s>15)
			continue;
		if(a[i][s]==1)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(s<j)
				k=0;
			if(s>j)
				break;
		}
		b[i][j]+=add(k);
	}
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;
		huoqi=0;
	
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}

	
	mark=k=0;
	a[i][j]=2;
	for(s=j-4;s<=j+4;s++)
	{
		if(s<1||s>15)
			continue;
		if(a[i][s]==2)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(s<j)
				k=0;
			if(s>j)
				break;
		}
		b[i][j]+=add(k);
	}
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
	
		
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}
	
	
	//----------------------上下-----------------------------------
	mark=k=0;
	a[i][j]=1;
	for(r=i-4;r<=i+4;r++)
	{
		if(r<1||r>15)
			continue;
		if(a[r][j]==1)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(r<i)
				k=0;
			if(r>i)
				break;
		}
	}	
	b[i][j]+=add(k);
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
	
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}
	
	mark=k=0;
	a[i][j]=2;
	for(r=i-4;r<=i+4;r++)
	{
		if(r<1||r>15)
			continue;
		if(a[r][j]==2)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(r<i)
				k=0;
			if(r>i)
				break;
		}
			
	}b[i][j]+=add(k);
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
	
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}
    

	//-----------------------左上到右下-------------------------
	mark=k=0;
	a[i][j]=1;
	for(r=i-4,s=j-4;r<=i+4&&s<=j+4;r++,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		if(a[r][s]==1)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(r<i)
				k=0;
			if(r>i)
				break;
		}
	
	}b[i][j]+=add(k);
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
	
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}
	
	mark=k=0;
	a[i][j]=2;
	for(r=i-4,s=j-4;r<=i+4&&s<=j+4;r++,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		if(a[r][s]==2)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(r<i)
				k=0;
			if(r>i)
				break;
		}
			
	}b[i][j]+=add(k);
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
	
	
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}
   
	//------------------------左下到右上--------------------------------
	mark=k=0;
	a[i][j]=1;
	for(r=i+4,s=j-4;r>=i-4&&s<=j+4;r--,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		if(a[r][s]==1)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(s<j)
				k=0;
			if(s>j)
				break;
		}
			
	}b[i][j]+=add(k);
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}

	mark=k=0;
	a[i][j]=2;
	for(r=i+4,s=j-4;r>=i-4&&s<=j+4;r--,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		if(a[r][s]==2)
			mark++;
		else 
		{
			if(mark>k) k=mark;
		    mark=0;
			if(s<j)
				k=0;
			if(s>j)
				break;
		}
	
	}b[i][j]+=add(k);
	if(k>=4)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
	//
	}
	if(k>=5)
	{
		max[1]=i;
		max[2]=j;
		a[i][j]=0;huoqi=0;
		return;
	//
	}
	a[i][j]=0;				
		}
	}	
}
void choose()
{
	max[0]=0;
	for(i=1;i<=15;i++)
		for(j=1;j<=15;j++)
		{
			if(b[i][j]>max[0])
			{
				max[0]=b[i][j];
				max[1]=i;
				max[2]=j;
			}
		}
}
/*void VALUE()
{
	for(i=1;i<=15;i++)
		for(j=1;j<=15;j++)
			b[i][j]=0;
	int r,s;
	for(i=1;i<=15;i++)
	 for(j=1;j<=15;j++)
		{
			if(a[i][j]==0)
			{

	//---------------------左右------------------------------
	qixing=0;
    a[i][j]=1;
	for(s=j-4;s<=j+4;s++)
	{
		if(s<1||s>15)
			continue;
		qixing=qixing*10+a[i][s];
	}
	
	qixing=0;
	a[i][j]=2;
	for(s=j-4;s<=j+4;s++)
	{
		if(s<1||s>15)
			continue;
		qixing=qixing*10+a[i][s];
	}
	
	
	//----------------------上下-----------------------------------
	qixing=0;
	a[i][j]=1;
	for(r=i-4;r<=i+4;r++)
	{
		if(r<1||r>15)
			continue;
		qixing=qixing*10+a[r][j];		
	}	

    qixing=0;
	a[i][j]=2;
	for(r=i-4;r<=i+4;r++)
	{
		if(r<1||r>15)
			continue;
		qixing=qixing*10+a[r][j];		
			
	}
    

	//-----------------------左上到右下-------------------------
	qixing=0;
	a[i][j]=1;
	for(r=i-4,s=j-4;r<=i+4&&s<=j+4;r++,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		qixing=qixing*10+a[r][s];		
	
	}

    qixing=0;
	a[i][j]=2;
	for(r=i-4,s=j-4;r<=i+4&&s<=j+4;r++,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		qixing=qixing*10+a[r][s];		
			
	}
   
	//------------------------左下到右上--------------------------------
    qixing=0;
	a[i][j]=1;
	for(r=i+4,s=j-4;r>=i-4&&s<=j+4;r--,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		qixing=qixing*10+a[r][s];					
	}

	qixing=0;
	a[i][j]=2;
	for(r=i+4,s=j-4;r>=i-4&&s<=j+4;r--,s++)
	{
		if(r<1||r>15||s<1||s>15)
			continue;
		qixing=qixing*10+a[r][s];		
	}
	a[i][j]=0;				
		}
	}	
}
*/