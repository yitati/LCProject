/******************************************************************************/
/*
* Question: #103 Binary Tree Level Order Traversal
* Given a binary tree, return the zigzag level order traversal of its nodes' values. 
* (ie, from left to right, then right to left for the next level and alternate between).
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
	vector<vector<int>> results;
	if (root == NULL) return results;
	queue<TreeNode *> layer;
	layer.push(root);
	int k = 0;
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
		if (k % 2 == 1) reverse(result.begin(), result.end());
		k++;
		results.push_back(result);
	}
	return results;
}
