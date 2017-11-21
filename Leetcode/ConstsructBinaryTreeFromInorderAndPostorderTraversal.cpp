/******************************************************************************/
/*
* Question: #106 Construct Binary Tree From Inorder Traversal and Postorder Tranversal
* Given inorder and postorder traversal of a tree, construct the binary tree.
*/
/*****************************************************************************/

#include <vector>
#include "../Leetcode/BST.h"

using namespace std;

TreeNode * buildTreePostIn(vector<int> & postorder, int pStart, int pEnd, vector<int> & inorder, int iStart, int iEnd)
{
	if (pStart > pEnd || iStart > iEnd) return NULL;
	int rootVal = postorder[pEnd];
	TreeNode * root = new TreeNode(rootVal);
	// calculate how many nodes in left tree
	int i = iStart;
	while (inorder[i] != rootVal) i++;
	// num of left nodes is (i-1)-(iStart)+1 = i-iStart
	root->left = buildTreePostIn(postorder, pStart, pStart + i - iStart - 1, inorder, iStart, i - 1);
	root->right = buildTreePostIn(postorder, pStart + i - iStart, pEnd - 1, inorder, i + 1, iEnd);
	return root;
}

TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder)
{
	return buildTreePostIn(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
}