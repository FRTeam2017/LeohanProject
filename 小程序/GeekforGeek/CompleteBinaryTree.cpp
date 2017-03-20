#ifdef _PETRO_TOUR
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
#include<queue>
using namespace std;
#define MAX_Q_SIZE 500

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

bool isCompleteBT(struct node * root)
{
	if (root == NULL)
		return true;
	int rear, front;
	queue<node> que;
	que.push(*root);
	bool flag = false;
	while (!que.empty())
	{
		node temp_node = que.front();
		que.pop();
		if (temp_node.left)
		{
			if (flag == true)
				return false;
			que.push(*temp_node.left);
		}
		else
			flag = true;
		if (temp_node.right)
		{
			if (flag == true)
				return false;
			que.push(*temp_node.right);
		}
		else
			flag = true;
	}
	return true;
}

struct node * newNode(int data)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);

	if (isCompleteBT(root) == true)
		printf("Complete Binary Tree");
	else
		printf("NOT Complete Binary Tree");

	return 0;
}
#endif // _PETRO_TOUR