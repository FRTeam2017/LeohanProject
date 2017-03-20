/*
#include<Bits.h>
#include<map>
#include<iostream>
using namespace std;
bool canPairs(int arr[], int n, int k)
{
if (n & 1)
return false;
map<int, int> freq;
for (int i = 0; i < n; i++)
freq[arr[i] % k]++;
for (int i = 0; i < n; i++)
{
int rem = arr[i] % k;
if (2 * rem == k)
{
if (freq[rem] % 2 != 0)
return false;
}
else if (rem == 0)
{
if (freq[rem] & 1)
return false;
}
else if (freq[rem] != freq[k - rem])
return false;
}
return true;
}
int main()
{
	int arr[] = { 92, 75, 65, 48, 45, 35 };
	int k = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	canPairs(arr, n, k) ? cout << "True" : cout << "False";
	return 0;
}
*/