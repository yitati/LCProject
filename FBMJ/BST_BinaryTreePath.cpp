/******************************************************************************
* Question: #257 Binary Tree Path
* company tag: Facebook
* Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:
["1->2->5", "1->3"]
*****************************************************************************/

#include "BST.h"
#include <vector>
#include <string>

using namespace std;

void binaryTreePaths_dfs(TreeNode * root, vector<string> & results, string result)
{
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL)
	{
		results.push_back(result);
		return;
	}
	if (root->left)binaryTreePaths_dfs(root->left, results, result + "->" + to_string(root->left->val));
	if (root->right)binaryTreePaths_dfs(root->right, results, result + "->" + to_string(root->right->val));

}

vector<string> binaryTreePaths(TreeNode* root)
{
	if (root == NULL) return{};
	vector<string> results;
	string result;
	result += to_string(root->val);
	binaryTreePaths_dfs(root, results, result);
	return results;
}


