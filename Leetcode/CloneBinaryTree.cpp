/*
 * MianJing: Clone Binary Tree
 * company tag: Facebook
 * For a given binary tree, return a deep copy of it.
 */

// TODO - similar to clone graph

#include "../Leetcode/BST.h"

// Solution 1 - DFS solution
TreeNode* cloneTree(TreeNode* root)
{
	if(!root) return NULL;
	TreeNode* copyRoot = new TreeNode(root->val);
	copyRoot->left = cloneTree(root->left);
	copyRoot->right = cloneTree(root->right);
	return copyRoot;
}


