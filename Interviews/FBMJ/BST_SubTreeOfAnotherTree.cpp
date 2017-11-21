/*
 * Tree_SubTreeOfAnotherTree.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: JoanneY1
 */

#include "../Leetcode/BST.h"

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



