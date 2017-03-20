#include<iostream>
#include<algorithm>
using namespace std;
int n, c;
int func(int num, int array[]);
int bs(int array[]);
int main()
{
	int t;//test case
	cin >> t;
	while (t--)
	{
		cin >> n;//n stall to locate cow
		cin >> c;//num of cows
		int * array = new int[n];
		for (int i = 0; i < n; i++)
			cin >> array[i];
		sort(array, array + n);//sort the position of stall
		int k = bs(array);
		cout << k << endl;
	}
	return 0;
}

//num is min distance
//array is the position of cow
int func(int num, int array[])
{
	int cows = 1, pos = array[0];//there must be one cow at the position[0]
	for (int i = 1; i < n; i++)
	{
		if (array[i] - pos >= num)
		{
			pos = array[i];
			cows++;
			if (cows == c)
				return 1;
		}
	}
	return 0;
}
int bs(int array[])
{
	int ini = 0, last = array[n - 1], max = -1;
	while (last>ini)
	{
		int mid = (ini + last) / 2;
		if (func(mid, array) == 1)
		{
			if (mid > max)
				max = mid;
			ini = mid + 1;
		}
		else
			last = mid;
	}
	return max;
}