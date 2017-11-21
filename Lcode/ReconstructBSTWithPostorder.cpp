/*
 * Laicode_ReconstructBSTWithPostorder.cpp

Given the postorder traversal sequence of a binary search tree, reconstruct the original tree.

Assumptions

The given sequence is not null
There are no duplicate keys in the binary search tree
Examples

postorder traversal = {1, 4, 3, 11, 8, 5}

the corresponding binary search tree is

        5

      /    \

    3        8

  /   \        \

1      4        11

 */

#include <vector>
#include <climits>
#include "../Leetcode/BST.h"

using namespace std;

/*
 * similar to preorder, with post order if we get the last element it should be the root node
 * and by ruling out all element large than this value we can get right tree and then left tree
 */

TreeNode* buildFromPost(const vector<int>& post, int& pos, int upper, int lower)
{
	if(pos < 0 || post[pos] >= upper || post[pos] <= lower) return NULL;
	TreeNode* node = new TreeNode(post[pos]);
	pos--;
	node->right = buildFromPost(post, pos, upper, node->val);
	node->left = buildFromPost(post, pos, node->val, lower);
	return node;
}

TreeNode* reconstructBSTWithPost(vector<int> post)
{
	int upper = INT_MAX, lower = INT_MIN;
	int pos = post.size()-1;
	return buildFromPost(post, pos, upper, lower);
}

/*
 * but in fact on the above solution, the upper bound is not needed
 */
TreeNode* buildFromPost_consice(const vector<int>& post, int & pos, int lower)
{
	if(pos < 0 || post[pos] <= lower) return NULL;
	TreeNode* node = new TreeNode(post[pos]);
	pos--;
	node->right = buildFromPost_consice(post, pos, node->val);
	node->left = buildFromPost_consice(post, pos, lower);
	return node;
}

