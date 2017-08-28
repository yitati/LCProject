/*
 * Laicode_HeightofBinaryTree.cpp
 *

Find the height of binary tree.

Examples:

        5

      /    \

    3        8

  /   \        \

1      4        11

The height of above binary tree is 3.

 */

#include <algorithm>

using namespace std;

int findHeight(TreeNode* root)
{
	if(!root) return 0;
	int left = findHeight(root->left);
	int right = findHeight(root->right);
	return max(left, right)+1;
}




