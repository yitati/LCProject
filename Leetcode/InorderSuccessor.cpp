/******************************************************************************
* Question: #285 Inorder Successor in BST
* company tag: Facebook
* Given a binary search tree and a node in it, find the in-order successor of that node in the BST. 
* Note: If the given node has no in-order successor in the tree, return null. 
*****************************************************************************/

#include "../Leetcode/BST.h"

// time complexity to O(logN)

// find the inorder successor of a BST node
TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p)
{
	if (!root) return NULL;
	// do not forget about this ==
	if (root->val <= p->val) return inorderSuccessor(root->right, p);
	else
	{
		TreeNode * left = inorderSuccessor(root->left, p);
		return left ? left : root;
	}
}

// follow-up: find the inorder predecessor
TreeNode * inorderPredessor(TreeNode * root, TreeNode * p)
{
	if (!root) return NULL;
	if (root->val >= p->val) return inorderPredessor(root->left, p);
	else
	{
		TreeNode * right = inorderPredessor(root->right, p);
		return right ? right : root;
	}
}
