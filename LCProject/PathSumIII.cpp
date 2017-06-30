/******************************************************************************/
/**
* Question: #437 Path Sum III
* You are given a binary tree in which each node contains an integer value.
* Find the number of paths that sum to a given value.
* The path does not need to start or end at the root or a leaf, but it must go downwards 
* (traveling only from parent nodes to child nodes).
* The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
/*****************************************************************************/

#include "BST.h"
#include <unordered_map>

using namespace std;

void pathSumIII_dfs(TreeNode * root, int & count, int prefixSum, unordered_map<int, int> & table, int target)
{
	if (root == NULL) return;
	prefixSum += root->val;
	if (prefixSum == target) count++;
	count += table[prefixSum - target];
	table[prefixSum]++;
	pathSumIII_dfs(root->left, count, prefixSum, table, target);
	pathSumIII_dfs(root->right, count, prefixSum, table, target);
	table[prefixSum]--;
	prefixSum -= root->val;
}


int pathSumIII(TreeNode* root, int sum)
{
	int count = 0;
	if (root == NULL) return 0;
	unordered_map<int, int> table;
	pathSumIII_dfs(root, count, 0, table, sum);
	return count;
}
