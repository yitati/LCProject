/******************************************************************************/
/*
* Question: #105 Construct Binary Tree From Preorder and Inorder Traversal
* Given preorder and inorder traversal of a tree, construct the binary tree.
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>

using namespace std;

TreeNode * buildTreePreIn(vector<int> & preorder, int pStart, int pEnd, vector<int> & inorder, int iStart, int iEnd)
{
	if (pStart > pEnd || iStart > iEnd) return NULL;
	int rootVal = preorder[pStart];
	TreeNode * root = new TreeNode(rootVal);
	// calculate how many nodes in left tree
	int i = iStart;
	while (inorder[i] != rootVal) i++;
	// num of left nodes is (i-1)-(iStart)+1 = i-iStart
	root->left = buildTreePreIn(preorder, pStart + 1, pStart + i - iStart, inorder, iStart, i - 1);
	root->right = buildTreePreIn(preorder, pStart + i - iStart + 1, pEnd, inorder, i + 1, iEnd);
	return root;
}

TreeNode* buildTreeI(vector<int>& preorder, vector<int>& inorder)
{
	return buildTreePreIn(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}