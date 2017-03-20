#ifdef __Balance_Tree
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node * left;
	struct node * right;
};

int height(struct node * node)
{
	if (node == NULL)
		return 0;
	return 1 + max(height(node->left), height(node->right));
}

struct node * newNode(int data)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

bool isBalanced(struct node * root)
{
	int lh, rh;
	if (root == NULL)
		return 1;
	lh = height(root->left);
	rh = height(root->right);
	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;
	return 0;
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);

	if (isBalanced(root))
		printf("Tree is balanced");
	else
		printf("Tree is not balanced");

	getchar();
	return 0;
}
#endif // __Balance_Tree