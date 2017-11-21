/*
 * Laicode_MaximumPathSum.cpp
Given a binary tree in which each node contains an integer number. Find the maximum possible sum from one leaf node to another leaf node. If there is no such path available, return Integer.MIN_VALUE(Java)/INT_MIN (C++).

Examples

  -15

  /    \

2      11

     /    \

    6     14

The maximum path sum is 6 + 11 + 14 = 31.

How is the binary tree represented?

We use the level order traversal sequence with a special symbol "#" denoting the null node.

For Example:

The sequence [1, 2, 3, #, #, 4] represents the following binary tree:

    1

  /   \

 2     3

      /

    4

*/

#include <algorithm>
#include <climits>
#include "../Leetcode/BST.h"

using namespace std;

int maxPathDfs(TreeNode* root, int & maxSum){
	if(!root) return 0;
	int maxPath = 0;
	int leftSum = maxPathDfs(root->left, maxSum);
	int rightSum = maxPathDfs(root->right, maxSum);
	// it is possible that left or right = NULL
	if(root->left && root->right){
		maxSum = max(maxSum, leftSum + root->val + rightSum);
		maxPath = max(leftSum, rightSum) + root->val;
	}
	else{
		// do not update maxSum !!!
		maxPath = root->left ? leftSum + root->val : rightSum + root->val;
	}

	return maxPath;
}

int maxPathSumOfBinaryTree(TreeNode* root){
	int maxSum = INT_MIN;
	int maxPath = maxPathDfs(root, maxSum);
	return maxSum;
}






