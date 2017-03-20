/*
	问题描述
		用欧拉公式求两个数的最大公约数
		如果两个数的最大公约数为1，那么这两个数互质
*/
#include<iostream>
using namespace std;
/*
	求两个数的最大公约数
*/
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}
/*
	
*/
int phi(unsigned int n)
{
	unsigned int result = 1;
	for (int i = 2; i < n; i++)
	{
		if (gcd(i, n) == 1)
		{
			result++;
			cout << i << endl;
		}
	}
	return result;
}