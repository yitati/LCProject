/*
 * Laicode_DeleteBST.cpp
Delete the target key K in the given binary search tree if the binary search tree contains K.
Return the root of the binary search tree.

Find your own way to delete the node from the binary search tree, after deletion the binary search
tree's property should be maintained.

Assumptions

There are no duplicate keys in the binary search tree
 */

#include "LCProject/BST.h"

static int getRightMostVal(TreeNode* root){
	while(root->right){
		root = root->right;
	}
	return root->val;
}


TreeNode* deleteBST(TreeNode* root, int value)
{
	if(!root) return NULL;
	if(value < root->val) root->left = deleteBST(root->left, value);
	else if(value > root->val) root->right = deleteBST(root->right, value);
	else{  // when roor is the node to be deleted
		if(!root->left && !root->right) { // 1. when root is the leaf node
			delete root;
			return NULL;
		}
		else if(!root->left || !root->right){ // 2.when root has only one child
			TreeNode* ret = root->left ? root->left : root->right;
			delete root;
			return ret;
		}
		else{ // 3. when root has both child, use the rightMost child of left tree to replace it
			int rm = getRightMostVal(root->left);
			root->val = rm;
			root->left = deleteBST(root->left, rm);
		}
	}
}


