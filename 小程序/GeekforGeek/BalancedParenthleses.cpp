#ifdef _Balanced__
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define bool int
struct sNode {
	char data;
	struct sNode *next;
};

/*
在链表的头部插入一个节点
*/
void push(struct sNode **top_ref, int new_data)
{
	struct sNode * new_node = (struct sNode *)malloc(sizeof(struct sNode));
	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

/*
从链表的头部摘除一个节点
*/
int pop(struct sNode **top_ref)
{
	char res;
	struct sNode *top;
	if (*top_ref == NULL)
	{
		cout << "Stack overflow " << endl;
		exit(0);
	}
	else
	{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

/*
判断括号是否匹配
*/
bool isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

bool areParentesisBalanced(char exp[])
{
	int i = 0;
	struct sNode *stack = NULL;
	while (exp[i])
	{
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]);
		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
		{
			if (stack == NULL)
				return 0;
			else if (!isMatchingPair(pop(&stack), exp[i]))
			{
				return 0;
			}
		}
		++i;
	}
	if (stack == NULL)
		return 1;
	else
		return 0;
}

int main()
{
	char exp[100] = "{()}[]";
	if (areParentesisBalanced(exp))
		printf("\n Balanced ");
	else
		printf("\n Not Balanced ");
	return 0;
}
#endif // _Balanced__