#include<iostream>
using namespace std;
/*
һ������ʮ��״̬��
1.��������ˣ�NULL��2.�������ǲˣ�3.�������򣬲ˣ�4.�����ǲˣ���5.������ˣ��ǣ�
 6.��NULL��������ˣ�7.���ǲˣ�����8.���ˣ�������9.�������ǲˣ�10.���ǣ�����ˣ�
*/
class puzzle_1//����˹�������
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
	void search()//Ѱ·����1��λ��6��λ;
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
		cout << "˳������Ϊ��" << endl;
		for (int i = 0; i <= t; i++)
		{
			cout << temp[i] <<"  ";
		}
	}
};
