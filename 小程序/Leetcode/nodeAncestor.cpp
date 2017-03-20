#ifdef Ancestor
#include<iostream>
using namespace std;
struct node {
	int data;
	struct node * left;
	struct node * right;
};
struct node * newnode(int data)
{
	struct node * node = new struct node;
	node->left = node->right = NULL;
	node->data = data;
	return node;
}
bool printAncestors(struct node * root, int target)
{
	if (root == NULL)
		return false;
	if (root->data == target)
		return true;
	if (printAncestors(root->left, target) || printAncestors(root->right, target))
	{
		cout << root->data << " ";
		return true;
	}
	return false;
}
int main()
{

	/* Construct the following binary tree
	1
	/   \
	2      3
	/  \
	4     5
	/
	7
	*/
	struct node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->left->left->left = newnode(7);

	printAncestors(root, 7);

	getchar();
	return 0;
}
#endif // Ancestor
