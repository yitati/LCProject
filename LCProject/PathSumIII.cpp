/******************************************************************************
* Question: #437 Path Sum III
* company tag: Amazon
* You are given a binary tree in which each node contains an integer value.
* Find the number of paths that sum to a given value.
* The path does not need to start or end at the root or a leaf, but it must go downwards 
* (traveling only from parent nodes to child nodes).
* The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
*****************************************************************************/

#include "BST.h"
#include <unordered_map>

using namespace std;

/*
 * DFS solution, at each node, we can count this node in or not
 * the space complexity is O(n) (each node will have a sum)
 * the time complexity is O(n^2) if no branching and O(nlgn) with balanced tree
 */
int pathSumFrom(TreeNode* node, int sum)
{
	if(!node) return 0;
	return (node->val == sum ? 1 : 0) + pathSumFrom(node->left, sum - node->val) + pathSumFrom(node->right, sum - node->val);
}

int pathSumIII_DFS(TreeNode* root, int sum)
{
	if(!root) return 0;
	return pathSumFrom(root, sum) + pathSumIII_DFS(root->left, sum) + pathSumIII_DFS(root->right, sum);
}

/*
 * Prefix sum solution, every node is visited only once. So time complexity is O(n)
 */
void pathSumIII_prefix(TreeNode * root, int & count, int prefixSum, unordered_map<int, int> & table, int target)
{
    if (root == NULL) return;
    prefixSum += root->val;
    count += table[prefixSum - target];
    table[prefixSum]++;
    pathSumIII_prefix(root->left, count, prefixSum, table, target);
    pathSumIII_prefix(root->right, count, prefixSum, table, target);
    // this is clean-up for other pathes
    table[prefixSum]--;
    prefixSum -= root->val;
}


int pathSumIII(TreeNode* root, int sum)
{
    int count = 0;
    if (root == NULL) return 0;
    unordered_map<int, int> table;
    table[0] = 1;
    pathSumIII_prefix(root, count, 0, table, sum);
    return count;
}
