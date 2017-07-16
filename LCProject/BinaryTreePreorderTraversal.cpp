/******************************************************************************/
/*
* Question: #144 Binary Tree Preorder Traversal
* Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>
#include <stack>

using namespace std;

// solution 1 - using recursion
void preorderTraversal_recursion(TreeNode * root, vector<int> & preorder)
{
	if (!root) return;
	preorder.push_back(root->val);
	preorderTraversal_recursion(root->left, preorder);
	preorderTraversal_recursion(root->right, preorder);
}

vector<int> preorderTraversal1(TreeNode* root) 
{
	vector<int> preorder;
	preorderTraversal_recursion(root, preorder);
	return preorder;
}

// solution 2 - using stack, put right to the bottom and left to the top
vector<int> preorderTraversal2(TreeNode * root)
{
	vector<int> preorder;
	if (!root) return preorder;
	stack<TreeNode*> layer;
	layer.push(root);
	while (!layer.empty())
	{
		TreeNode * curr = layer.top();
		layer.pop();
		preorder.push_back(curr->val);
		if (curr->right) layer.push(curr->right);
		if (curr->left) layer.push(curr->left);
	}
	return preorder;
}

// solution 3 - morris traversal, O(1) space



