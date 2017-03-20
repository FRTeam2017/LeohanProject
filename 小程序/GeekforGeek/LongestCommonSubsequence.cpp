/*
	问题描述
		最常公共子序列问题
	解决方法
		在两个序列的最常公共子序列已知的情况下，如果两个公共子序列的下一个元素相同的时候
		那么这两个序列的最常公共子序列的最常公共子序列的长度+1
		否则就是两个序列的长度中某一个元素少一的情况下两个序列的最常公共子序列
*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int lcs(char *X, char *Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcs(X, Y, m - 1, n - 1);
	else
		return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}
int LCS()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	printf("Length of LCS is %d\n", lcs(X, Y, m, n));

	return 0;
}