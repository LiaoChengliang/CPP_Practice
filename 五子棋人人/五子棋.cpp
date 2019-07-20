#include<graphics.h>
#define WIDTH 528
#define HEIGHT 528
MOUSEMSG m;
int a[16][16]={0};
int i,j,u,v,success=0,t=1;
int p,q;
void chk();
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
			if(t==1)
			{
			  setfillcolor(BLACK);
		      fillcircle(p,q,WIDTH/48);
			  a[q*16/WIDTH][p*16/WIDTH]=1;
			  chk();
			  t=2;
			}
		    else
			{
			   setfillcolor(WHITE);
		       fillcircle(p,q,WIDTH/48);
			   a[q*16/WIDTH][p*16/WIDTH]=2;	
			   chk();
			   t=1;
			}
			}		
		}
	   }	   
	}
	    RECT r = {0, 0, WIDTH, HEIGHT/16};
		settextstyle( HEIGHT/16, 0, _T("宋体"));
		if(t==2)
		{
	        drawtext(_T("黑方胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	
		}
		if(t==1)
		{
	        drawtext(_T("白方胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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