/******************************************************************************/
/*
* Question: #99 Recover Binary Search Tree
* Two elements of a binary search tree (BST) are swapped by mistake.
* Recover the tree without changing its structure.
* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>

using namespace std;

// every binary search has unique order (inorder)
void fillSuspect_recursion(TreeNode * curr, TreeNode * & prev, vector<pair<TreeNode*, TreeNode *>> & suspect)
{
	if (!curr) return;

	fillSuspect_recursion(curr->left, prev, suspect);
	if (prev && prev->val > curr->val)
	{
		suspect.push_back(pair<TreeNode*, TreeNode*>(prev, curr));
	}
	prev = curr;
	fillSuspect_recursion(curr->right, prev, suspect);
}

void recoverTree(TreeNode* root)
{
	vector<pair<TreeNode*, TreeNode *>> suspect;
	if (root == NULL) return;
	TreeNode* prev = NULL;
	fillSuspect_recursion(root, prev, suspect);
	if (suspect.size() == 2)
	{
		swap(suspect[0].first->val, suspect[1].second->val);
		return;
	}
	else
	{
		swap(suspect[0].first->val, suspect[0].second->val);
	}
}