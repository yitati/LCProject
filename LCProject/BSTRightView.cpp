/******************************************************************************/
/**
* Question: #199 Binary Tree Right Side View
* Given a binary tree, imagine yourself standing on the right side of it, return
* the valud of the nodes you can see ordered from top to bottom.
*/
/*****************************************************************************/

#include <iostream>
#include <vector>


using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

// dfs problem
class BSTRightView
{
public:
	vector<int> rightView(TreeNode * root)
	{
		vector<int> result;
		if (root == NULL) return result;

		vector<TreeNode*> parent;
		parent.push_back(root);

		while (!parent.empty())
		{
			vector<TreeNode*> child;
			for (auto& node : parent)
			{
				if (node->left) child.push_back(node->left);
				if (node->right) child.push_back(node->right);
			}
			result.push_back(parent.back()->val);
			parent = child;
		}

		return result;

	}
};
