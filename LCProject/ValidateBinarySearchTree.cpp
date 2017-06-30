/******************************************************************************/
/*
* Question: #98 Validate Binary Search Tree
* Given a binary tree, determine if it is a valid binary search tree (BST).
* Assume a BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.

Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/
/*****************************************************************************/

#include "BST.h"

using namespace std;

// this solution does not have the limitations for INT_MIN and INT_MAX
bool isValidBST_helper(TreeNode * root, TreeNode * maxNode, TreeNode * minNode)
{
	if (!root) return true;
	if ((maxNode && root->val >= maxNode->val) || (minNode && root->val <= minNode->val)) return false;
	return isValidBST_helper(root->left, root, minNode) && isValidBST_helper(root->right, maxNode, root);
}

bool isValidBST(TreeNode* root)
{
	return isValidBST_helper(root, NULL, NULL);
}