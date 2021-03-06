/******************************************************************************************
 * Question #156 Binary Tree Upside Down
 * company tag: LinkedIn
 * Given a binary tree where all the right nodes are either leaf nodes with a sibling
 * (a left node that shares the same parent node) or empty, flip it upside down and turn
 * it into a tree where the original right nodes turned into left leaf nodes.
 * Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5



return the root of the binary tree [4,5,2,#,#,3,1].

   4
  / \
 5   2
    / \
   3   1

******************************************************************************************/

#include "../Leetcode/BST.h"

// This is very similar to reverse linked list
TreeNode* upsideDownBinaryTree(TreeNode* root)
{
	if(!root || !root->left) return root;

	TreeNode* newroot = upsideDownBinaryTree(root->left);

	root->left->left = root->right;
	root->left->right = root;
	// break the link
	root->left = NULL;
	root->right = NULL;

	return newroot;
}


