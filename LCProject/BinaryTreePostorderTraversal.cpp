/******************************************************************************/
/*
* Question: #145 Binary Tree Postorder Traversal
* Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


// solution 1 - using recursion
void postorderTraversal_recursion(TreeNode * root, vector<int> & postorder)
{
	if (root == NULL) return;
	postorderTraversal_recursion(root->left, postorder);
	postorderTraversal_recursion(root->right, postorder);
	postorder.push_back(root->val);
}

vector<int> postorderTraversal1(TreeNode* root) 
{
	vector<int> postorder;
	postorderTraversal_recursion(root, postorder);
	return postorder;
}

// solution 2 - use stack, push node, then right, then left
vector<int> postorderTraversal2(TreeNode * root)
{
	vector<int> postorder;
	if (!root) return postorder;
	stack<TreeNode*> layer;
	layer.push(root);
	while (!layer.empty())
	{
		TreeNode * curr = layer.top();
		layer.pop();
		postorder.push_back(curr->val);
		if (curr->left) layer.push(curr->left);
		if (curr->right) layer.push(curr->right);
	}
	reverse(postorder.begin(), postorder.end());
	return postorder;
}
