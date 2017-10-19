/******************************************************************************
i c * Question: #543 Diameter of Binary Tree
* company tag: Facebook
* Given a binary tree, you need to compute the length of the diameter of the tree. 
* The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
* This path may or may not pass through the root. 

Example:
Given a binary tree 

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3]. 

* Note: The length of path between two nodes is represented by the number of edges between them. 
*****************************************************************************/

#include <algorithm>
#include "BST.h"

using namespace std;

int maxTreeDepth(TreeNode * root, int & maxDepth)
{
	if (!root) return 0;
	int leftDepth = maxTreeDepth(root->left, maxDepth);
	int rightDepth = maxTreeDepth(root->right, maxDepth);
	maxDepth = max(leftDepth + rightDepth, maxDepth);
	return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
	if (!root || (!root->left && !root->right)) return 0;
	int maxDepth = 0;
	maxTreeDepth(root, maxDepth);
	return maxDepth;
}
