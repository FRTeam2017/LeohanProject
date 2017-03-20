#ifdef __TREE_HEIGHT_
#include<iostream>
#include<queue>
using namespace std;
struct node
{
	struct node *left;
	struct node *right;
	int data;
};

node * newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int treeHeight(node * root)
{
	if (root == NULL)
		return 0;
	queue<node *> q;
	q.push(root);
	int height = 0;

	while (true)
	{
		int nodeCount = q.size();
		if (nodeCount == 0)
			return height;
		height++;
		while (nodeCount > 0)
		{
			node *node = q.front();
			q.pop();
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			nodeCount--;
		}
	}
}
int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << "Height of tree is " << treeHeight(root);
	return 0;
}
#endif // __TREE_HEIGHT_