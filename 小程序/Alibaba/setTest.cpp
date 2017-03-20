#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#ifdef _Test
int main()
{
	vector<int> myVector;
	myVector.push_back(1);
	std::vector<int>::iterator position = std::find(myVector.begin(), myVector.end(), 8);
	if (position != myVector.end()) // == myVector.end() means the element was not found
		myVector.erase(position);
}
#endif