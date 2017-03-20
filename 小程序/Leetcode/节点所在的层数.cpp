#ifdef __LayersNode
#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *left;
	struct node * right;
};

int getLevelUtil(struct node * node, int data, int level)
{
	if (node == NULL)
		return 0;
	if (node->data == data)
		return level;
	int downlevel = getLevelUtil(node->left, data, level + 1);
	if (downlevel != 0)
		return downlevel;
	downlevel = getLevelUtil(node->right, data, level + 1);
	return downlevel;
}

int getLevel(struct node * node, int data)
{
	return getLevelUtil(node, data, 1);
}

struct node * newNode(int data)
{
	struct node * temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main()
{
	struct node *root = new struct node;
	int x;

	/* Constructing tree given in the above figure */
	root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(4);

	for (x = 1; x <= 5; x++)
	{
		int level = getLevel(root, x);
		if (level)
			printf(" Level of %d is %d\n", x, getLevel(root, x));
		else
			printf(" %d is not present in tree \n", x);

	}
	return 0;
}
#endif // __LayersNode