/*
	这里求解最优的搜索结果
		在根据节点出现的频率构建一个二叉树的过程中，求出构建的二叉树的最小代价
*/
#include<iostream>
using namespace std;
int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	{
		s += freq[k];
	}
	return s;
}
int optCost(int freq[], int i, int j)
{
	if (j < i)
		return 0;
	if (j == i)
		return freq[i];

	int fsum = sum(freq, i, j);

	int min = INT_MAX;

	for (int r = i; r <= j; r++)
	{
		int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
		if (cost < min)
			min = cost;
	}
	return min + fsum;
}
int optimalSearch(int key[], int freqp[], int n)
{
	return optCost(freqp, 0, n - 1);
}