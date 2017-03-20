#ifdef _TreeHeigh__
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node * left;
	struct node * right;
};

int maxDepth(struct node * node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);
		if (lDepth > rDepth)
			return lDepth + 1;
		else
			return rDepth + 1;
	}
}

struct node * newNode(int data)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}

void deleteTree(struct node * node)
{
	if (node == NULL)
		return;
	deleteTree(node->left);
	deleteTree(node->right);
	cout << node->data << " ";
	free(node);
}

void mirror(struct node * node)
{
	if (node == NULL)
		return;
	else
	{
		struct node * temp;
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

void inOrder(struct node * node)
{
	if (node == NULL)
		return;
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

void printArray(int ints[], int len)
{
	for (int i = 0; i < len; i++)
		cout << ints[i] << " ";
	cout << endl;
}

void printPathrecur(struct node * node, int path[], int pathLen)
{
	if (node == NULL)
		return;
	path[pathLen] = node->data;
	pathLen++;
	if (node->left == NULL && node->right == NULL)
		printArray(path, pathLen);
	else
	{
		printPathrecur(node->left, path, pathLen);
		printPathrecur(node->right, path, pathLen);
	}
}

void printPaths(struct node * node)
{
	int path[100];
	printPathrecur(node, path, 0);
}

unsigned int getLeafCount(struct node * node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
	{
		return getLeafCount(node->left) + getLeafCount(node->right);
	}
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Leaf count of the tree is %d", getLeafCount(root));

	getchar();
	return 0;
}
#endif // _TreeHeigh__