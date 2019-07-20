#include<iostream>
int w[] = { 2, 2, 6, 5, 4 };
int v[] = { 6, 3, 5, 4, 6 };
int fun(int i,int j)
{
	if (i < 0||j - w[i]< 0)
		return 0;
	return fun(i - 1, j - w[i]) + v[i] > fun(i - 1, j) ? fun(i - 1, j - w[i]) + v[i] : fun(i - 1, j);
}
int main()
{
	std::cout<<fun(5,10);
	std::cin.get();
	return 0;
}