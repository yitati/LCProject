/******************************************************************************/
/*
* Question: #95 Unique Binary Search Tree II
* Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/*****************************************************************************/

#include "BST.h"
#include <vector>

using namespace std;


vector<TreeNode *> generateTrees_recursion(int start, int end)
{
	vector<TreeNode *> results;
	if (start > end)
	{
		results.push_back(NULL);
		return results;
	}

	for (int i = start; i <= end; i++)
	{
		vector<TreeNode *> leftTrees = generateTrees_recursion(start, i - 1);
		vector<TreeNode *> rightTrees = generateTrees_recursion(i + 1, end);
		for (TreeNode * leftTree : leftTrees)
		{
			for (TreeNode * rightTree : rightTrees)
			{
				TreeNode * newRoot = new TreeNode(i);
				newRoot->left = leftTree;
				newRoot->right = rightTree;
				results.push_back(newRoot);
			}
		}
	}

	return results;
}

vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode *> results;
	if (n == 0) return results;
	return generateTrees_recursion(1, n);
}
