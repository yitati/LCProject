/******************************************************************************/
/**
* Question: #501 Find Mode In Binary Search Tree
* Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
For example:
Given BST [1,null,2,2],
1
\
2
/
2
return [2].

* Note: If a tree has more than one mode, you can return them in any order.
* Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred 
* due to recursion does not count).
/*****************************************************************************/

#include "BST.h"
#include <vector>
#include <queue>
#include <unordered_map>

vector<int> findMode(TreeNode* root) 
{
	if (root == NULL) return{};
	unordered_map<int, int> table;
	queue<TreeNode *> layer;
	vector<int> result;
	layer.push(root);
	while (!layer.empty())
	{
		TreeNode * curr = layer.front();
		layer.pop();
		table[curr->val]++;
		if (curr->left) layer.push(curr->left);
		if (curr->right) layer.push(curr->right);
	}
	int maxFreq = 0;
	for (auto it = table.begin(); it != table.end(); it++)
	{
		maxFreq = max(maxFreq, it->second);
	}
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if (it->second == maxFreq) result.push_back(it->first);
	}

	return result;
}