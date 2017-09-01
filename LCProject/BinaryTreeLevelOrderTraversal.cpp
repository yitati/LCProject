/******************************************************************************
* Question: #102 Binary Tree Level Order Traversal
* company tag: LinkedIn, eBay
* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*****************************************************************************/

#include "BST.h"
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> results;
	if (root == NULL) return results;
	queue<TreeNode *> layer;
	layer.push(root);
	while (!layer.empty())
	{
		int layerLen = layer.size();
		vector<int> result;
		for (int i = 0; i < layerLen; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();
			result.push_back(curr->val);
			if (curr->left) layer.push(curr->left);
			if (curr->right) layer.push(curr->right);
		}
		results.push_back(result);
	}
	return results;
}
