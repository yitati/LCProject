/******************************************************************************/
/*
* Question: #104 Maximum Depth Of Binary Tree
* Given a binary tree, find its maximum depth.
* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
/*****************************************************************************/

#include "BST.h"
#include <queue>

using namespace std;

int maxDepth(TreeNode * root) 
{
	if (root == NULL) return 0;
	int depth = 0;
	queue<TreeNode *> layer;
	layer.push(root);
	while (!layer.empty())
	{
		int len = layer.size();
		for (int i = 0; i < len; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();
			if (curr->left)layer.push(curr->left);
			if (curr->right) layer.push(curr->right);
		}
		depth++;
	}
	return depth;
}