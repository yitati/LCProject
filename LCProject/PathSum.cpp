/******************************************************************************
* Question: #112 Path Sum
* company tag: Facebook
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up 
* all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
TODO
*****************************************************************************/

#include "BST.h"

bool pathSumI_dfs(TreeNode * root, int sum, int target)
{
	if (root->left == NULL && root->right == NULL)
	{
		if (sum == target) return true;
		return false;
	}
	bool left = false, right = false;
	if (root->left) left = pathSumI_dfs(root->left, sum + root->left->val, target);
	if (left == true) return true;
	if (root->right) right = pathSumI_dfs(root->right, sum + root->right->val, target);
	if (right == true) return true;
	return false;
}

// this a dfs issue
bool hasPathSum(TreeNode* root, int sum) 
{
	if (root == NULL) return false;
	return pathSumI_dfs(root, root->val, sum);
}
