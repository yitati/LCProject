/******************************************************************************/
/*
* Question: #314 Binary Tree Vertical Order Traversal
* Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
* If two nodes are in the same row and column, the order should be from left to right.
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<vector<int>> verticalOrder(TreeNode* root)
{
	if (!root) return{};
	map<int, vector<int>> table;
	// this has to be level order tranversal since the vector needs order
	queue<pair<TreeNode*, int>> level;
	level.push(pair<TreeNode*, int>(root, 0));
	while (!level.empty())
	{
		int levelSize = level.size();
		for (int i = 0; i<levelSize; i++)
		{
			TreeNode * node = level.front().first;
			int rootLevel = level.front().second;
			level.pop();
			if (table.count(rootLevel)) table[rootLevel].push_back(node->val);
			else
			{
				vector<int> item;
				item.push_back(node->val);
				table[rootLevel] = item;
			}
			if (node->left) level.push(pair<TreeNode *, int>(node->left, rootLevel - 1));
			if (node->right) level.push(pair<TreeNode *, int>(node->right, rootLevel + 1));
		}
	}

	vector<vector<int>> results;
	for (auto it = table.begin(); it != table.end(); it++)
	{
		results.push_back(it->second);
	}
	return results;
}