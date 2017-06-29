/******************************************************************************/
/*
* Question: #199 Binary Tree Right Side View
* Given a binary tree, imagine yourself standing on the right side of it, return the values 
* of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>
#include <queue>

using namespace std;
// one way is to push the last element of every layer
vector<int> rightSideView(TreeNode* root) 
{
	vector<int> result;
	if (root == NULL) return result;
	queue<TreeNode *> layer;
	layer.push(root);
	while (!layer.empty())
	{
		int layerLen = layer.size();
		for (int i = 0; i < layerLen; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();
			if (i == layerLen) result.push_back(curr->val);
			if (curr->left) layer.push(curr->left);
			if (curr->right) layer.push(curr->right);
		}
	}
	return result;
}