/*************************************************************************************************
 * Question #366. Find Leaves of Binary Tree
 * Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves,
 * repeat until the tree is empty.
Example:
Given binary tree

          1
         / \
        2   3
       / \
      4   5

Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:
          1
         /
        2
2. Now removing the leaf [2] would result in this tree:
          1
3. Now removing the leaf [1] would result in the empty tree:
          []
Returns [4, 5, 3], [2], [1].

 *************************************************************************************************/

#include "BST.h"
#include <vector>
#include <unordered_map>

using namespace std;

int findLevel(TreeNode* root, vector<vector<int>>& leaves)
{
	if(!root) return 0;
	int leftLevel = findLevel(root->left, leaves);
	int rightLevel = findLevel(root->right, leaves);
	int rootLevel = max(leftLevel, rightLevel);
	if(rootLevel >= leaves.size())
	{
		vector<int> layer;
		leaves.push_back(layer);
	}
	leaves[rootLevel].push_back(root->val);
	return rootLevel + 1;
}

vector<vector<int>> findLeaves(TreeNode* root)
{
	vector<vector<int>> leaves;
	if(!root) return leaves;
	int h = findLevel(root, leaves);
	return leaves;
}





