#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define N 4

bool wPrefersM1OverM(int prefer[2 * N][N], int w, int m, int m1)
{
	for (int i = 0; i < N; i++)
	{
		if (prefer[w][i] == m1)
			return true;
		if (prefer[w][i] == m)
			return false;
	}
}
