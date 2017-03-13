/******************************************************************************/
/*
* Question: #124 Binary Tree Maximum Path Sum
* Given a binary tree, find the maximum path sum.
* For this problem, a path is defined as any sequence of nodes from some starting node to
* any node in the tree along the parent-child connections. The path must contain at least 
* one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/
/*****************************************************************************/

#include "BST.h"
#include <algorithm>

using namespace std;

int maxSinglePathSum(TreeNode * root, int & globalSum)
{
	if (root == NULL) return 0;
	int singleMaxSum = INT_MIN;
	int leftMaxSum = maxSinglePathSum(root->left, globalSum);
	int rightMaxSum = maxSinglePathSum(root->right, globalSum);
	singleMaxSum = max(max(leftMaxSum, rightMaxSum) + root->val, root->val);
	globalSum = max(globalSum, max(singleMaxSum, leftMaxSum + rightMaxSum + root->val));
	return singleMaxSum;
}

int maxPathSum(TreeNode* root)
{
	int globalPathSum = INT_MIN;
	int sigle = maxSinglePathSum(root, globalPathSum);
	return globalPathSum;
}