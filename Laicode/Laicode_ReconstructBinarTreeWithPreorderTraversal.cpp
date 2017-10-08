/*
 * Laicode_ReconstructBinarTreeWithPreorderTraversal.cpp
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

// TODO

#include "../LCProject/BST.h"
#include <vector>

using namespace std;

TreeNode * constructTree(TreeNode* upper, TreeNode* lower, vector<int>& pre, int pos)
{
	if(pos >= pre.size()) return NULL;
	TreeNode* node = new TreeNode(pre[pos]);
    return NULL;
}






