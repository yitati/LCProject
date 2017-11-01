/******************************************************************************
* Question: #124 Binary Tree Maximum Path Sum
* company tag: Facebook
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
*****************************************************************************/

#include "BST.h"
#include <climits>
#include <algorithm>

using namespace std;

// return the maximum sum on one path
int maxPath(TreeNode* root, int& globalMax)
{
	if(!root) return 0;
	int leftPath = maxPath(root->left, globalMax);
	int rightPath = maxPath(root->right, globalMax);
	int pathSum = max(max(leftPath, rightPath) + root->val, root->val);
	globalMax = max(globalMax, max(pathSum, leftPath + rightPath + root->val));
	return pathSum;
}

int maxPathSum(TreeNode* root)
{
	int globalMax = INT_MIN;
	int pathSum = maxPath(root, globalMax);
	return globalMax;
}
