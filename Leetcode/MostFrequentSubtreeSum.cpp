/******************************************************************************/
/**
* Question: #508 Most Frequent Subtree Sum
* Given the root of a tree, you are asked to find the most frequent subtree sum. 
* The subtree sum of a node is defined as the sum of all the node values formed by 
* the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? 
* If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

5
/  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

5
/  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.

* Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
*/
/*****************************************************************************/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../Leetcode/BST.h"

using namespace std;

int calculateSum_recursive(TreeNode * root, unordered_map<int, int> & table)
{
	int sum = 0;
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) sum = root->val;
	else sum = calculateSum_recursive(root->left, table) + calculateSum_recursive(root->right, table) + root->val;
	table[sum]++;
	return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) 
{
	if (root == NULL) return{};
	// create a table to store all the sum and frequency
	vector<int> result;
	unordered_map<int, int> table;
	calculateSum_recursive(root, table);
	int maxFrequency = 0;
	for (auto it = table.begin(); it != table.end(); it++)
	{
		maxFrequency = max(maxFrequency, it->second);
	}

	for (auto it = table.begin(); it != table.end(); it++)
	{
		if (it->second == maxFrequency) result.push_back(it->first);
	}

	return result;

}