/******************************************************************************/
/*
* Question: #337 House Robber III
* The thief has found himself a new place for his thievery again. 
* There is only one entrance to this area, called the "root." 
* Besides the root, each house has one and only one parent house. 
* After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
* It will automatically contact the police if two directly-linked houses were broken into on the same night.

* Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
/*****************************************************************************/

#include "BST.h"
#include <algorithm>
#include <unordered_map>

using namespace std;

int robIII_recursion(TreeNode * root, int & l, int & r)
{
	if (!root) return 0;

	int ll = 0, lr = 0, rl = 0, rr = 0;
	l = robIII_recursion(root->left, ll, lr);
	r = robIII_recursion(root->right, rl, rr);

	return max(root->val + ll + lr + rl + rr, l + r);
}

int robIII(TreeNode* root) 
{
	int l = 0, r = 0;
	return robIII_recursion(root, l, r);
}