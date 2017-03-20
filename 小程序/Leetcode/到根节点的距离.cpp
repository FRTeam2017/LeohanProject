#ifdef _KDistance
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newNode(int data)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->right = node->left = NULL;
	return node;
}

void printKDistance(node * root, int k)
{
	if (root == NULL)
		return;
	if (k == 0)
	{
		cout << root->data << " ";
	}
	else
	{
		printKDistance(root->left, k - 1);
		printKDistance(root->right, k - 1);
	}
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(8);

	printKDistance(root, 2);

	getchar();
	return 0;
}
#endif // _KDistance