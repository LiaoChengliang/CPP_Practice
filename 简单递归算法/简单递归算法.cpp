#include<iostream>
using namespace std;
class recursion//递归算法实现
{
public:
	//求一个整数的阶乘
	int funA(int num)
	{
		if (num == 1)
		{
			return 1;
		}
		return num*funA(num-1);
	}

	/*一个人赶着鸭子去每个村庄卖，每经过一个村子卖去所赶鸭子的一半又一只。
	这样他经过了七个村子后还剩两只鸭子，问他出发时共赶多少只鸭子？
	经过每个村子卖出多少只鸭子？*/
	int funB(int num)
	{
		if (num == 0)
		{
			return 2;
		}
		return (funB(num-1)+1)*2;
	}

	/*角谷定理。输入一个自然数，若为偶数，则把它除以2，若为奇数，则把它乘以3加1。
	经过如此有限次运算后，总可以得到自然数值1。求经过多少次可得到自然数1。
	如：输入22，
	输出 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
	STEP = 16*/
	int t=0;
	int funC(int num)
	{
		t++;
		if (num == 1)
		{
			cout << 1 << " ";
			cout <<"Step：" <<t << endl;
			return 1;
		}
		else
			cout << num << " ";
		if (num%2==0)
		return funC(num/2);
		if (num % 2 != 0)
			return funC(num*3+1);
	}
	
	/*斐波那契数列第n项的值*/
	long funD(int num)
	{
		if (num == 1||num==2)
			return 1;
		return funD(num - 1) + funD(num - 2);
	}


};