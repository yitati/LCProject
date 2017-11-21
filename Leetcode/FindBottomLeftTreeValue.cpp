/******************************************************************************/
/**
* Question: #515 Find Largest Value In Each Tree Row
* Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

2
/ \
1   3

Output:
1
Example 2:
Input:

1
/ \
2   3
/   / \
4   5   6
/
7

Output:
7
*/
/*****************************************************************************/

#include <queue>
#include <algorithm>
#include "../Leetcode/BST.h"

using namespace std;

int findBottomLeftValue(TreeNode* root) 
{
	if (root == NULL) return{};
	vector<int> result;
	queue<TreeNode *> layer;
	layer.push(root);
	int layerLeft = 0;
	while (!layer.empty())
	{
		int layerSize = layer.size();
		for (int i = 0; i < layerSize; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();
			if(i == 0)layerLeft = curr->val;
			if (curr->left) layer.push(curr->left);
			if (curr->right) layer.push(curr->right);
		}
	}
	return layerLeft;
}