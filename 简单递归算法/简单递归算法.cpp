#include<iostream>
using namespace std;
class recursion//�ݹ��㷨ʵ��
{
public:
	//��һ�������Ľ׳�
	int funA(int num)
	{
		if (num == 1)
		{
			return 1;
		}
		return num*funA(num-1);
	}

	/*һ���˸���Ѽ��ȥÿ����ׯ����ÿ����һ��������ȥ����Ѽ�ӵ�һ����һֻ��
	�������������߸����Ӻ�ʣ��ֻѼ�ӣ���������ʱ���϶���ֻѼ�ӣ�
	����ÿ��������������ֻѼ�ӣ�*/
	int funB(int num)
	{
		if (num == 0)
		{
			return 2;
		}
		return (funB(num-1)+1)*2;
	}

	/*�ǹȶ�������һ����Ȼ������Ϊż�������������2����Ϊ���������������3��1��
	����������޴�������ܿ��Եõ���Ȼ��ֵ1���󾭹����ٴοɵõ���Ȼ��1��
	�磺����22��
	��� 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
	STEP = 16*/
	int t=0;
	int funC(int num)
	{
		t++;
		if (num == 1)
		{
			cout << 1 << " ";
			cout <<"Step��" <<t << endl;
			return 1;
		}
		else
			cout << num << " ";
		if (num%2==0)
		return funC(num/2);
		if (num % 2 != 0)
			return funC(num*3+1);
	}
	
	/*쳲��������е�n���ֵ*/
	long funD(int num)
	{
		if (num == 1||num==2)
			return 1;
		return funD(num - 1) + funD(num - 2);
	}


};