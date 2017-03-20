#include<iostream>
using namespace std;
int printCountRect(int dist)
{
	if (dist < 0)
		return 0;
	if (dist == 0)
		return 1;
	return printCountRect(dist - 1) + printCountRect(dist - 2) + printCountRect(dist - 3);
}
void printCountRectDemo()
{
	int dist = 4;
	cout << printCountRect(dist);
}