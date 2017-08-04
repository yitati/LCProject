/*
 * Laicode_SearchInBST.cpp
Find the target key K in the given binary search tree, return the node that contains the key if K is found,
otherwise return null.

Assumptions

There are no duplicate keys in the binary search tree

*/

#include "BST.h"

using namespace std;

TreeNode* searchBST(TreeNode* root, int value)
{
	if(!root) return NULL;
	if(root->val == value) return root;
	else if(value < root->val) return searchBST(root->left, value);
	else return searchBST(root->right, value);
}



