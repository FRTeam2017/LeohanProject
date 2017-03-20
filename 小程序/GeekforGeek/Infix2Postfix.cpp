#ifdef infixToPostfix
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stack>
using namespace std;
//�ж��Ƿ�Ϊ��ĸ
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
//�жϲ����������ȼ�
int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}
//��׺���ʽת��׺���ʽ
int infixToPostfix(char * exp)
{
	int i, k;
	stack<char> stk;
	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];//���ʽ���ɵ�������ĸ��ɵ�
		else if (exp[i] == '(')
		{
			stk.push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			while (!stk.empty() && stk.top() != '(')
			{
				exp[++k] = stk.top();
				stk.pop();
			}
			if (!stk.empty() && stk.top() != '(')
			{
				return -1;
			}
			else
			{
				stk.pop();
			}
		}
		else
		{
			while (!stk.empty() && Prec(exp[i]) <= Prec(stk.top()))
			{
				exp[++k] = stk.top();
				stk.pop();
			}
			stk.push(exp[i]);
		}
	}
	while (!stk.empty())
	{
		exp[++k] = stk.top();
		stk.pop();
	}
	exp[++k] = '\0';
	cout << exp << endl;
}
int main()
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}
#endif // infixToPostfix
