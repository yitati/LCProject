/******************************************************************************/
/*
* Question: #94 Binary Tree Inorder Traversal
* Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>
#include <stack>

using namespace std;


// solution 1 - recursive solution
void inorderTraversal_recursion(TreeNode * root, vector<int> & inorder)
{
	if (root == NULL) return;
	inorderTraversal_recursion(root->left, inorder);
	inorder.push_back(root->val);
	inorderTraversal_recursion(root->right, inorder);
}

vector<int> inorderTraversal1(TreeNode* root) 
{
	vector<int> inorder;
	inorderTraversal_recursion(root, inorder);
	return inorder;
}

// solution 2 -  using stack
vector<int> inorderTraversal2(TreeNode* root)
{
	vector<int> inorder;
	stack<TreeNode *> path;
	TreeNode * curr = root;

	while (curr || !path.empty())
	{
		if (curr)
		{
			path.push(curr);
			curr = curr->left;
		}
		else
		{
			curr = path.top();
			path.pop();
			inorder.push_back(curr->val);
			curr = curr->right;
		}
	}
	return inorder;
}