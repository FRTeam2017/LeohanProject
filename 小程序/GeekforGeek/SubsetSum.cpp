#include<iostream>
using namespace std;
bool isSubsetSum(int set[], int n, int sum)
{
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	//如果最后一个元素的值大于求的和，则将这个值忽略
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);
	return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
void SubsetSum()
{
	/*
		这仅仅是一个判定是不是的问题，不是一个是什么的问题
	*/
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 31;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
}