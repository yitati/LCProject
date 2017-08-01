/*
 * Laicode_InsertInBST.cpp
Insert a key in a binary search tree if the binary search tree does not already contain the key.
Return the root of the binary search tree.

Assumptions

There are no duplicate keys in the binary search tree

If the key is already existed in the binary search tree, you do not need to do anything

Examples

        5

      /    \

    3        8

  /   \

 1     4

insert 11, the tree becomes

        5

      /    \

    3        8

  /   \        \

 1     4       11

insert 6, the tree becomes

        5

      /    \

    3        8

  /   \     /  \

 1     4   6    11

*/

#include "BST.h"

using namespace std;

TreeNode* insertBST(TreeNode* root, int value)
{
	if(!root) return new TreeNode(value);
	if(root->val == value) return root;
	else if(value < root->val) {
		root->left = insertBST(root->left, value);
	}
	else root->right = insertBST(root->right, value);
	return root;
}




