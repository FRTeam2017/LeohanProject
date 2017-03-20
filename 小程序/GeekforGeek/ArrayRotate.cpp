#include<iostream>
using namespace std;
void leftRotateOne(int arr[], int n)
{
	int i, temp;
	temp = arr[0];
	for (i = 0; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[i] = temp;
}
void leftRotate(int arr[], int d, int n)
{
	int i;
	for (i = 0; i < d; i++)
	{
		leftRotateOne(arr, n);
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
void LeftRotate()
{
	int arr[] = {1,2,3,4,5,6,7};
	leftRotate(arr, 2, 7);
	printArray(arr, 7);
	cout << endl;
}