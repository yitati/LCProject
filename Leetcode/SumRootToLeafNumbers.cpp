/******************************************************************************/
/**
* Question: #129 Sum Root To Leaf Numbers
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
* Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
/*****************************************************************************/

#include "../Leetcode/BST.h"

using namespace std;

// dfs solution
void calculateTreeSum_dfs(TreeNode * root, int & globalSum, int currPathSum)
{
	currPathSum = currPathSum * 10 + root->val;
	// get to a leaf node
	if (!root->left && !root->right)
	{
		globalSum += currPathSum;
		return;
	}
	
	if (root->left)
	{
		calculateTreeSum_dfs(root->left, globalSum, currPathSum);
	}
	if (root->right)
	{
		calculateTreeSum_dfs(root->right, globalSum, currPathSum);
	}
}

int sumNumbers(TreeNode* root) 
{
	if (!root) return 0;
	int globalSum = 0;
	calculateTreeSum_dfs(root, globalSum, 0);
	return globalSum;
}