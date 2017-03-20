/*
	生成前n个数的组合
*/
#include<iostream>
#include<algorithm>
using namespace std;
void comb(int N, int k)
{
	string bitmask(k, 1);
	bitmask.resize(N, 0);
	do {
		for (int i = 0; i < N; i++)
		{
			if (bitmask[i])
				cout << " " << i;
		}
		cout << endl;
	} while (prev_permutation(bitmask.begin(), bitmask.end()));
}