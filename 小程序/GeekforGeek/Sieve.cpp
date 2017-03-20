#include<iostream>
using namespace std;
void SieveOfEratosthenes(int n)
{
	bool *prime = (bool *)malloc(sizeof(bool)*(n+1));
	memset(prime, true, sizeof(prime));
	for (int p = 2; p*p < n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	//打印所有的素数
	for (int p = 2; p <= n; p++)
	{
		if (prime[p])
			cout << p << " ";
	}
}