/******************************************************************************
* Question: #114 Flatten Binary Tree to Linked List
* company tag: Facebook
* Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*****************************************************************************/

#include "../Leetcode/BST.h"

using namespace std;

TreeNode * findRightMost(TreeNode * root)
{
	if (!root) return NULL;
	while (root->right)
	{
		root = root->right;
	}
	return root;
}

void flatten(TreeNode* root)
{
	if (!root) return;
	TreeNode * rightTree = root->right;
	TreeNode * leftRightMost = NULL;
	if (root->left)
	{
		flatten(root->left);
		leftRightMost = findRightMost(root->left);
		root->right = root->left;
		root->left = NULL;
	}
	if (rightTree) flatten(rightTree);
	if (leftRightMost)
	{
		leftRightMost->right = rightTree;
	}
}
