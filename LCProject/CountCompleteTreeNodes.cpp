/******************************************************************************
* Question: #222 Count Complete Tree Nodes
* Given a complete binary tree, count the number of nodes.
* Definition of a complete binary tree from Wikipedia:
* In a complete binary tree every level, except possibly the last, is completely filled, 
* and all nodes in the last level are as far left as possible. 
* It can have between 1 and 2^h nodes inclusive at the last level h.
*****************************************************************************/

#include "BST.h"
#include <cmath>

using namespace std;

int countNodes(TreeNode* root) 
{
	if (!root) return 0;
	int hl = 0, hr = 0;
	TreeNode *l = root, *r = root;
	while (l) { hl++; l = l->left; }
	while (r) { hr++; r = r->right; }
	if (hl == hr) return pow(2, hl) - 1;
	else return 1 + countNodes(root->left) + countNodes(root->right);
}
