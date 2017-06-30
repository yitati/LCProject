/******************************************************************************/
/*
* Question: #298 Binary Tree Longest Consecutive Sequence
* Given a binary tree, find the length of the longest consecutive sequence path.
* The path refers to any sequence of nodes from some starting node to any node in 
* the tree along the parent-child connections. The longest consecutive path need 
* to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/
/*****************************************************************************/
#include "BST.h"
#include <algorithm>

using namespace std;

void findLongestConsecutive(TreeNode * root, int & maxLen, int currLen)
{
	// base case
	if (!root) return;
	if (!root->left && !root->right) return;
	if (root->left)
	{
		if (root->left->val == root->val + 1)
		{
			maxLen = max(maxLen, currLen + 1);
			findLongestConsecutive(root->left, maxLen, currLen + 1);
		}
		else
		{
			findLongestConsecutive(root->left, maxLen, 1);
		}
	}
	if (root->right)
	{
		if (root->right->val == root->val + 1)
		{
			maxLen = max(maxLen, currLen + 1);
			findLongestConsecutive(root->right, maxLen, currLen + 1);
		}
		else
		{
			findLongestConsecutive(root->right, maxLen, 1);
		}
	}
}

int longestConsecutive(TreeNode* root)
{
	if (!root) return 0;
	int currLen = 1;
	int maxLen = 1;
	findLongestConsecutive(root, maxLen, currLen);
	return maxLen;
}