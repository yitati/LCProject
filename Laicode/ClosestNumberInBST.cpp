/*
 * ClosestNumberInBST.cpp

In a binary search tree, find the node containing the closest number to the given target number.

Assumptions:

The given root is not null.
There are no duplicate keys in the binary search tree.
Examples:

    5

  /    \

2      11

     /    \

    6     14

closest number to 4 is 5

closest number to 10 is 11

closest number to 6 is 6

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
#include <climits>
#include <cstdlib>

using namespace std;

int closest(TreeNode* root, int target)
{
	TreeNode* curr = root;
	int diff = INT_MAX, close = 0;
	while(curr){
		if(curr->val == target) return target; // curr->val equals target
		if(abs(curr->val - target) < diff) {
			close = curr->val;
			diff = abs(curr->val - target);
		}
		if(target < curr->val) curr = curr->left; // target < curr->val
		else curr = curr->right; // target > curr->val
	}
	return close;

}



