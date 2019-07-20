#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>

//#define width 26
//#define height 24
#define x0 11
#define y0 1
//#define unitx 30
//#define widthm 40
//#define heightm 5
int k=x0,h=y0,p;

void loc(int x,int y);


void creatmap();
void creatblock();
int checkdown();
void down();
void sdown();
void left();
void right();
void sink();
void rotate();
void remove();

void pause();
void GameOver();


int a[30][25];
int b[4][4];
int c[23];
int m[20][4][4]={
{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
{1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0}, 
{0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0}, 
{1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0}, 
{1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0}, 
{1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0}, 
{1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0}, 
{0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0}, 
{1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0}, 
{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0}, 
{1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
{0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0}, 
{0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0}, 
{1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0}, 
{1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0}, 
{1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0}, 
{0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
{0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0}} ;


void creatmap()
{
	int i,j;	
	system("title 俄罗斯方块");
	system("mode concols=50 lines=31");
	system("color 0A");
	for(i=0;i<=24;i++)
	{
		printf("%c%c", '\xA1', '\xF6');
		a[0][i]=1;
	}
	for(j=1;j<=27;j++)
	{
        printf("%c%c", '\xA1', '\xF6');
		a[j][0]=1;
		for(i=1;i<=23;i++)
		{
			printf("  ");
			a[j][i]=0;
		}
		printf("%c%c", '\xA1', '\xF6');
		a[j][24]=1;
	}
	for(i=0;i<=24;i++)
	{
		printf("%c%c", '\xA1', '\xF6');
		a[28][i]=1;
	}
	for(i=0;i<=24;i++)
		a[29][i]=0;
}
void Loc(int x, int y)
{
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
void creatblock()
{
	int i,j;
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
		a[h+i][k+j]|=m[p][i][j];
		}
	}
    for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
		if (a[h+i][k+j]==1)
		{
			Loc(2*(k+j),h+i);
			printf("%c%c", '\xA1', '\xF6');
		}

		}
	}
}

int checkdown()
{
    int i,j,r=1;
	//核对是否能进行：
	for(i=0;i<=3;i++)//权宜
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j]&b[i][j])==1)
				a[h+i][k+j]=0;
		}
	}

//////////////////////////////////////////////
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i+1][k+j]+b[i][j])==2)
			{
				r=0;	
			}
		}
	}

///////////////////////////////////////////////
	for(i=0;i<=3;i++)//返权
	{
		for(j=0;j<=3;j++)
		{
			a[h+i][k+j]|=b[i][j];
		}
	}
	return r;
}


void down()
{
	int i,j;
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j]&b[i][j])==1)
			{
				Loc(2*(k+j),h+i);
				printf("  ");
				a[h+i][k+j]=0;
			}
		}
	}	
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			a[h+i+1][k+j]|=b[i][j];
			if(a[h+i+1][k+j]==1)
			{
				Loc(2*(k+j),h+i+1);
				printf("%c%c", '\xA1', '\xF6');
			}
		}
	}
    h++;

}

void left()
{
	int i,j,r=1;
	for(i=0;i<=3;i++)//权宜
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j]&b[i][j])==1)
				a[h+i][k+j]=0;
		}
	}

//////////////////////////////////////////////
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j-1]+b[i][j])==2)
			{
				r=0;
			
			}
		}
	}

///////////////////////////////////////////////
	for(i=0;i<=3;i++)//返权
	{
		for(j=0;j<=3;j++)
		{
			a[h+i][k+j]|=b[i][j];
		}
	}
   if (r!=0)
{
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j]&b[i][j])==1)
			{
				Loc(2*(k+j),h+i);
				printf("  ");
				a[h+i][k+j]=0;
			}
		}
	}
	
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			a[h+i][k+j-1]|=b[i][j];
			if(a[h+i][k+j-1]==1)
			{
				Loc(2*(k+j-1),h+i);
				printf("%c%c", '\xA1', '\xF6');
			}
		}
	}	k--;
}
   else 
   {}
}
void right()
{
	int i,j,r=1;
	for(i=0;i<=3;i++)//权宜
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j]&b[i][j])==1)
				a[h+i][k+j]=0;
		}
	}

//////////////////////////////////////////////
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j+1]+b[i][j])==2)
			{
				r=0;
			
			}
		}
	}

///////////////////////////////////////////////
	for(i=0;i<=3;i++)//返权
	{
		for(j=0;j<=3;j++)
		{
			a[h+i][k+j]|=b[i][j];
		}
	}
if (r!=0)
{
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j]&b[i][j])==1)
			{
				Loc(2*(k+j),h+i);
				printf("  ");
				a[h+i][k+j]=0;
			}
		}
	}
	
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			a[h+i][k+j+1]|=b[i][j];
			if(a[h+i][k+j+1]==1)
			{
				Loc(2*(k+j+1),h+i);
				printf("%c%c", '\xA1', '\xF6');
			}
		}
	}	
	k++;
}
   else 
   {}
}



void sink()
{
	while(checkdown()==1)
	{		
		down();
	}
}

void sdown()
{
	if(checkdown()==1)
		down();
}

void rotate()
{
	int i,j,r=1;
	for(i=0;i<=3;i++)//权宜
	{
		for(j=0;j<=3;j++)
		{
			if((a[h+i][k+j]&b[i][j])==1)
				a[h+i][k+j]=0;
		}
	}
	////////////////////////////
	for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
		{
			if(a[h+i][k+j]+b[3-j][i]==2)
				r=0;
		}
/////////////////////////////////////////
	for(i=0;i<=3;i++)//返权
	{
		for(j=0;j<=3;j++)
		{
			a[h+i][k+j]|=b[i][j];
		}
	}
	if (i=1)
	{
		for(i=0;i<=3;i++)
			for(j=0;j<=3;j++)
				if ((a[h+i][k+j]&b[i][j])==1)
				{
					Loc(2*(k+j),h+i);
					printf("  ");
					a[h+i][k+j]=0;
				}
		for(i=0;i<=3;i++)
			for(j=0;j<=3;j++)
			{
				a[h+i][k+j]|=b[3-j][i];
				if (a[h+i][k+j]==1)
				{
					Loc(2*(k+j),h+i);
					printf("%c%c", '\xA1', '\xF6');
				}
			}
		for(i=0;i<=3;i++)
			for(j=0;j<=3;j++)
			{
				b[i][j]=a[h+i][k+j];
			
			}
	}
}


void remove()
{
	int i,j,e,s,u,v;
	for(i=28;i>=1;i--)
	{
		for(j=1;j<=23;j++)
		{
			if (a[i][j])
			s++;
		}
		if (s==23)
		{
			Loc(3,i);
			for(e=1;e<=22;e++)
			{
				printf("  ");
				a[i][e]=0;
			}
			for(u=i;u>=8;u--)
				for(v=1;v<=23;v++)
				{
					a[u][v]=a[u-1][v];
					if(a[u][v]==1)
					{
						Loc(2*v,u);
						printf("%c%c", '\xA1', '\xF6');

					}
					else
					{
						Loc(2*v,u);
						printf("  ");
					}
				}

		}
		s=0; 
	}
	

}

void main()
{	
	creatmap();
	int g,i,j;
	do
	{
		h=y0;
	    k=x0;
		p=rand()%20;
    	creatblock();
		for(i=0;i<=3;i++)
			for(j=0;j<=3;j++)
				b[i][j]=a[h+i][k+j];
		if(checkdown()==0)
			break;
		
	while(checkdown()==1)
	{
		_sleep(100);
		down();
		remove();
		for(g=1;g<=3;g++)
		{
		_sleep(100);
		if(kbhit())
		{
		switch(getch())
		{
		case 'A': left();break;
		case 'D': right();break;
		case ' ': sink();break;
		case 'S': sdown();break;
		case 'W': rotate();break;
        default:  getch();
		}
		}
		}
	}
	}while(1);
	getch();

}



