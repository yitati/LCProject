/******************************************************************************/
/*
* Question: #226 Invert Binary Tree
* Invert a binary tree.
*/
/*****************************************************************************/

#include "BST.h"

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL) return NULL;
	TreeNode * left = root->left;
	TreeNode * right = root->right;
	root->left = invertTree(right);
	root->right = invertTree(left);
	return root;
}