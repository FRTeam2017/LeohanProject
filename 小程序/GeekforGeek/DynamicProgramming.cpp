/*
	动态规划问题
		使用的条件
			重叠的子问题
			最优的子结构
	解决方案
		将原来的问题分解为子问题，将子问题的解存放在表中
		如果没有重复计算的子问题，那么动态规划是没有用的
*/
#include<iostream>
using namespace std;
#define NIL -1
#define MAX 100
int lookup[MAX];

void _initialize()
{
	for (int i = 0; i < MAX;i++)
	{
		lookup[i] = NIL;
	}
}
int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

/*动态规划版的fib*/
int fibd(int n)
{
	if (lookup[n] == NIL)
	{
		if (n <= 1)
			lookup[n] = n;
		else
			lookup[n] = fib(n - 1) + fib(n - 2);
	}
	return lookup[n];
}

/*
	自底向上的斐波那契数列
*/
/* C program for Tabulated version */
#include<stdio.h>
int fibb(int n)
{
	int *f = (int *)malloc(sizeof(int)*(n + 1));
	int i;
	f[0] = 0;   f[1] = 1;
	for (i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];

	return f[n];
}
void fib()
{

	int n = 5;
	_initialize();
	cout << "斐波拉奇数 40 是" << fib(n) << endl;

}