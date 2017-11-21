/*
 * LowestCommonAncestor.cpp
 * company tag: Facebook
1. Given two nodes in a binary tree, find their lowest common ancestor
(the given two nodes are not guaranteed to be in the binary tree).

2. What if we need to look for LCA in a kinary-tree.
 */

#include <vector>
#include "../Leetcode/BST.h"

using namespace std;


/*
 * solution for 1
 */
// check LCA
TreeNode* getLca(TreeNode* root, TreeNode* one, TreeNode* two)
{
	if(root == NULL || root == one || root == two) return root;
	TreeNode* leftLca = getLca(root->left, one, two);
	TreeNode* rightLca = getLca(root->right, one, two);
	if(leftLca && rightLca) return root;
	return leftLca ? leftLca : rightLca;
}

// check existence
bool exist(TreeNode* root, TreeNode* node)
{
	if(!root) return false;
	if(root == node) return true;
	if(exist(root->left, node)) return true;
	return exist(root->right, node);
}

TreeNode* LCAOfTwoNodes(TreeNode* root, TreeNode* one, TreeNode* two)
{
	TreeNode* lca = getLca(root, one, two);
	// if lca is a node that is not one or two, it must be the lca of those two nodes
	if(lca != one && lca != two) return lca;
	else if(lca == one)
	{
		if(exist(one, two)) return one;
	}
	else if(lca == two)
	{
		if(exist(two, one)) return two;
	}
	return NULL;
}

/*
 * solution for 2, tree node has more than one children
 */

struct KnaryTreeNode
{
	int val;
	vector<KnaryTreeNode*> children;
};

KnaryTreeNode* getKnaryLca(KnaryTreeNode* root, KnaryTreeNode* p, KnaryTreeNode * q)
{
	int count = 0;
	if(root == NULL || root == p || root == q) return root;

}
