#ifdef __使用栈做中序遍历
#include<stdlib.h>
#include<iostream>
using namespace std;
#define bool int
struct tNode
{
	int data;
	struct tNode *left;
	struct tNode *right;
};

struct sNode
{
	struct tNode *t;
	struct sNode *next;
};

void push(struct sNode **top_ref, struct tNode *t)
{
	struct sNode *new_tNode = (struct sNode *)malloc(sizeof(struct sNode));
	if (new_tNode == NULL)
	{
		cout << "Stack Overflow" << endl;
	}
	new_tNode->t = t;
	new_tNode->next = (*top_ref);
	(*top_ref) = new_tNode;
}

bool isEmpty(struct sNode *top)
{
	return (top == NULL) ? 1 : 0;
}

struct tNode *pop(struct sNode **top_ref) {
	struct tNode *res;
	struct sNode *top;
	if (isEmpty(*top_ref))
	{
		cout << "Stack underflow" << endl;
	}
	else
	{
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

struct tNode *newtNode(int data)
{
	struct tNode * tNode = (struct tNode*)malloc(sizeof(struct tNode));
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;
	return tNode;
}

void inOrder(struct tNode *root)
{
	struct tNode *current = root;
	struct sNode *s = NULL;
	bool done = 0;
	while (!done)
	{
		if (current != NULL)
		{
			push(&s, current);
			current = current->left;
		}
		else
		{
			if (!isEmpty(s))
			{
				current = pop(&s);
				cout << current->data << " ";
				current = current->right;
			}
			else
			{
				done = 1;
			}
		}
	}
}

int main()
{
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	inOrder(root);

	getchar();
	return 0;
}
#endif // __使用栈做中序遍历