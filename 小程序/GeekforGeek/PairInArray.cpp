#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
/*
	问题描述
	给定一个数组A[]，找出数组中的两个元素,使他们相加的和为x
*/
int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int *)b);
}
int hasArrayTwoCandidates(int A[], int ar_size, int sum)
{
	qsort(A, ar_size, sizeof(int), compare);//快速排序
	int left = 0, right = ar_size - 1;
	while (left < right)
	{
		if (A[left] + A[right] < sum)
		{
			left++;
		}
		else if (A[left] + A[right] > sum)
		{
			right--;
		}
		else
		{
			return 1;//表示存在
		}
	}
	return 0;//表示不存在
}
void PairInArray()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand();
		cout << a[i] << " ";
	}
	cout << endl;
	if (hasArrayTwoCandidates(a, 10, a[3]+a[5]) == 1)
	{
		cout << "存在这样的数" << endl;
	}
	else
	{
		cout << "不存在这样的数" << endl;
	}
}