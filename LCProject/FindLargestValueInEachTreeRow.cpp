/******************************************************************************
* Question: #515 Find Largest Value In Each Tree Row
* company tag: LinkedIn
* type tag: #tree#BFS#
* You need to find the largest value in each row of a binary tree.
Example:
Input:

1
/ \
3   2
/ \   \
5   3   9

Output: [1, 3, 9]

*****************************************************************************/

#include "BST.h"
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> largestValues(TreeNode* root) 
{
	if (root == NULL) return{};
	vector<int> result;
	queue<TreeNode *> layer;
	layer.push(root);
	while (!layer.empty())
	{
		int layerMax = INT_MIN;
		int layerSize = layer.size();
		for (int i = 0; i < layerSize; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();
			layerMax = max(layerMax, curr->val);
			if (curr->left) layer.push(curr->left);
			if (curr->right) layer.push(curr->right);
		}
		result.push_back(layerMax);
	}

	return result;
}
