/******************************************************************************/
/**
* Question: #450 Delete Node in a BST
* Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
* Return the root node reference (possibly updated) of the BST.
* Basically, the deletion can be divided into two stages:
* Search for a node to remove.
* If the node is found, delete the node.
* Note: Time complexity should be O(height of tree).
/*****************************************************************************/

#include "BST.h"

int rightMostValue(TreeNode * root)
{
	while (root->right) root = root->right;
	return root->val;
}

TreeNode* deleteNode(TreeNode* root, int key) 
{
	if (root == NULL) return NULL;
	if (root->val < key) root->right = deleteNode(root->right, key);
	if (root->val > key) root->left = deleteNode(root->left, key);
	// when key == root->val
	if (root->left == NULL && root->right == NULL)
	{
		delete root;
		return NULL;
	}
	if (root->left == NULL)
	{
		TreeNode * right = root->right;
		delete root;
		return right;
	}
	if (root->right == NULL)
	{
		TreeNode * left = root->left;
		delete root;
		return left;
	}
	int rightMost = rightMostValue(root->left);
	root->val = rightMost;
	root->left = deleteNode(root->left, rightMost);
	return root;
}