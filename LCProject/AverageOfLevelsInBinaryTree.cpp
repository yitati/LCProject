/******************************************************************************
* Question: #637 Average of Levels in Binary Tree
* company tag: Facebook
* Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

* Note:
* The range of node's value is in the range of 32-bit signed integer.

*****************************************************************************/

#include <../LCProject/BST.h>
#include <vector>

using namespace std;

vector<double> averageOfLevels(TreeNode* root)
{
	vector<double> result;
	if(!root) return result;

	queue<TreeNode*> level;
	level.push(root);

	while(!level.empty())
	{
		int levelSize = level.size();
		double sum = 0;
		for(int i=0; i<levelSize; i++)
		{
			TreeNode* curr = level.front();
			level.pop();
			sum += (double) curr->val;
			if(curr->left) level.push(curr->left);
			if(curr->right) level.push(curr->right);
		}
		result.push_back(sum/levelSize);
	}

	return result;
}

