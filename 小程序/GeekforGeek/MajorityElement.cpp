#include<iostream>
using namespace std;
/*
	题目的描述是找到数组中出现次数超过一半的元素为主要元素
	返回这个被称之为主要元素的值
*/
/*
	题解
	这里只有两种元素，主元素和非主元素
	出现一个主元素，则主元素的count++
	出现一个非主元素，主元素的count--
*/
int findCandidate(int a[], int size)
{
	int maj_index = 0;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (a[maj_index] == a[i]) {
			count++;
		}
		else
		{
			count--;
		}
		if (count == 0)
		{
			maj_index = i;
			count = 1;
		}
	}
	return a[maj_index];
}

bool isMajority(int a[], int size, int cand)
{
	int i, count = 0;
	for (i = 0; i < size; i++)
		if (a[i] == cand)
			count++;
	if (count > size / 2)
		return 1;
	else
		return 0;
}

void printMajority(int a[], int size)
{
	/* Find the candidate for Majority*/
	int cand = findCandidate(a, size);

	/* Print the candidate if it is Majority*/
	if (isMajority(a, size, cand))
		printf(" %d ", cand);
	else
		printf("No Majority Element");
}

int MajorElem()
{
	int a[] = { 1, 3, 3, 1, 2 };
	int size = (sizeof(a)) / sizeof(a[0]);
	printMajority(a, size);
	getchar();
	return 0;
}