#include<iostream>
using namespace std;
/*
	 找到0-n-1中缺失的数字
*/
int MissingNumber(int a[], int n)
{
	int i, total=0,sum=0;
	total = (n+2)*(n + 1) / 2;
	for (i = 0; i < n; i++)
		sum = sum + a[i];
	return total - sum;
}
/*
	采用异或运算可以消解不存在的元素
*/
int getMissingNo(int a[], int n)
{
	int i;
	int x1 = a[0];
	int x2 = 1;
	for (i = 1; i < n; i++)
		x1 = x1 ^ a[i];
	for (i = 2; i <= n + 1; i++)
		x2 = x2 ^ i;
	return (x1 ^ x2);
}
int MissingNo()
{
	int a[] = { 1,2,4,5,6 };
	int miss = getMissingNo(a, 5);
	cout << miss << endl;
	return 0;
}