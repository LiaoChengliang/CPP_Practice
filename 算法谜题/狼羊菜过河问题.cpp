#include<iostream>
using namespace std;
/*
一共以下十种状态：
1.（人狼羊菜，NULL）2.（人羊，狼菜）3.（人狼羊，菜）4.（人狼菜，羊）5.（人羊菜，狼）
 6.（NULL，人狼羊菜）7.（狼菜，人羊）8.（菜，人狼羊）9.（羊，人狼菜）10.（狼，人羊菜）
*/
class puzzle_1//狼羊菜过河问题
{
public:
	int a[11][11];
	puzzle_1()
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				a[i][j] = 0;
			}
		}
		a[1][7] = a[7][1] = 1;
		a[2][6] = a[6][2] = 1;
		a[2][9] = a[9][2] = 1;
		a[3][9] = a[9][3] = 1;
		a[3][10] = a[10][3] = 1;
		a[4][7] = a[7][4] = 1;
		a[4][8] = a[8][4] = 1;
		a[4][10] = a[10][4] = 1;
		a[5][8] = a[8][5] = 1;
		a[5][9] = a[9][5] = 1;
	}
	void search()//寻路，从1号位到6号位;
	{	
		int last = 6;
		int temp[10];
		int t = 1;
		temp[0] = 1;
		temp[1] = 7;
		int flag = 7;
		while (1)
		{
			for (int i = 1; i <= 10; i++)
			{
				if ((a[flag][i] == 1) && (i != temp[t - 1]))
				{
					t++;
					flag=temp[t] = i;
					break;
				}
			}
			if (flag == last)
				break;
		}
		cout << "顺序依次为：" << endl;
		for (int i = 0; i <= t; i++)
		{
			cout << temp[i] <<"  ";
		}
	}
};
