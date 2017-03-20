#include<iostream>
using namespace std;
int main()
{
	int testCase;
	int arraySize;
	cin >> testCase;
	cin >> arraySize;
	int ** sample;
	sample = (int **)malloc(sizeof(int *)*testCase);
	for (int i = 0; i < testCase; i++)
	{
		sample[i] = (int *)malloc(sizeof(int)*arraySize);
	}
	for (int i = 0; i < testCase; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			cin >> sample[i][j];
		}
	}
	int m;
	for (int i = 0; i < testCase; i++)
	{
		cout << "Case " << i << ":" << endl;
		for (int j = 0; j < arraySize; j++)
		{
			m = sample[i][j] / 65536;
			cout << sample[i][j] - 65536 * m << " ";
		}
		cout << endl;
		for (int j = 0; j < arraySize; j++)
		{
			cout << sample[i][j] / 65536 << " ";
		}
		cout << endl;
	}
	return 0;
}