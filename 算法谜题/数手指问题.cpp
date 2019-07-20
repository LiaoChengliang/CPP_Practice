#include<iostream>
using namespace std;
class puzzle_2//数手指问题
{
public:
	int a[8];
	void fun()
	{
		int i = 0;
		int k = 1;
		while (1)
		{
			a[i] = k;
			if (k == 1000)
			{
				cout << i;
				break;
			}
			k++;
			i++;
			if (i == 8)
				i = 0;
		}
	}
};