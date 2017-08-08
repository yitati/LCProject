/*
 * Laicode_ReverseBinaryTreeUpsidedown.cpp

Given a binary tree where all the right nodes are leaf nodes, flip it upside down and turn it into a
tree with left leaf nodes as the root.

Examples

        1

      /    \

    2        5

  /   \

3      4

is reversed to

        3

      /    \

    2        4

  /   \

1      5

 */

#include "LCProject/BST.h"

using namespace std;

// very similar with reverse linked list
TreeNode* reverseBinaryTree(TreeNode* root)
{
	// base case
	if(!root || !root->left) return root;
	TreeNode* newRoot = reverseBinaryTree(root->left);

	root->left->left = root;
	root->left->right = root->right;

	root->left = NULL;
	root->right = NULL;

	return newRoot;
}

