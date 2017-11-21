/*
 * EBMJ_FindNextInBinarySearchTree.cpp
 *

given a num, find the immediate larger element in a BST. num may be not in the BST

 */

#include "../Leetcode/BST.h"

TreeNode* findNextInBst(TreeNode* root, int target)
{
	if(!root) return NULL;
	if(root->val <= target) return findNextInBst(root->right, target);
	TreeNode* leftRet = findNextInBst(root->left, target);
	if(!leftRet) return root;
	else return leftRet;
}




