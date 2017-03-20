#ifdef __doubleTree
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node * left;
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

void doubleTree(struct node * node)
{
	struct node *oldLeft;
	if (node == NULL)
		return;
	doubleTree(node->left);
	doubleTree(node->right);
	oldLeft = node->left;
	node->left = newNode(node->data);
	node->left->left = oldLeft;
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Inorder traversal of the original tree is \n");
	printInorder(root);

	doubleTree(root);

	printf("\n Inorder traversal of the double tree is \n");
	printInorder(root);

	getchar();
	return 0;
}
#endif // __doubleTree