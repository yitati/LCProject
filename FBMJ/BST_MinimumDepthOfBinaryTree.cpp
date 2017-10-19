/******************************************************************************
* Question: #111 Minimum Depth Of Binary Tree
* company tag: Facebook
* Given a binary tree, find its minimum depth.
* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*****************************************************************************/

#include "BST.h"
#include <queue>

using namespace std;

// since we need to get the min depth, simply use BFS
int minDepth(TreeNode* root) 
{
	if (root == NULL) return 0;
	int depth = 1;
	queue<TreeNode *> layer;
	layer.push(root);
	while (!layer.empty())
	{
		int len = layer.size();
		for (int i = 0; i < len; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();
			if (!curr->left && !curr->right) return depth;
			if (curr->left)layer.push(curr->left);
			if (curr->right) layer.push(curr->right);
		}
		depth++;
	}
	return depth;
}

// recursion
int minDepth_recursion(TreeNode* root)
{
	if(!root) return 0;
	int leftDepth = minDepth_recursion(root->left);
	int rightDepth = minDepth_recursion(root->right);
	// this is a pitfalll
	return (leftDepth ==0 || rightDepth == 0) ? leftDepth + rightDepth + 1 : min(leftDepth, rightDepth) + 1;
}
