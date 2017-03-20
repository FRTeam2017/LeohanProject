#ifdef __Traverse_
#include<iostream>
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
	node->right = NULL;
	node->left = NULL;
	return (node);
}

void printPosterorder(struct node *node)
{
	if (node == NULL)
		return;
	printPosterorder(node->left);
	printPosterorder(node->right);
	cout << node->data << " ";
}

void printInorder(struct node * node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

void printPreorder(struct node * node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	printPreorder(node->left);
	printPreorder(node->right);
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("\nPreorder traversal of binary tree is \n");
	printPreorder(root);

	printf("\nInorder traversal of binary tree is \n");
	printInorder(root);

	printf("\nPostorder traversal of binary tree is \n");
	printPosterorder(root);
}
#endif // __Traverse_
