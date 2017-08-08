/*
 * Laicode_MaximumPathSumBinaryTreeII.cpp

Given a binary tree in which each node contains an integer number. Find the maximum possible sum from any node to any node
(the start node and the end node can be the same).

Assumptions

​The root of the given binary tree is not null
Examples

   -1

  /    \

2      11

     /    \

    6    -14

one example of paths could be -14 -> 11 -> -1 -> 2

another example could be the node 11 itself

The maximum path sum in the above binary tree is 6 + 11 + (-1) + 2 = 18

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

#include "LCProject/BST.h"
#include <climits>

using namespace std;
/*
 * the largest path sum could be the node itself, or one branch, or both branch
 * but the sum that passed to parent should be the maximum sum when adding this number with one of its branches or it self
 * 1. maxSum to pass to parent = max(node->val, node->value + max(left branch, right branch))
 * 2. maxPathSum to save as the global = max(maxPathSum, maxSum, node->val + left branch + right branch)
 */

int maxPathBetweenAnyNodes(TreeNode* root, int& maxSum){
	if(!root) return 0;
	int leftMax = maxPathBetweenAnyNodes(root->left, maxSum);
	int rightMax = maxPathBetweenAnyNodes(root->right, maxSum);
	int toRet = max(root->val, max(root->val + leftMax, root->val + rightMax));
	maxSum = max(maxSum, max(toRet, root->val + leftMax + rightMax));
	return toRet;
}

int maxPathSumII(TreeNode* root){
	int maxSum = INT_MIN;
	int path = maxPathBetweenAnyNodes(root, maxSum);
	return maxSum;
}


