#ifdef _UN_recursive
#include<iostream>
#include<stdlib.h>
using namespace std;
struct tNode
{
	int data;
	struct tNode *left;
	struct tNode *right;
};

struct tNode * newtNode(int data)
{
	struct tNode *tNode = (struct tNode*)malloc(sizeof(struct tNode));
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;
	return tNode;
}

void MorrisTraversal(struct tNode *root)
{
	struct tNode *current, *pre;
	if (root == NULL)
		return;
	current = root;
	while (current != NULL)
	{
		if (current->left == NULL)
		{
			cout << current->data;
			current = current->right;
		}
		else
		{
			pre = current->left;
			while (pre->right != NULL&&pre->right != current)
			{
				pre = pre->right;
			}
			if (pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				cout << current->data;
				current = current->right;
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

	MorrisTraversal(root);

	getchar();
	return 0;
}
#endif // _UN_recursive