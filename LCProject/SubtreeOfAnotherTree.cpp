/******************************************************************************
* Question: #572 Subtree Of Another Tree
* company tag: eBay
* Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and 
* node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this 
* node's descendants. The tree s could also be considered as a subtree of itself. 

Example 1:
Given tree s:
3
/ \
4   5
/ \
1   2

Given tree t:    4
/ \
1   2

Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:
3
/ \
4   5
/ \
1   2
/
0

Given tree t:    4
/ \
1   2

Return false.
*****************************************************************************/

#include "BST.h"

using namespace std;

// helper funtion that checks if two trees are identical
bool isTwoSameTree(TreeNode * lhs, TreeNode * rhs)
{
	if (!lhs && !rhs) return true;
	else if (!lhs || !rhs) return false;

	if (lhs->val != rhs->val) return false;
	bool left = isTwoSameTree(lhs->left, rhs->left);
	bool right = isTwoSameTree(lhs->right, rhs->right);
	return left && right;
}

// function that checks if t is subtree of s
bool isSubtree(TreeNode* s, TreeNode* t)
{
	if (!s) return false;
	if (isTwoSameTree(s, t)) return true;
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}
