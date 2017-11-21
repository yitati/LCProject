/*
 * Laicode_RecoverBinarySearchTree.cpp
 *

Given a Binary Search Tree with only two nodes swapped. Try to find them and recover the binary search tree.

Input:

               4

              / \

             2   6

            / \   / \

           1  5 3  7

Output:       4

                  / \

                2   6

               /  \   / \

            1  3   5  7

 */

#include <vector>
#include "../Leetcode/BST.h"

using namespace std;

/*
 * For binary search tree, every nodes should be larger than its left tree and smaller
 * than its right tree.
 * !!!! BST prev !!!!! use reference instead of value pass
 */

void findSuspect(vector<pair<TreeNode*, TreeNode*>>& suspect, TreeNode*& prev, TreeNode* node)
{
	if(!node) return;
	findSuspect(suspect, prev, node->left);
	if(prev && prev->val > node->val)
	{
		suspect.emplace_back(prev, node);
	}
	// for prev reference we always need to update it
	prev = node;
	findSuspect(suspect, prev, node->right);

}

TreeNode* recover(TreeNode* root)
{
	if(!root) return NULL;
	vector<pair<TreeNode*, TreeNode*>> suspect;
	// push nodes with in-order
	TreeNode* prev = NULL;
	findSuspect(suspect, prev, root);
	if(suspect.size() == 2)
	{
		swap(suspect[0].first->val, suspect[1].second->val);
	}
	else
	{
		swap(suspect[0].first->val, suspect[0].second->val);
	}
	return root;
}
