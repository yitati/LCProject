/*
 * ReconstructBinaryTreeWithPreorderTraversal.cpp
 *
 *
company tag: Facebook
Given the preorder traversal sequence of a binary search tree, reconstruct the original tree.

Assumptions

The given sequence is not null
There are no duplicate keys in the binary search tree
Examples

preorder traversal = {5, 3, 1, 4, 8, 11}

The corresponding binary search tree is

        5

      /    \

    3        8

  /   \        \

1      4        11
 */

#include "../LCProject/BST.h"
#include <vector>
#include <climits>

using namespace std;

// this is also used in BST serialization and deserialization
TreeNode* deserializeTree(const vector<int>& preorder, int& pos, int upper)
{
	if(pos >= preorder.size()) return NULL;
	int data = preorder[pos];
	if(data >= upper) return NULL;
	TreeNode* newNode = new TreeNode(data);
	pos++;
	newNode->left = deserializeTree(preorder, pos, data);
	newNode->right = deserializeTree(preorder, pos, upper);

	return newNode;
}


TreeNode* reconstruct(vector<int> pre)
{
	int upper = INT_MAX;
	int pos = 0;
	return deserializeTree(pre, pos, INT_MAX);
}






