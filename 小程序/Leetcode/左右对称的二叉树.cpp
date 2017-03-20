#ifdef __foldable__
#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *left;
	struct node * right;
};

struct node * newNode(int data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
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

bool isStructSame(struct node *a, struct node * b)
{
	if (a == NULL && b == NULL)
		return true;
	if (a != NULL&&b != NULL && isStructSame(a->left, b->left) && isStructSame(a->right, b->right))
		return true;
	return false;
}

bool isFoldable(struct node * root)
{
	bool res = false;
	if (root == NULL)
		return true;
	mirror(root->left);
	res = isStructSame(root->left, root->right);
	mirror(root->left);
	return res;
}

int main(void)
{
	/* The constructed binary tree is
	1
	/   \
	2     3
	\    /
	4  5
	*/
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->left->right = newNode(5);

	if (isFoldable(root) == 1)
	{
		printf("\n tree is foldable");
	}
	else
	{
		printf("\n tree is not foldable");
	}

	getchar();
	return 0;
}
#endif // __foldable__