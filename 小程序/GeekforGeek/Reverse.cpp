#ifdef __REVERSE
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<stack>
using namespace std;
void reverse(char * str)
{
	int n = strlen(str);
	stack<char> stk;
	for (int i = 0; i < n; i++)
	{
		stk.push(str[i]);
	}
	for (int i = 0; i < n; i++)
	{
		str[i] = stk.top();
		stk.pop();
	}
}
int main()
{
	char str[] = "Geek Maze";
	reverse(str);
	cout << "Reversed string is " << str << endl;
	return 0;
}
#endif // __REVERSE