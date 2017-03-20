#include<iostream>
#include<algorithm>
using namespace std;
int findLongestFormACell(int i, int j, int **mat, int **dp,int n)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
	{
		return 0;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1]))
		return dp[i][j] = 1 + findLongestFormACell(i, j + 1, mat, dp, n);
	if (j > 0 && (mat[i][j] + 1) == mat[i][j - 1])
		return dp[i][j] = 1 + findLongestFormACell(i, j - 1, mat, dp, n);
	if (i > 0 && (mat[i][j] + 1) == mat[i - 1][j])
		return dp[i][j] = 1 + findLongestFormACell(i - 1, j, mat, dp, n);
	if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j]))
		return dp[i][j] = 1 + findLongestFormACell(i + 1, j, mat, dp, n);
	return dp[i][j] = 1;
}
int findLongestOverAll(int **mat,int n)
{
	int result = 1;
	int **dp = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
		dp[i] = (int *)malloc(sizeof(int)*n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == -1)
				findLongestFormACell(i, j, mat, dp, n);
			result = max(result, dp[i][j]);
		}

	}
	return 0;
}