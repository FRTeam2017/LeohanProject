#ifndef IsSubtree
#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *left;
	struct node * right;
};
bool areIdentical(struct node * root1, struct node * root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;
	return (root1->data == root2->data && (areIdentical(root1->left, root2->left)) && areIdentical(root1->right, root2->right));
}
bool isSubTree(struct node * T, struct node * S)
{
	if (S == NULL)
		return true;
	if (T == NULL)
		return false;
	if (areIdentical(T, S))
		return true;
	return isSubTree(T->left, S) || isSubTree(T->right, S);
}
struct node* newNode(int data)
{
	struct node* node =
		(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main()
{
	struct node *T = newNode(26);
	T->right = newNode(3);
	T->right->right = newNode(3);
	T->left = newNode(10);
	T->left->left = newNode(4);
	T->left->left->right = newNode(30);
	T->left->right = newNode(6);
	struct node *S = newNode(10);
	S->right = newNode(6);
	S->left = newNode(4);
	S->left->right = newNode(30);


	if (isSubTree(T, S))
		printf("Tree 2 is subtree of Tree 1");
	else
		printf("Tree 2 is not a subtree of Tree 1");

	getchar();
	return 0;
}
#endif // !IsSubtree

