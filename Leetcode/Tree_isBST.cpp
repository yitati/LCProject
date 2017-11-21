#include <climits>
#include "../Leetcode/BST.h"

bool judgeBST(TreeNode * root, int upperBound, int lowerBound)
{
	if (root == NULL) return true;
	else if (root->val >= upperBound || root->val <= lowerBound) return false;
	return judgeBST(root->left, root->val, lowerBound) && judgeBST(root->right, upperBound, root->val);
}

bool isBinarySearchTree(TreeNode * root)
{
	return judgeBST(root, INT_MAX, INT_MIN);
}
