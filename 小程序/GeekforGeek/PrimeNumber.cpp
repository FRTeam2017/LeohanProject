/*
	问题描述
		Fermat's 小理论
		如果n是素数，那么对于任何的 1 <= a < n
		都有 a^(n-1)%n = 1
*/
#include<iostream>
using namespace std;
int power2(int a, unsigned int n, int p)
{
	int res = 1;
	a = a % p;
	while (n > 0)
	{
		if (n & 1)
			res = (res* a) % p;
		n = n >> 1;
		a = (a * a) % p;
	}
	return res;
}
/*
	k的值越大，判断的准确率越高
*/
bool isPrime(unsigned int n, int k)
{
	if (n <= 1 || n == 4)
		return false;
	if (n <= 3)
		return true;
	while (k > 0)
	{
		int a = 2 + rand() % (n - 4);
		if (power2(a, n - 1, n) != 1)
		{
			return false;
		}
		k--;
	}
	return true;
}

