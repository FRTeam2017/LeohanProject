/*
#include<iostream>
#include<map>
using namespace std;
bool findPairs(int arr[], int n)
{
map<int, pair<int, int>> Hash;
for (int i = 0; i < n; i++)
{
for (int j = i + 1; j < n; j++)
{
int sum = arr[i] + arr[j];
if (Hash.find(sum) == Hash.end())
Hash[sum] = make_pair(i, j);
else
{
pair<int, int> pp = Hash[sum];
cout << "(" << arr[pp.first] << "," << arr[pp.second] << ") and (" << arr[i] << ", " << arr[j] << ")" << endl;
}
}
}
cout << "No Pairs found";
return false;
}

void main()
{
int array[] = { 1,2,3,4,5 };
findPairs(array, 5);
}
*/