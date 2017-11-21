/******************************************************************************/
/**
* Question: #113 Path Sum III
* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return
[
[5,4,11,2],
[5,8,4,5]
]
/*****************************************************************************/

#include <vector>
#include "../Leetcode/BST.h"

using namespace std;

// use same dfs trick but this time pass a difference with target instead of the current sum

void pathSumII_dfs(TreeNode * root, vector<vector<int>> & results, vector<int> & result, int target)
{
	if (root->left == NULL && root->right == NULL)
	{
		if (target == 0)
		{
			results.push_back(result);
			return;
		}
	}

	if (root->left)
	{
		result.push_back(root->left->val);
		pathSumII_dfs(root->left, results, result, target - root->left->val);
		result.pop_back();
	}
	if (root->right)
	{
		result.push_back(root->right->val);
		pathSumII_dfs(root->right, results, result, target - root->right->val);
		result.pop_back();
	}
}

vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	if (root == NULL) return{};
	vector<vector<int>> results;
	vector<int> result;
	result.push_back(root->val);
	pathSumII_dfs(root, results, result, sum - root->val);
	return results;
}