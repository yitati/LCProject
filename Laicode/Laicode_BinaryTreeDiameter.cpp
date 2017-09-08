/*
 * Laicode_BinaryTreeDiameter.cpp
 *

Given a binary tree in which each node contains an integer number.
The diameter is defined as the longest distance from one leaf node
to another leaf node. The distance is the number of nodes on the path.

If there does not exist any such paths, return 0.

Examples

    5

  /    \

2      11

     /    \

    6     14

The diameter of this tree is 4 (2 → 5 → 11 → 14)

How is the binary tree represented?

We use the level order traversal sequence with a special symbol "#" denoting the null node.

For Example:

The sequence [1, 2, 3, #, #, 4] represents the following binary tree:

    1

  /   \

 2     3

      /

    4

 */

#include "../LCProject/BST.h"
#include <algorithm>

using namespace std;

int getMaxDiameter(TreeNode* root, int & maxDiameter)
{
	if(!root) return 0;
	int leftLen = getMaxDiameter(root->left, maxDiameter);
	int rightLen = getMaxDiameter(root->right, maxDiameter);

	if(root->left && root->right)
	{
		int curr = leftLen + rightLen + 1;
		maxDiameter = max(maxDiameter, curr);
	}

	return max(leftLen, rightLen) + 1;
}

int diameter(TreeNode* root)
{
	int maxDiameter = 0;
	int maxLen = getMaxDiameter(root, maxDiameter);
	return maxDiameter;
}


