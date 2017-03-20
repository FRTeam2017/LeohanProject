#include<iostream>
using namespace std;
int power(int x, unsigned int y)
{
	int res = 1;
	while (y > 0)
	{
		if (y & 1)
			res = res * x;
		y = y >> 1;
		x = x * x;
	}
	return res;
}
int power(int x, unsigned int y, int p)
{
	int res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
