#ifdef ConvertTree
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node * right;
};

struct node * newNode(int data)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printInorder(struct node * node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

void increment(struct node *node, int diff)
{
	if (node->left != NULL)
	{
		node->left->data = node->left->data + diff;
		increment(node->left, diff);
	}
	else if (node->right != NULL)
	{
		node->right->data = node->right->data + diff;
		increment(node->right, diff);
	}
}

void convertTree(struct node * node)
{
	int left_data = 0, right_data = 0, diff;
	if (node == NULL || (node->left == NULL && node->right == NULL))
		return;
	else
	{
		convertTree(node->left);
		convertTree(node->right);
		if (node->left != NULL)
			left_data = node->left->data;
		if (node->right != NULL)
			right_data = node->right->data;
		diff = left_data + right_data - node->data;
		if (diff > 0)
			node->data = node->data + diff;
		if (diff < 0)
			increment(node, -diff);
	}
}

int main()
{
	struct node *root = newNode(50);
	root->left = newNode(7);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(1);
	root->right->right = newNode(30);

	printf("\n Inorder traversal before conversion ");
	printInorder(root);

	convertTree(root);

	printf("\n Inorder traversal after conversion ");
	printInorder(root);

	getchar();
	return 0;
}
#endif // ConvertTree