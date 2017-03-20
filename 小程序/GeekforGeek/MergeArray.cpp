#include<iostream>
#include<random>
using namespace std;
#define NA -1
void moveToEnd(int mPlusN[], int size)
{
	int i = 0;
	int j = size - 1;
	for (i = size - 1; i >= 0; i--)
	{
		if (mPlusN[i] != NA)
		{
			mPlusN[j] = mPlusN[i];
			j--;
		}
	}
}
int merge(int mPlus[], int N[], int m, int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k<(m+n))
	{

	}
	return 0;
}
void MergeArray()
{

}