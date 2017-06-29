/******************************************************************************/
/*
* Question: #110 Balanced Binary Tree
* Given a binary tree, determine if it is height-balanced.
* For this problem, a height-balanced binary tree is defined as a binary tree in 
* which the depth of the two subtrees of every node never differ by more than 1.
*/
/*****************************************************************************/

#include "BST.h"
#include <algorithm>

using namespace std;

int treeDepth(TreeNode * root)
{
	if (root == NULL) return 0;
	if (!root->left && !root->right) return 1;
	return max(treeDepth(root->left), treeDepth(root->right)) + 1;
}

bool isBalanced(TreeNode* root) 
{
	if (root == NULL) return true;
	if (!isBalanced(root->left)) return false;
	if (!isBalanced(root->right)) return false;
	if (abs(treeDepth(root->left) - treeDepth(root->right)) > 1) return false;
	return true;
}