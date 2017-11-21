/*
Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
Print all the keys of tree in range k1 and k2. i.e. print all x such that k1 <= x <= k2 
and x is a key of given BST. Print all the keys in an increasing order.
*/

#include "../Leetcode/BST.h"

void printBstWithRange(TreeNode * root, int k1, int k2)
{
	if (root == NULL) return;
	if (root->val > k1)
	{
		printBstWithRange(root->left, k1, k2);
	}
	cout << root->val << "   ";

	if (root->val < k2)
	{
		printBstWithRange(root->right, k1, k2);
	}
}