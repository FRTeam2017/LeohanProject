/*
	问题描述
		找到一个序列中最常的递增子序列
	解决方法
		首先知道当前子序列中最大的元素的什么，如果下一个元素大于
		子序列中最大的元素，那么最大子序列中元素的个数+1
*/
#include<iostream>
#include<vector>
using namespace std;
/*
	D代表输入的序列
*/
void calc_LIS(vector<int> &D)
{
	vector<vector<int>> L(D.size());
	L[0].push_back(D[0]);//如果子序列中只有一个元素，那么这个元素就是子序列中最大的元素
	int i;
	for (i = 1; i < D.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((D[j] < D[i]) && ((L[i].size() < L[j].size() + 1)))//迭代出前面的最大的子序列
				L[i] = L[j];
		}
		L[i].push_back(D[i]);
	}
	for (vector<int> x : L)
	{
		for (vector<int>::iterator it = x.begin(); it != x.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}
void LIS()
{
	int a[] = {3,2,6,4,5,1};
	vector<int> arr(a, a + sizeof(a) / sizeof(a[0]));
	cout << "Data in" << endl;
	calc_LIS(arr);

}