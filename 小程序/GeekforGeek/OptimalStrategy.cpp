#include<iostream>
#include<stdio.h>
#include<limits.h>
int mmax(int a, int b)
{
	return a > b ? a : b;
}
int mmin(int a, int b)
{
	return a < b ? a : b;
}
int optimalStrategyOfGame(int * arr, int n)
{
	//分配一个二维数组
	int ** table = (int **)malloc(sizeof(int *)* n);
	for (int i = 0; i < n; i++)
		table[i] = (int *)malloc(sizeof(int)*n);
	int gap, i, j, x, y, z;
	for (gap = 0; gap < n; gap++)
	{
		for (i = 0, j = gap; j < n; ++i, ++j)
		{
			x = ((i + 2) <= j) ? table[i + 2][j] : 0;
			y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
			z = (i <= (j - 2)) ? table[i][j - 2] : 0;
			table[i][j] = mmax(arr[i] + mmin(x, y), arr[j] + mmin(y, z));
		}
	}
	return table[0][n - 1];
}