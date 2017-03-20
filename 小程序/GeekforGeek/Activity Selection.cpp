/*
	贪心算法
		算法的本质是每一步都选择当前的最优解。
		因为局部的最优解就是全局的最优解
	在处理NP问题的时候，贪心算法会得到最优解的近似解
*/
#include<iostream>
using namespace std;
/*
	问题描述
		给定了六项活动的起始时间和最后的终结时间，从中选择出最多的活动数目，
		前提条件是他们在时间上不会产生冲突
*/
void printMaxActivities(int s[], int f[], int n)
{
	int i, j;
	cout << "Following activiteis are selected" << endl;
	i = 0;
	cout << i << " ";
	for (j = 1; j < n; j++)
	{
		if (s[j] >= f[i])
		{
			cout << j << " ";
			i = j;
		}
	}
	cout << endl;
}
void ActivitySelectionDemo()
{
	int s[] = {1,3,0,5,8,5};
	int f[] = {2,4,6,7,9,9};
	int n = sizeof(s) / sizeof(int);
	printMaxActivities(s, f, n);
	return;
}