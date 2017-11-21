/******************************************************************************/
/**
* Question: #404 Sum Of Left Leaves
* Find the sum of all left leaves in a given binary tree.
Example:
3
/ \
9  20
/  \
15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
/*****************************************************************************/

#include <queue>
#include "../Leetcode/BST.h"

using namespace std;

int sumOfLeftLeaves(TreeNode * root) 
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->val;
	int sum = 0;
	queue<TreeNode *> layer;
	layer.push(root);
	while (!layer.empty())
	{
		TreeNode * curr = layer.front();
		layer.pop();
		if (curr->left)
		{
			layer.push(curr->left);
			if (curr->left->left == NULL && curr->left->right == NULL) sum += curr->left->val;
		}
		if (curr->right) layer.push(curr->right);
	}
	return sum;

}